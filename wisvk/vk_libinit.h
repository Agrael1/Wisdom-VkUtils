#pragma once

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
inline void* InitializeVulkanLibrary()noexcept
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



struct LibToken
{
    LibToken()noexcept
        : m_library(InitializeVulkanLibrary())
    {}

    ~LibToken()noexcept
    {
        UninitializeVulkanLibrary(m_library);
    }

public:
    bool is_valid()const noexcept
    {
        return m_library != nullptr;
    }
    operator bool()const noexcept
    {
        return is_valid();
    }

public:
    void* m_library = nullptr;
};
} // namespace wis
