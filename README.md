# Wisdom utility header generator for Vulkan

Serves as a header generator for the Vulkan API. It is based on the vk.xml file from the KhronosGroup/Vulkan-Headers repository.
Contains only parts of the API that are actually improving the development experience. All headers are usable without any additional dependencies, besides Vulkan headers.


# Contents

## A header only vulkan loader implementation with separate loading tables (vk_loader.hpp)
- Supports loading of Vulkan functions from a dynamic library
- Does not require linking to the Vulkan library
- Does not pollute the global namespace with Vulkan functions
- Functions are loaded on demand
- Supports feature switching with `#undef` macros
- Loads functions depending on header version replacing new commands with extension ones if necessary

## Managed handle implementation (vk_managed_handles.hpp) 
- Provides a shared_ptr like handle implementation for Vulkan handles with parent-child relationships
- Handles keep track of their parent handles ensuring that the parent handle is not destroyed before the child handle
- Managed handles are unique_ptr like objects that can be moved, but not copied
- Managed handles still require shared_handle to parent handle to be kept alive

## Handle traits (vk_handle_traits.hpp)
- Provides a traits class for Vulkan handles
- Include creation parent, destruction function, and destruction parent, as well as pool handle type for pool handles

## Library loader stub (vk_libinit.hpp)
- Provides a stub for loading the Vulkan library
- Can be used to implement custom library loading

# Intended use

The generator is used to generate up-to-date headers for Wisdom project. However, it can be used for other projects as well. 
The generated output is specifically constrained to the needs of Wisdom project, but it can be easily modified.

# Usage

Use FetchContent to add the repository to your project. If you intend only to use headers, you can use the following snippet:

```cmake
FetchContent_Declare(
	wisvk
	GIT_REPOSITORY https://github.com/Agrael1/Wisdom-VkUtils.git
	GIT_TAG        master
	)

	set(WISVK_ONLY_HEADERS ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(wisvk)
```
This will make a target called wisvk available. You can then use it in your target_link_libraries command. Configuration should take no time at all.
