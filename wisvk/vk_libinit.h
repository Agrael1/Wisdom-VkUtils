#pragma once
#include <string_view>

#ifdef _WIN32
typedef const char* LPCSTR;
typedef struct HINSTANCE__* HINSTANCE;
typedef HINSTANCE HMODULE;
#if defined(_MINWINDEF_)
/* minwindef.h defines FARPROC, and attempting to redefine it may conflict with -Wstrict-prototypes */
#elif defined(_WIN64)
typedef __int64(__stdcall* FARPROC)(void);
#else
typedef int(__stdcall* FARPROC)(void);
#endif
#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllimport) HMODULE __stdcall LoadLibraryA(LPCSTR);
__declspec(dllimport) FARPROC __stdcall GetProcAddress(HMODULE, LPCSTR);
__declspec(dllimport) int __stdcall FreeLibraryA(HMODULE);
#ifdef __cplusplus
}
#endif

#else
#include <dlfcn.h>
#endif

namespace wis {
inline void* InitializeVulkanLibrary() noexcept
{
#if defined(_WIN32)
    return LoadLibraryA("vulkan-1.dll");
#elif defined(__APPLE__)
    void* library = dlopen("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!library)
        library = dlopen("libvulkan.1.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!library)
        library = dlopen("libMoltenVK.dylib", RTLD_NOW | RTLD_LOCAL);
    return library;
#else
    void* library = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
    if (!library)
        library = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
    return library;
#endif
    return nullptr;
}

inline void UninitializeVulkanLibrary(void* library) noexcept
{
#if defined(_WIN32)
    FreeLibraryA((HMODULE)library);
#else
    dlclose(library);
#endif
}

template<typename T>
struct TypeName {
    constexpr static const char* fullname_internal()
    {
#if defined(__clang__) || defined(__GNUC__)
        return __PRETTY_FUNCTION__;
#elif defined(_MSC_VER)
        return __FUNCSIG__;
#else
#error "Unsupported compiler"
#endif
    }

public:
    constexpr static std::string_view name()
    {
        constexpr auto xvoid = std::string_view(TypeName<void>::fullname_internal());
        constexpr auto postfix = xvoid.length() - xvoid.rfind(">::");

        auto line = std::string_view(fullname_internal());
        line.remove_suffix(postfix);
        line = line.substr(line.find("TypeName<") + 9);
        if (line.ends_with(' ')) // trailing space MSVC
            line.remove_suffix(1);
        return line;
    }

    using type = T;
    constexpr static std::string_view value = name();
};

struct LibToken {
    LibToken() noexcept
        : m_library(InitializeVulkanLibrary())
    {
    }

    ~LibToken() noexcept
    {
        UninitializeVulkanLibrary(m_library);
    }

public:
    bool is_valid() const noexcept
    {
        return m_library != nullptr;
    }
    operator bool() const noexcept
    {
        return is_valid();
    }

    template<typename PFN>
    PFN GetProcAddress() const noexcept
    {
        constexpr auto fn_name = TypeName<std::remove_pointer<PFN>>::value.substr(4);
#if defined(__unix__) || defined(__APPLE__) || defined(__QNXNTO__) || defined(__Fuchsia__)
        return (PFN)dlsym(m_library, fn_name.data());
#elif defined(_WIN32)
        return (PFN)::GetProcAddress((HMODULE)m_library, fn_name.data());
#else
#error unsupported platform
#endif
    }

public:
    void* m_library = nullptr;
};
} // namespace wis
