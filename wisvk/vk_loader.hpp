#pragma once
#include <vulkan/vulkan.h>
#include "vk_libinit.h"

namespace wis {

struct VkGlobalTable{
void Init(LibToken token) noexcept{
#if defined(VK_VERSION_1_0) 
	vkGetInstanceProcAddr = token.GetProcAddress<decltype(vkGetInstanceProcAddr)>();
	vkGetDeviceProcAddr = token.GetProcAddress<decltype(vkGetDeviceProcAddr)>();
	vkEnumerateInstanceLayerProperties = token.GetProcAddress<decltype(vkEnumerateInstanceLayerProperties)>();
	vkEnumerateInstanceExtensionProperties = token.GetProcAddress<decltype(vkEnumerateInstanceExtensionProperties)>();
	vkCreateInstance = token.GetProcAddress<decltype(vkCreateInstance)>();
#endif
#if defined(VK_VERSION_1_1) 
	vkEnumerateInstanceVersion = token.GetProcAddress<decltype(vkEnumerateInstanceVersion)>();
#endif
}
public:
#if defined(VK_VERSION_1_0) 
operator PFN_vkGetInstanceProcAddr()const noexcept { return vkGetInstanceProcAddr;};
operator PFN_vkGetDeviceProcAddr()const noexcept { return vkGetDeviceProcAddr;};
operator PFN_vkEnumerateInstanceLayerProperties()const noexcept { return vkEnumerateInstanceLayerProperties;};
operator PFN_vkEnumerateInstanceExtensionProperties()const noexcept { return vkEnumerateInstanceExtensionProperties;};
operator PFN_vkCreateInstance()const noexcept { return vkCreateInstance;};
#endif
#if defined(VK_VERSION_1_1) 
operator PFN_vkEnumerateInstanceVersion()const noexcept { return vkEnumerateInstanceVersion;};
#endif

public:
#if defined(VK_VERSION_1_0) 
PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
PFN_vkCreateInstance vkCreateInstance;
#endif
#if defined(VK_VERSION_1_1) 
PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
#endif
};

struct VkInstanceTable{
void Init(VkInstance instance, VkGlobalTable global_table) noexcept{
#if defined(VK_EXT_directfb_surface) 
	vkCreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateDirectFBSurfaceEXT");
	vkGetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif
#if defined(VK_VERSION_1_0) 
	vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties");
	vkDestroyInstance = (PFN_vkDestroyInstance)global_table.vkGetInstanceProcAddr(instance, "vkDestroyInstance");
	vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties");
	vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)global_table.vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDevices");
	vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)global_table.vkGetInstanceProcAddr(instance, "vkEnumerateDeviceLayerProperties");
	vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures");
	vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties");
	vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties");
	vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties");
	vkCreateDevice = (PFN_vkCreateDevice)global_table.vkGetInstanceProcAddr(instance, "vkCreateDevice");
	vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)global_table.vkGetInstanceProcAddr(instance, "vkEnumerateDeviceExtensionProperties");
	vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties");
#endif
#if defined(VK_EXT_calibrated_timestamps) 
	vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
#endif
#if defined(VK_EXT_tooling_info) 
	vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceToolPropertiesEXT");
#endif
#if defined(VK_KHR_xcb_surface) 
	vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
	vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateXcbSurfaceKHR");
#endif
#if defined(VK_EXT_acquire_xlib_display) 
	vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkAcquireXlibDisplayEXT");
	vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetRandROutputDisplayEXT");
#endif
#if defined(VK_EXT_debug_utils) 
	vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)global_table.vkGetInstanceProcAddr(instance, "vkSubmitDebugUtilsMessageEXT");
	vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
	vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)global_table.vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
#endif
#if defined(VK_KHR_get_physical_device_properties2) 
	vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
	vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties2KHR");
	vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties2KHR");
	vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures2KHR");
	vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2KHR");
	vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties2KHR");
	vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
#endif
#if defined(VK_KHR_cooperative_matrix) 
	vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
#endif
#if defined(VK_KHR_get_surface_capabilities2) 
	vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
	vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceFormats2KHR");
#endif
#if defined(VK_KHR_win32_surface) 
	vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateWin32SurfaceKHR");
	vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif
#if defined(VK_KHR_display) 
	vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayPropertiesKHR");
	vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
	vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetDisplayPlaneSupportedDisplaysKHR");
	vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetDisplayModePropertiesKHR");
	vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateDisplayModeKHR");
	vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetDisplayPlaneCapabilitiesKHR");
	vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateDisplayPlaneSurfaceKHR");
#endif
#if defined(VK_NV_cooperative_matrix) 
	vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif
#if defined(VK_VERSION_1_1) 
	vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)global_table.vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceGroups");
	vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties2");
	vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures2");
	vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2");
	vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties2");
	vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties2");
	vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties2");
	vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2");
	vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalBufferProperties");
	vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalSemaphoreProperties");
	vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalFenceProperties");
#endif
#if defined(VK_EXT_debug_report) 
	vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)global_table.vkGetInstanceProcAddr(instance, "vkDebugReportMessageEXT");
	vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)global_table.vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
	vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
#endif
#if defined(VK_MVK_macos_surface) 
	vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)global_table.vkGetInstanceProcAddr(instance, "vkCreateMacOSSurfaceMVK");
#endif
#if defined(VK_EXT_metal_surface) 
	vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateMetalSurfaceEXT");
#endif
#if defined(VK_EXT_sample_locations) 
	vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif
#if defined(VK_KHR_surface) 
	vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR");
	vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkDestroySurfaceKHR");
	vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
	vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceSupportKHR");
	vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR");
#endif
#if defined(VK_EXT_display_surface_counter) 
	vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif
#if defined(VK_KHR_xlib_surface) 
	vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateXlibSurfaceKHR");
	vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif
#if defined(VK_KHR_wayland_surface) 
	vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateWaylandSurfaceKHR");
	vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif
#if defined(VK_VERSION_1_3) 
	vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceToolProperties");
#endif
#if defined(VK_NN_vi_surface) 
	vkCreateViSurfaceNN = (PFN_vkCreateViSurfaceNN)global_table.vkGetInstanceProcAddr(instance, "vkCreateViSurfaceNN");
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2) 
	vkGetPhysicalDeviceSciSyncAttributesNV = (PFN_vkGetPhysicalDeviceSciSyncAttributesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSciSyncAttributesNV");
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group) 
	vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif
#if defined(VK_EXT_full_screen_exclusive) 
	vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
#endif
#if defined(VK_GGP_stream_descriptor_surface) 
	vkCreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP)global_table.vkGetInstanceProcAddr(instance, "vkCreateStreamDescriptorSurfaceGGP");
#endif
#if defined(VK_KHR_external_semaphore_capabilities) 
	vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
#endif
#if defined(VK_KHR_get_display_properties2) 
	vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
	vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayProperties2KHR");
	vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetDisplayModeProperties2KHR");
	vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR)global_table.vkGetInstanceProcAddr(instance, "vkGetDisplayPlaneCapabilities2KHR");
#endif
#if defined(VK_KHR_android_surface) 
	vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateAndroidSurfaceKHR");
#endif
#if defined(VK_KHR_performance_query) 
	vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR)global_table.vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
	vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
#endif
#if defined(VK_KHR_object_refresh) 
	vkGetPhysicalDeviceRefreshableObjectTypesKHR = (PFN_vkGetPhysicalDeviceRefreshableObjectTypesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceRefreshableObjectTypesKHR");
#endif
#if defined(VK_KHR_video_queue) 
	vkGetPhysicalDeviceVideoCapabilitiesKHR = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
	vkGetPhysicalDeviceVideoFormatPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
#endif
#if defined(VK_FUCHSIA_imagepipe_surface) 
	vkCreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA)global_table.vkGetInstanceProcAddr(instance, "vkCreateImagePipeSurfaceFUCHSIA");
#endif
#if defined(VK_NV_external_memory_capabilities) 
	vkGetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#endif
#if defined(VK_NV_optical_flow) 
	vkGetPhysicalDeviceOpticalFlowImageFormatsNV = (PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
#endif
#if defined(VK_KHR_device_group_creation) 
	vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)global_table.vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceGroupsKHR");
#endif
#if defined(VK_KHR_external_memory_capabilities) 
	vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
#endif
#if defined(VK_EXT_direct_mode_display) 
	vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkReleaseDisplayEXT");
#endif
#if defined(VK_KHR_external_fence_capabilities) 
	vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
#endif
#if defined(VK_MVK_ios_surface) 
	vkCreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)global_table.vkGetInstanceProcAddr(instance, "vkCreateIOSSurfaceMVK");
#endif
#if defined(VK_QNX_screen_surface) 
	vkCreateScreenSurfaceQNX = (PFN_vkCreateScreenSurfaceQNX)global_table.vkGetInstanceProcAddr(instance, "vkCreateScreenSurfaceQNX");
	vkGetPhysicalDeviceScreenPresentationSupportQNX = (PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
#endif
#if defined(VK_KHR_fragment_shading_rate) 
	vkGetPhysicalDeviceFragmentShadingRatesKHR = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
#endif
#if defined(VK_NV_coverage_reduction_mode) 
	vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif
#if defined(VK_EXT_headless_surface) 
	vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateHeadlessSurfaceEXT");
#endif
#if defined(VK_EXT_acquire_drm_display) 
	vkAcquireDrmDisplayEXT = (PFN_vkAcquireDrmDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkAcquireDrmDisplayEXT");
	vkGetDrmDisplayEXT = (PFN_vkGetDrmDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetDrmDisplayEXT");
#endif
#if defined(VK_KHR_video_encode_queue) 
	vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
#endif
#if defined(VK_NV_acquire_winrt_display) 
	vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)global_table.vkGetInstanceProcAddr(instance, "vkAcquireWinrtDisplayNV");
	vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV)global_table.vkGetInstanceProcAddr(instance, "vkGetWinrtDisplayNV");
#endif
#if defined(VK_NV_external_memory_sci_buf) 
	vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV = (PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
	vkGetPhysicalDeviceSciBufAttributesNV = (PFN_vkGetPhysicalDeviceSciBufAttributesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSciBufAttributesNV");
#endif
}
public:
#if defined(VK_EXT_directfb_surface) 
operator PFN_vkCreateDirectFBSurfaceEXT()const noexcept { return vkCreateDirectFBSurfaceEXT;};
operator PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT()const noexcept { return vkGetPhysicalDeviceDirectFBPresentationSupportEXT;};
#endif
#if defined(VK_VERSION_1_0) 
operator PFN_vkGetPhysicalDeviceMemoryProperties()const noexcept { return vkGetPhysicalDeviceMemoryProperties;};
operator PFN_vkDestroyInstance()const noexcept { return vkDestroyInstance;};
operator PFN_vkGetPhysicalDeviceProperties()const noexcept { return vkGetPhysicalDeviceProperties;};
operator PFN_vkEnumeratePhysicalDevices()const noexcept { return vkEnumeratePhysicalDevices;};
operator PFN_vkEnumerateDeviceLayerProperties()const noexcept { return vkEnumerateDeviceLayerProperties;};
operator PFN_vkGetPhysicalDeviceFeatures()const noexcept { return vkGetPhysicalDeviceFeatures;};
operator PFN_vkGetPhysicalDeviceFormatProperties()const noexcept { return vkGetPhysicalDeviceFormatProperties;};
operator PFN_vkGetPhysicalDeviceImageFormatProperties()const noexcept { return vkGetPhysicalDeviceImageFormatProperties;};
operator PFN_vkGetPhysicalDeviceQueueFamilyProperties()const noexcept { return vkGetPhysicalDeviceQueueFamilyProperties;};
operator PFN_vkCreateDevice()const noexcept { return vkCreateDevice;};
operator PFN_vkEnumerateDeviceExtensionProperties()const noexcept { return vkEnumerateDeviceExtensionProperties;};
operator PFN_vkGetPhysicalDeviceSparseImageFormatProperties()const noexcept { return vkGetPhysicalDeviceSparseImageFormatProperties;};
#endif
#if defined(VK_EXT_calibrated_timestamps) 
operator PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT()const noexcept { return vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;};
#endif
#if defined(VK_EXT_tooling_info) 
operator PFN_vkGetPhysicalDeviceToolPropertiesEXT()const noexcept { return vkGetPhysicalDeviceToolPropertiesEXT;};
#endif
#if defined(VK_KHR_xcb_surface) 
operator PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR()const noexcept { return vkGetPhysicalDeviceXcbPresentationSupportKHR;};
operator PFN_vkCreateXcbSurfaceKHR()const noexcept { return vkCreateXcbSurfaceKHR;};
#endif
#if defined(VK_EXT_acquire_xlib_display) 
operator PFN_vkAcquireXlibDisplayEXT()const noexcept { return vkAcquireXlibDisplayEXT;};
operator PFN_vkGetRandROutputDisplayEXT()const noexcept { return vkGetRandROutputDisplayEXT;};
#endif
#if defined(VK_EXT_debug_utils) 
operator PFN_vkSubmitDebugUtilsMessageEXT()const noexcept { return vkSubmitDebugUtilsMessageEXT;};
operator PFN_vkCreateDebugUtilsMessengerEXT()const noexcept { return vkCreateDebugUtilsMessengerEXT;};
operator PFN_vkDestroyDebugUtilsMessengerEXT()const noexcept { return vkDestroyDebugUtilsMessengerEXT;};
#endif
#if defined(VK_KHR_get_physical_device_properties2) 
operator PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR()const noexcept { return vkGetPhysicalDeviceQueueFamilyProperties2KHR;};
operator PFN_vkGetPhysicalDeviceMemoryProperties2KHR()const noexcept { return vkGetPhysicalDeviceMemoryProperties2KHR;};
operator PFN_vkGetPhysicalDeviceFormatProperties2KHR()const noexcept { return vkGetPhysicalDeviceFormatProperties2KHR;};
operator PFN_vkGetPhysicalDeviceFeatures2KHR()const noexcept { return vkGetPhysicalDeviceFeatures2KHR;};
operator PFN_vkGetPhysicalDeviceProperties2KHR()const noexcept { return vkGetPhysicalDeviceProperties2KHR;};
operator PFN_vkGetPhysicalDeviceImageFormatProperties2KHR()const noexcept { return vkGetPhysicalDeviceImageFormatProperties2KHR;};
operator PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR()const noexcept { return vkGetPhysicalDeviceSparseImageFormatProperties2KHR;};
#endif
#if defined(VK_KHR_cooperative_matrix) 
operator PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR()const noexcept { return vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR;};
#endif
#if defined(VK_KHR_get_surface_capabilities2) 
operator PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR()const noexcept { return vkGetPhysicalDeviceSurfaceCapabilities2KHR;};
operator PFN_vkGetPhysicalDeviceSurfaceFormats2KHR()const noexcept { return vkGetPhysicalDeviceSurfaceFormats2KHR;};
#endif
#if defined(VK_KHR_win32_surface) 
operator PFN_vkCreateWin32SurfaceKHR()const noexcept { return vkCreateWin32SurfaceKHR;};
operator PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR()const noexcept { return vkGetPhysicalDeviceWin32PresentationSupportKHR;};
#endif
#if defined(VK_KHR_display) 
operator PFN_vkGetPhysicalDeviceDisplayPropertiesKHR()const noexcept { return vkGetPhysicalDeviceDisplayPropertiesKHR;};
operator PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR()const noexcept { return vkGetPhysicalDeviceDisplayPlanePropertiesKHR;};
operator PFN_vkGetDisplayPlaneSupportedDisplaysKHR()const noexcept { return vkGetDisplayPlaneSupportedDisplaysKHR;};
operator PFN_vkGetDisplayModePropertiesKHR()const noexcept { return vkGetDisplayModePropertiesKHR;};
operator PFN_vkCreateDisplayModeKHR()const noexcept { return vkCreateDisplayModeKHR;};
operator PFN_vkGetDisplayPlaneCapabilitiesKHR()const noexcept { return vkGetDisplayPlaneCapabilitiesKHR;};
operator PFN_vkCreateDisplayPlaneSurfaceKHR()const noexcept { return vkCreateDisplayPlaneSurfaceKHR;};
#endif
#if defined(VK_NV_cooperative_matrix) 
operator PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV()const noexcept { return vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;};
#endif
#if defined(VK_VERSION_1_1) 
operator PFN_vkEnumeratePhysicalDeviceGroups()const noexcept { return vkEnumeratePhysicalDeviceGroups;};
operator PFN_vkGetPhysicalDeviceQueueFamilyProperties2()const noexcept { return vkGetPhysicalDeviceQueueFamilyProperties2;};
operator PFN_vkGetPhysicalDeviceFeatures2()const noexcept { return vkGetPhysicalDeviceFeatures2;};
operator PFN_vkGetPhysicalDeviceProperties2()const noexcept { return vkGetPhysicalDeviceProperties2;};
operator PFN_vkGetPhysicalDeviceFormatProperties2()const noexcept { return vkGetPhysicalDeviceFormatProperties2;};
operator PFN_vkGetPhysicalDeviceImageFormatProperties2()const noexcept { return vkGetPhysicalDeviceImageFormatProperties2;};
operator PFN_vkGetPhysicalDeviceMemoryProperties2()const noexcept { return vkGetPhysicalDeviceMemoryProperties2;};
operator PFN_vkGetPhysicalDeviceSparseImageFormatProperties2()const noexcept { return vkGetPhysicalDeviceSparseImageFormatProperties2;};
operator PFN_vkGetPhysicalDeviceExternalBufferProperties()const noexcept { return vkGetPhysicalDeviceExternalBufferProperties;};
operator PFN_vkGetPhysicalDeviceExternalSemaphoreProperties()const noexcept { return vkGetPhysicalDeviceExternalSemaphoreProperties;};
operator PFN_vkGetPhysicalDeviceExternalFenceProperties()const noexcept { return vkGetPhysicalDeviceExternalFenceProperties;};
#endif
#if defined(VK_EXT_debug_report) 
operator PFN_vkDebugReportMessageEXT()const noexcept { return vkDebugReportMessageEXT;};
operator PFN_vkDestroyDebugReportCallbackEXT()const noexcept { return vkDestroyDebugReportCallbackEXT;};
operator PFN_vkCreateDebugReportCallbackEXT()const noexcept { return vkCreateDebugReportCallbackEXT;};
#endif
#if defined(VK_MVK_macos_surface) 
operator PFN_vkCreateMacOSSurfaceMVK()const noexcept { return vkCreateMacOSSurfaceMVK;};
#endif
#if defined(VK_EXT_metal_surface) 
operator PFN_vkCreateMetalSurfaceEXT()const noexcept { return vkCreateMetalSurfaceEXT;};
#endif
#if defined(VK_EXT_sample_locations) 
operator PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT()const noexcept { return vkGetPhysicalDeviceMultisamplePropertiesEXT;};
#endif
#if defined(VK_KHR_surface) 
operator PFN_vkGetPhysicalDeviceSurfacePresentModesKHR()const noexcept { return vkGetPhysicalDeviceSurfacePresentModesKHR;};
operator PFN_vkDestroySurfaceKHR()const noexcept { return vkDestroySurfaceKHR;};
operator PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR()const noexcept { return vkGetPhysicalDeviceSurfaceCapabilitiesKHR;};
operator PFN_vkGetPhysicalDeviceSurfaceSupportKHR()const noexcept { return vkGetPhysicalDeviceSurfaceSupportKHR;};
operator PFN_vkGetPhysicalDeviceSurfaceFormatsKHR()const noexcept { return vkGetPhysicalDeviceSurfaceFormatsKHR;};
#endif
#if defined(VK_EXT_display_surface_counter) 
operator PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT()const noexcept { return vkGetPhysicalDeviceSurfaceCapabilities2EXT;};
#endif
#if defined(VK_KHR_xlib_surface) 
operator PFN_vkCreateXlibSurfaceKHR()const noexcept { return vkCreateXlibSurfaceKHR;};
operator PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR()const noexcept { return vkGetPhysicalDeviceXlibPresentationSupportKHR;};
#endif
#if defined(VK_KHR_wayland_surface) 
operator PFN_vkCreateWaylandSurfaceKHR()const noexcept { return vkCreateWaylandSurfaceKHR;};
operator PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR()const noexcept { return vkGetPhysicalDeviceWaylandPresentationSupportKHR;};
#endif
#if defined(VK_VERSION_1_3) 
operator PFN_vkGetPhysicalDeviceToolProperties()const noexcept { return vkGetPhysicalDeviceToolProperties;};
#endif
#if defined(VK_NN_vi_surface) 
operator PFN_vkCreateViSurfaceNN()const noexcept { return vkCreateViSurfaceNN;};
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2) 
operator PFN_vkGetPhysicalDeviceSciSyncAttributesNV()const noexcept { return vkGetPhysicalDeviceSciSyncAttributesNV;};
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group) 
operator PFN_vkGetPhysicalDevicePresentRectanglesKHR()const noexcept { return vkGetPhysicalDevicePresentRectanglesKHR;};
#endif
#if defined(VK_EXT_full_screen_exclusive) 
operator PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT()const noexcept { return vkGetPhysicalDeviceSurfacePresentModes2EXT;};
#endif
#if defined(VK_GGP_stream_descriptor_surface) 
operator PFN_vkCreateStreamDescriptorSurfaceGGP()const noexcept { return vkCreateStreamDescriptorSurfaceGGP;};
#endif
#if defined(VK_KHR_external_semaphore_capabilities) 
operator PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR()const noexcept { return vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;};
#endif
#if defined(VK_KHR_get_display_properties2) 
operator PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR()const noexcept { return vkGetPhysicalDeviceDisplayPlaneProperties2KHR;};
operator PFN_vkGetPhysicalDeviceDisplayProperties2KHR()const noexcept { return vkGetPhysicalDeviceDisplayProperties2KHR;};
operator PFN_vkGetDisplayModeProperties2KHR()const noexcept { return vkGetDisplayModeProperties2KHR;};
operator PFN_vkGetDisplayPlaneCapabilities2KHR()const noexcept { return vkGetDisplayPlaneCapabilities2KHR;};
#endif
#if defined(VK_KHR_android_surface) 
operator PFN_vkCreateAndroidSurfaceKHR()const noexcept { return vkCreateAndroidSurfaceKHR;};
#endif
#if defined(VK_KHR_performance_query) 
operator PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR()const noexcept { return vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;};
operator PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR()const noexcept { return vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;};
#endif
#if defined(VK_KHR_object_refresh) 
operator PFN_vkGetPhysicalDeviceRefreshableObjectTypesKHR()const noexcept { return vkGetPhysicalDeviceRefreshableObjectTypesKHR;};
#endif
#if defined(VK_KHR_video_queue) 
operator PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR()const noexcept { return vkGetPhysicalDeviceVideoCapabilitiesKHR;};
operator PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR()const noexcept { return vkGetPhysicalDeviceVideoFormatPropertiesKHR;};
#endif
#if defined(VK_FUCHSIA_imagepipe_surface) 
operator PFN_vkCreateImagePipeSurfaceFUCHSIA()const noexcept { return vkCreateImagePipeSurfaceFUCHSIA;};
#endif
#if defined(VK_NV_external_memory_capabilities) 
operator PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV()const noexcept { return vkGetPhysicalDeviceExternalImageFormatPropertiesNV;};
#endif
#if defined(VK_NV_optical_flow) 
operator PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV()const noexcept { return vkGetPhysicalDeviceOpticalFlowImageFormatsNV;};
#endif
#if defined(VK_KHR_device_group_creation) 
operator PFN_vkEnumeratePhysicalDeviceGroupsKHR()const noexcept { return vkEnumeratePhysicalDeviceGroupsKHR;};
#endif
#if defined(VK_KHR_external_memory_capabilities) 
operator PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR()const noexcept { return vkGetPhysicalDeviceExternalBufferPropertiesKHR;};
#endif
#if defined(VK_EXT_direct_mode_display) 
operator PFN_vkReleaseDisplayEXT()const noexcept { return vkReleaseDisplayEXT;};
#endif
#if defined(VK_KHR_external_fence_capabilities) 
operator PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR()const noexcept { return vkGetPhysicalDeviceExternalFencePropertiesKHR;};
#endif
#if defined(VK_MVK_ios_surface) 
operator PFN_vkCreateIOSSurfaceMVK()const noexcept { return vkCreateIOSSurfaceMVK;};
#endif
#if defined(VK_QNX_screen_surface) 
operator PFN_vkCreateScreenSurfaceQNX()const noexcept { return vkCreateScreenSurfaceQNX;};
operator PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX()const noexcept { return vkGetPhysicalDeviceScreenPresentationSupportQNX;};
#endif
#if defined(VK_KHR_fragment_shading_rate) 
operator PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR()const noexcept { return vkGetPhysicalDeviceFragmentShadingRatesKHR;};
#endif
#if defined(VK_NV_coverage_reduction_mode) 
operator PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV()const noexcept { return vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;};
#endif
#if defined(VK_EXT_headless_surface) 
operator PFN_vkCreateHeadlessSurfaceEXT()const noexcept { return vkCreateHeadlessSurfaceEXT;};
#endif
#if defined(VK_EXT_acquire_drm_display) 
operator PFN_vkAcquireDrmDisplayEXT()const noexcept { return vkAcquireDrmDisplayEXT;};
operator PFN_vkGetDrmDisplayEXT()const noexcept { return vkGetDrmDisplayEXT;};
#endif
#if defined(VK_KHR_video_encode_queue) 
operator PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR()const noexcept { return vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR;};
#endif
#if defined(VK_NV_acquire_winrt_display) 
operator PFN_vkAcquireWinrtDisplayNV()const noexcept { return vkAcquireWinrtDisplayNV;};
operator PFN_vkGetWinrtDisplayNV()const noexcept { return vkGetWinrtDisplayNV;};
#endif
#if defined(VK_NV_external_memory_sci_buf) 
operator PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV()const noexcept { return vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV;};
operator PFN_vkGetPhysicalDeviceSciBufAttributesNV()const noexcept { return vkGetPhysicalDeviceSciBufAttributesNV;};
#endif

public:
#if defined(VK_EXT_directfb_surface) 
PFN_vkCreateDirectFBSurfaceEXT vkCreateDirectFBSurfaceEXT;
PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
#endif
#if defined(VK_VERSION_1_0) 
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
PFN_vkDestroyInstance vkDestroyInstance;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkCreateDevice vkCreateDevice;
PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
#endif
#if defined(VK_EXT_calibrated_timestamps) 
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#endif
#if defined(VK_EXT_tooling_info) 
PFN_vkGetPhysicalDeviceToolPropertiesEXT vkGetPhysicalDeviceToolPropertiesEXT;
#endif
#if defined(VK_KHR_xcb_surface) 
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
#endif
#if defined(VK_EXT_acquire_xlib_display) 
PFN_vkAcquireXlibDisplayEXT vkAcquireXlibDisplayEXT;
PFN_vkGetRandROutputDisplayEXT vkGetRandROutputDisplayEXT;
#endif
#if defined(VK_EXT_debug_utils) 
PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;
PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
#endif
#if defined(VK_KHR_get_physical_device_properties2) 
PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
#endif
#if defined(VK_KHR_cooperative_matrix) 
PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR;
#endif
#if defined(VK_KHR_get_surface_capabilities2) 
PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR;
PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vkGetPhysicalDeviceSurfaceFormats2KHR;
#endif
#if defined(VK_KHR_win32_surface) 
PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif
#if defined(VK_KHR_display) 
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
#endif
#if defined(VK_NV_cooperative_matrix) 
PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
#endif
#if defined(VK_VERSION_1_1) 
PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
#endif
#if defined(VK_EXT_debug_report) 
PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
#endif
#if defined(VK_MVK_macos_surface) 
PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK;
#endif
#if defined(VK_EXT_metal_surface) 
PFN_vkCreateMetalSurfaceEXT vkCreateMetalSurfaceEXT;
#endif
#if defined(VK_EXT_sample_locations) 
PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT;
#endif
#if defined(VK_KHR_surface) 
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
#endif
#if defined(VK_EXT_display_surface_counter) 
PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;
#endif
#if defined(VK_KHR_xlib_surface) 
PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif
#if defined(VK_KHR_wayland_surface) 
PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif
#if defined(VK_VERSION_1_3) 
PFN_vkGetPhysicalDeviceToolProperties vkGetPhysicalDeviceToolProperties;
#endif
#if defined(VK_NN_vi_surface) 
PFN_vkCreateViSurfaceNN vkCreateViSurfaceNN;
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2) 
PFN_vkGetPhysicalDeviceSciSyncAttributesNV vkGetPhysicalDeviceSciSyncAttributesNV;
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group) 
PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;
#endif
#if defined(VK_EXT_full_screen_exclusive) 
PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT;
#endif
#if defined(VK_GGP_stream_descriptor_surface) 
PFN_vkCreateStreamDescriptorSurfaceGGP vkCreateStreamDescriptorSurfaceGGP;
#endif
#if defined(VK_KHR_external_semaphore_capabilities) 
PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
#endif
#if defined(VK_KHR_get_display_properties2) 
PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
PFN_vkGetPhysicalDeviceDisplayProperties2KHR vkGetPhysicalDeviceDisplayProperties2KHR;
PFN_vkGetDisplayModeProperties2KHR vkGetDisplayModeProperties2KHR;
PFN_vkGetDisplayPlaneCapabilities2KHR vkGetDisplayPlaneCapabilities2KHR;
#endif
#if defined(VK_KHR_android_surface) 
PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
#endif
#if defined(VK_KHR_performance_query) 
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
#endif
#if defined(VK_KHR_object_refresh) 
PFN_vkGetPhysicalDeviceRefreshableObjectTypesKHR vkGetPhysicalDeviceRefreshableObjectTypesKHR;
#endif
#if defined(VK_KHR_video_queue) 
PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR vkGetPhysicalDeviceVideoCapabilitiesKHR;
PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR vkGetPhysicalDeviceVideoFormatPropertiesKHR;
#endif
#if defined(VK_FUCHSIA_imagepipe_surface) 
PFN_vkCreateImagePipeSurfaceFUCHSIA vkCreateImagePipeSurfaceFUCHSIA;
#endif
#if defined(VK_NV_external_memory_capabilities) 
PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
#endif
#if defined(VK_NV_optical_flow) 
PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV vkGetPhysicalDeviceOpticalFlowImageFormatsNV;
#endif
#if defined(VK_KHR_device_group_creation) 
PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR;
#endif
#if defined(VK_KHR_external_memory_capabilities) 
PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR;
#endif
#if defined(VK_EXT_direct_mode_display) 
PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;
#endif
#if defined(VK_KHR_external_fence_capabilities) 
PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR;
#endif
#if defined(VK_MVK_ios_surface) 
PFN_vkCreateIOSSurfaceMVK vkCreateIOSSurfaceMVK;
#endif
#if defined(VK_QNX_screen_surface) 
PFN_vkCreateScreenSurfaceQNX vkCreateScreenSurfaceQNX;
PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX vkGetPhysicalDeviceScreenPresentationSupportQNX;
#endif
#if defined(VK_KHR_fragment_shading_rate) 
PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR vkGetPhysicalDeviceFragmentShadingRatesKHR;
#endif
#if defined(VK_NV_coverage_reduction_mode) 
PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
#endif
#if defined(VK_EXT_headless_surface) 
PFN_vkCreateHeadlessSurfaceEXT vkCreateHeadlessSurfaceEXT;
#endif
#if defined(VK_EXT_acquire_drm_display) 
PFN_vkAcquireDrmDisplayEXT vkAcquireDrmDisplayEXT;
PFN_vkGetDrmDisplayEXT vkGetDrmDisplayEXT;
#endif
#if defined(VK_KHR_video_encode_queue) 
PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR;
#endif
#if defined(VK_NV_acquire_winrt_display) 
PFN_vkAcquireWinrtDisplayNV vkAcquireWinrtDisplayNV;
PFN_vkGetWinrtDisplayNV vkGetWinrtDisplayNV;
#endif
#if defined(VK_NV_external_memory_sci_buf) 
PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV;
PFN_vkGetPhysicalDeviceSciBufAttributesNV vkGetPhysicalDeviceSciBufAttributesNV;
#endif
};

struct VkDeviceTable{
void Init(VkDevice device, VkGlobalTable global_table) noexcept{
#if defined(VK_VERSION_1_0) 
	vkDestroyDevice = (PFN_vkDestroyDevice)global_table.vkGetDeviceProcAddr(device, "vkDestroyDevice");
	vkResetEvent = (PFN_vkResetEvent)global_table.vkGetDeviceProcAddr(device, "vkResetEvent");
	vkMapMemory = (PFN_vkMapMemory)global_table.vkGetDeviceProcAddr(device, "vkMapMemory");
	vkGetDeviceQueue = (PFN_vkGetDeviceQueue)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceQueue");
	vkQueueSubmit = (PFN_vkQueueSubmit)global_table.vkGetDeviceProcAddr(device, "vkQueueSubmit");
	vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceMemoryCommitment");
	vkAllocateMemory = (PFN_vkAllocateMemory)global_table.vkGetDeviceProcAddr(device, "vkAllocateMemory");
	vkDestroyPipeline = (PFN_vkDestroyPipeline)global_table.vkGetDeviceProcAddr(device, "vkDestroyPipeline");
	vkQueueWaitIdle = (PFN_vkQueueWaitIdle)global_table.vkGetDeviceProcAddr(device, "vkQueueWaitIdle");
	vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)global_table.vkGetDeviceProcAddr(device, "vkCmdDispatchIndirect");
	vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)global_table.vkGetDeviceProcAddr(device, "vkCreateDescriptorSetLayout");
	vkCreateImage = (PFN_vkCreateImage)global_table.vkGetDeviceProcAddr(device, "vkCreateImage");
	vkFreeMemory = (PFN_vkFreeMemory)global_table.vkGetDeviceProcAddr(device, "vkFreeMemory");
	vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)global_table.vkGetDeviceProcAddr(device, "vkDeviceWaitIdle");
	vkResetDescriptorPool = (PFN_vkResetDescriptorPool)global_table.vkGetDeviceProcAddr(device, "vkResetDescriptorPool");
	vkSetEvent = (PFN_vkSetEvent)global_table.vkGetDeviceProcAddr(device, "vkSetEvent");
	vkUnmapMemory = (PFN_vkUnmapMemory)global_table.vkGetDeviceProcAddr(device, "vkUnmapMemory");
	vkCreateSampler = (PFN_vkCreateSampler)global_table.vkGetDeviceProcAddr(device, "vkCreateSampler");
	vkCreateEvent = (PFN_vkCreateEvent)global_table.vkGetDeviceProcAddr(device, "vkCreateEvent");
	vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)global_table.vkGetDeviceProcAddr(device, "vkFlushMappedMemoryRanges");
	vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)global_table.vkGetDeviceProcAddr(device, "vkDestroyDescriptorSetLayout");
	vkGetFenceStatus = (PFN_vkGetFenceStatus)global_table.vkGetDeviceProcAddr(device, "vkGetFenceStatus");
	vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)global_table.vkGetDeviceProcAddr(device, "vkInvalidateMappedMemoryRanges");
	vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)global_table.vkGetDeviceProcAddr(device, "vkCmdUpdateBuffer");
	vkBindBufferMemory = (PFN_vkBindBufferMemory)global_table.vkGetDeviceProcAddr(device, "vkBindBufferMemory");
	vkBindImageMemory = (PFN_vkBindImageMemory)global_table.vkGetDeviceProcAddr(device, "vkBindImageMemory");
	vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)global_table.vkGetDeviceProcAddr(device, "vkGetBufferMemoryRequirements");
	vkDestroySampler = (PFN_vkDestroySampler)global_table.vkGetDeviceProcAddr(device, "vkDestroySampler");
	vkDestroyImageView = (PFN_vkDestroyImageView)global_table.vkGetDeviceProcAddr(device, "vkDestroyImageView");
	vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)global_table.vkGetDeviceProcAddr(device, "vkGetImageMemoryRequirements");
	vkCreateQueryPool = (PFN_vkCreateQueryPool)global_table.vkGetDeviceProcAddr(device, "vkCreateQueryPool");
	vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)global_table.vkGetDeviceProcAddr(device, "vkGetImageSparseMemoryRequirements");
	vkQueueBindSparse = (PFN_vkQueueBindSparse)global_table.vkGetDeviceProcAddr(device, "vkQueueBindSparse");
	vkCreateFence = (PFN_vkCreateFence)global_table.vkGetDeviceProcAddr(device, "vkCreateFence");
	vkCreateCommandPool = (PFN_vkCreateCommandPool)global_table.vkGetDeviceProcAddr(device, "vkCreateCommandPool");
	vkDestroyFence = (PFN_vkDestroyFence)global_table.vkGetDeviceProcAddr(device, "vkDestroyFence");
	vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)global_table.vkGetDeviceProcAddr(device, "vkGetRenderAreaGranularity");
	vkResetFences = (PFN_vkResetFences)global_table.vkGetDeviceProcAddr(device, "vkResetFences");
	vkWaitForFences = (PFN_vkWaitForFences)global_table.vkGetDeviceProcAddr(device, "vkWaitForFences");
	vkCreateSemaphore = (PFN_vkCreateSemaphore)global_table.vkGetDeviceProcAddr(device, "vkCreateSemaphore");
	vkDestroyBuffer = (PFN_vkDestroyBuffer)global_table.vkGetDeviceProcAddr(device, "vkDestroyBuffer");
	vkDestroySemaphore = (PFN_vkDestroySemaphore)global_table.vkGetDeviceProcAddr(device, "vkDestroySemaphore");
	vkGetEventStatus = (PFN_vkGetEventStatus)global_table.vkGetDeviceProcAddr(device, "vkGetEventStatus");
	vkDestroyEvent = (PFN_vkDestroyEvent)global_table.vkGetDeviceProcAddr(device, "vkDestroyEvent");
	vkDestroyQueryPool = (PFN_vkDestroyQueryPool)global_table.vkGetDeviceProcAddr(device, "vkDestroyQueryPool");
	vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)global_table.vkGetDeviceProcAddr(device, "vkGetQueryPoolResults");
	vkCreateBuffer = (PFN_vkCreateBuffer)global_table.vkGetDeviceProcAddr(device, "vkCreateBuffer");
	vkCreateBufferView = (PFN_vkCreateBufferView)global_table.vkGetDeviceProcAddr(device, "vkCreateBufferView");
	vkDestroyBufferView = (PFN_vkDestroyBufferView)global_table.vkGetDeviceProcAddr(device, "vkDestroyBufferView");
	vkDestroyImage = (PFN_vkDestroyImage)global_table.vkGetDeviceProcAddr(device, "vkDestroyImage");
	vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)global_table.vkGetDeviceProcAddr(device, "vkGetImageSubresourceLayout");
	vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)global_table.vkGetDeviceProcAddr(device, "vkCreatePipelineLayout");
	vkCmdNextSubpass = (PFN_vkCmdNextSubpass)global_table.vkGetDeviceProcAddr(device, "vkCmdNextSubpass");
	vkCreateImageView = (PFN_vkCreateImageView)global_table.vkGetDeviceProcAddr(device, "vkCreateImageView");
	vkCreateShaderModule = (PFN_vkCreateShaderModule)global_table.vkGetDeviceProcAddr(device, "vkCreateShaderModule");
	vkDestroyShaderModule = (PFN_vkDestroyShaderModule)global_table.vkGetDeviceProcAddr(device, "vkDestroyShaderModule");
	vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)global_table.vkGetDeviceProcAddr(device, "vkCmdBindIndexBuffer");
	vkCmdFillBuffer = (PFN_vkCmdFillBuffer)global_table.vkGetDeviceProcAddr(device, "vkCmdFillBuffer");
	vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)global_table.vkGetDeviceProcAddr(device, "vkGetPipelineCacheData");
	vkCreatePipelineCache = (PFN_vkCreatePipelineCache)global_table.vkGetDeviceProcAddr(device, "vkCreatePipelineCache");
	vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)global_table.vkGetDeviceProcAddr(device, "vkDestroyPipelineCache");
	vkMergePipelineCaches = (PFN_vkMergePipelineCaches)global_table.vkGetDeviceProcAddr(device, "vkMergePipelineCaches");
	vkCreateComputePipelines = (PFN_vkCreateComputePipelines)global_table.vkGetDeviceProcAddr(device, "vkCreateComputePipelines");
	vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)global_table.vkGetDeviceProcAddr(device, "vkCreateGraphicsPipelines");
	vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)global_table.vkGetDeviceProcAddr(device, "vkDestroyPipelineLayout");
	vkCmdCopyImage = (PFN_vkCmdCopyImage)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyImage");
	vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)global_table.vkGetDeviceProcAddr(device, "vkCreateDescriptorPool");
	vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)global_table.vkGetDeviceProcAddr(device, "vkDestroyDescriptorPool");
	vkCreateFramebuffer = (PFN_vkCreateFramebuffer)global_table.vkGetDeviceProcAddr(device, "vkCreateFramebuffer");
	vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)global_table.vkGetDeviceProcAddr(device, "vkAllocateDescriptorSets");
	vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)global_table.vkGetDeviceProcAddr(device, "vkFreeDescriptorSets");
	vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)global_table.vkGetDeviceProcAddr(device, "vkCmdSetLineWidth");
	vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)global_table.vkGetDeviceProcAddr(device, "vkUpdateDescriptorSets");
	vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)global_table.vkGetDeviceProcAddr(device, "vkDestroyFramebuffer");
	vkCreateRenderPass = (PFN_vkCreateRenderPass)global_table.vkGetDeviceProcAddr(device, "vkCreateRenderPass");
	vkDestroyRenderPass = (PFN_vkDestroyRenderPass)global_table.vkGetDeviceProcAddr(device, "vkDestroyRenderPass");
	vkDestroyCommandPool = (PFN_vkDestroyCommandPool)global_table.vkGetDeviceProcAddr(device, "vkDestroyCommandPool");
	vkResetCommandPool = (PFN_vkResetCommandPool)global_table.vkGetDeviceProcAddr(device, "vkResetCommandPool");
	vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)global_table.vkGetDeviceProcAddr(device, "vkAllocateCommandBuffers");
	vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)global_table.vkGetDeviceProcAddr(device, "vkFreeCommandBuffers");
	vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)global_table.vkGetDeviceProcAddr(device, "vkBeginCommandBuffer");
	vkEndCommandBuffer = (PFN_vkEndCommandBuffer)global_table.vkGetDeviceProcAddr(device, "vkEndCommandBuffer");
	vkResetCommandBuffer = (PFN_vkResetCommandBuffer)global_table.vkGetDeviceProcAddr(device, "vkResetCommandBuffer");
	vkCmdBindPipeline = (PFN_vkCmdBindPipeline)global_table.vkGetDeviceProcAddr(device, "vkCmdBindPipeline");
	vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)global_table.vkGetDeviceProcAddr(device, "vkCmdPipelineBarrier");
	vkCmdSetViewport = (PFN_vkCmdSetViewport)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewport");
	vkCmdSetScissor = (PFN_vkCmdSetScissor)global_table.vkGetDeviceProcAddr(device, "vkCmdSetScissor");
	vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBias");
	vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)global_table.vkGetDeviceProcAddr(device, "vkCmdSetBlendConstants");
	vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)global_table.vkGetDeviceProcAddr(device, "vkCmdBindVertexBuffers");
	vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBounds");
	vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)global_table.vkGetDeviceProcAddr(device, "vkCmdSetStencilCompareMask");
	vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)global_table.vkGetDeviceProcAddr(device, "vkCmdSetStencilWriteMask");
	vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)global_table.vkGetDeviceProcAddr(device, "vkCmdSetStencilReference");
	vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)global_table.vkGetDeviceProcAddr(device, "vkCmdBindDescriptorSets");
	vkCmdDraw = (PFN_vkCmdDraw)global_table.vkGetDeviceProcAddr(device, "vkCmdDraw");
	vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndexed");
	vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndirect");
	vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirect");
	vkCmdDispatch = (PFN_vkCmdDispatch)global_table.vkGetDeviceProcAddr(device, "vkCmdDispatch");
	vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyBuffer");
	vkCmdBlitImage = (PFN_vkCmdBlitImage)global_table.vkGetDeviceProcAddr(device, "vkCmdBlitImage");
	vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyBufferToImage");
	vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyImageToBuffer");
	vkCmdClearColorImage = (PFN_vkCmdClearColorImage)global_table.vkGetDeviceProcAddr(device, "vkCmdClearColorImage");
	vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)global_table.vkGetDeviceProcAddr(device, "vkCmdClearDepthStencilImage");
	vkCmdClearAttachments = (PFN_vkCmdClearAttachments)global_table.vkGetDeviceProcAddr(device, "vkCmdClearAttachments");
	vkCmdResolveImage = (PFN_vkCmdResolveImage)global_table.vkGetDeviceProcAddr(device, "vkCmdResolveImage");
	vkCmdSetEvent = (PFN_vkCmdSetEvent)global_table.vkGetDeviceProcAddr(device, "vkCmdSetEvent");
	vkCmdResetEvent = (PFN_vkCmdResetEvent)global_table.vkGetDeviceProcAddr(device, "vkCmdResetEvent");
	vkCmdWaitEvents = (PFN_vkCmdWaitEvents)global_table.vkGetDeviceProcAddr(device, "vkCmdWaitEvents");
	vkCmdBeginQuery = (PFN_vkCmdBeginQuery)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginQuery");
	vkCmdEndQuery = (PFN_vkCmdEndQuery)global_table.vkGetDeviceProcAddr(device, "vkCmdEndQuery");
	vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)global_table.vkGetDeviceProcAddr(device, "vkCmdResetQueryPool");
	vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteTimestamp");
	vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyQueryPoolResults");
	vkCmdPushConstants = (PFN_vkCmdPushConstants)global_table.vkGetDeviceProcAddr(device, "vkCmdPushConstants");
	vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginRenderPass");
	vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)global_table.vkGetDeviceProcAddr(device, "vkCmdEndRenderPass");
	vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)global_table.vkGetDeviceProcAddr(device, "vkCmdExecuteCommands");
#endif
#if defined(VK_KHR_device_group) 
	vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDeviceMaskKHR");
	vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdDispatchBaseKHR");
	vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif
#if defined(VK_VERSION_1_1) 
	vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)global_table.vkGetDeviceProcAddr(device, "vkBindBufferMemory2");
	vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceGroupPeerMemoryFeatures");
	vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)global_table.vkGetDeviceProcAddr(device, "vkGetBufferMemoryRequirements2");
	vkBindImageMemory2 = (PFN_vkBindImageMemory2)global_table.vkGetDeviceProcAddr(device, "vkBindImageMemory2");
	vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDeviceMask");
	vkCmdDispatchBase = (PFN_vkCmdDispatchBase)global_table.vkGetDeviceProcAddr(device, "vkCmdDispatchBase");
	vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)global_table.vkGetDeviceProcAddr(device, "vkGetImageMemoryRequirements2");
	vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)global_table.vkGetDeviceProcAddr(device, "vkGetImageSparseMemoryRequirements2");
	vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutSupport");
	vkTrimCommandPool = (PFN_vkTrimCommandPool)global_table.vkGetDeviceProcAddr(device, "vkTrimCommandPool");
	vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceQueue2");
	vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)global_table.vkGetDeviceProcAddr(device, "vkCreateSamplerYcbcrConversion");
	vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)global_table.vkGetDeviceProcAddr(device, "vkDestroySamplerYcbcrConversion");
	vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)global_table.vkGetDeviceProcAddr(device, "vkCreateDescriptorUpdateTemplate");
	vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)global_table.vkGetDeviceProcAddr(device, "vkDestroyDescriptorUpdateTemplate");
	vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)global_table.vkGetDeviceProcAddr(device, "vkUpdateDescriptorSetWithTemplate");
#endif
#if defined(VK_EXT_descriptor_buffer) 
	vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = (PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT");
	vkCmdSetDescriptorBufferOffsetsEXT = (PFN_vkCmdSetDescriptorBufferOffsetsEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDescriptorBufferOffsetsEXT");
	vkGetDescriptorEXT = (PFN_vkGetDescriptorEXT)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorEXT");
	vkGetSamplerOpaqueCaptureDescriptorDataEXT = (PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetSamplerOpaqueCaptureDescriptorDataEXT");
	vkGetDescriptorSetLayoutSizeEXT = (PFN_vkGetDescriptorSetLayoutSizeEXT)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutSizeEXT");
	vkGetDescriptorSetLayoutBindingOffsetEXT = (PFN_vkGetDescriptorSetLayoutBindingOffsetEXT)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutBindingOffsetEXT");
	vkCmdBindDescriptorBuffersEXT = (PFN_vkCmdBindDescriptorBuffersEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBindDescriptorBuffersEXT");
	vkCmdBindDescriptorBufferEmbeddedSamplersEXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
	vkGetBufferOpaqueCaptureDescriptorDataEXT = (PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetBufferOpaqueCaptureDescriptorDataEXT");
	vkGetImageOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageOpaqueCaptureDescriptorDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetImageOpaqueCaptureDescriptorDataEXT");
	vkGetImageViewOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetImageViewOpaqueCaptureDescriptorDataEXT");
#endif
#if defined(VK_EXT_debug_marker) 
	vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)global_table.vkGetDeviceProcAddr(device, "vkDebugMarkerSetObjectTagEXT");
	vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDebugMarkerInsertEXT");
	vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDebugMarkerBeginEXT");
	vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)global_table.vkGetDeviceProcAddr(device, "vkDebugMarkerSetObjectNameEXT");
	vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDebugMarkerEndEXT");
#endif
#if defined(VK_AMD_buffer_marker) 
	vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteBufferMarkerAMD");
#endif
#if defined(VK_NV_optical_flow) 
	vkBindOpticalFlowSessionImageNV = (PFN_vkBindOpticalFlowSessionImageNV)global_table.vkGetDeviceProcAddr(device, "vkBindOpticalFlowSessionImageNV");
	vkCmdOpticalFlowExecuteNV = (PFN_vkCmdOpticalFlowExecuteNV)global_table.vkGetDeviceProcAddr(device, "vkCmdOpticalFlowExecuteNV");
	vkCreateOpticalFlowSessionNV = (PFN_vkCreateOpticalFlowSessionNV)global_table.vkGetDeviceProcAddr(device, "vkCreateOpticalFlowSessionNV");
	vkDestroyOpticalFlowSessionNV = (PFN_vkDestroyOpticalFlowSessionNV)global_table.vkGetDeviceProcAddr(device, "vkDestroyOpticalFlowSessionNV");
#endif
#if defined(VK_EXT_opacity_micromap) 
	vkCreateMicromapEXT = (PFN_vkCreateMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCreateMicromapEXT");
	vkCopyMemoryToMicromapEXT = (PFN_vkCopyMemoryToMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMemoryToMicromapEXT");
	vkBuildMicromapsEXT = (PFN_vkBuildMicromapsEXT)global_table.vkGetDeviceProcAddr(device, "vkBuildMicromapsEXT");
	vkCmdCopyMicromapEXT = (PFN_vkCmdCopyMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMicromapEXT");
	vkGetMicromapBuildSizesEXT = (PFN_vkGetMicromapBuildSizesEXT)global_table.vkGetDeviceProcAddr(device, "vkGetMicromapBuildSizesEXT");
	vkWriteMicromapsPropertiesEXT = (PFN_vkWriteMicromapsPropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkWriteMicromapsPropertiesEXT");
	vkCopyMicromapEXT = (PFN_vkCopyMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMicromapEXT");
	vkDestroyMicromapEXT = (PFN_vkDestroyMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkDestroyMicromapEXT");
	vkCmdBuildMicromapsEXT = (PFN_vkCmdBuildMicromapsEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBuildMicromapsEXT");
	vkCopyMicromapToMemoryEXT = (PFN_vkCopyMicromapToMemoryEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMicromapToMemoryEXT");
	vkCmdCopyMicromapToMemoryEXT = (PFN_vkCmdCopyMicromapToMemoryEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMicromapToMemoryEXT");
	vkCmdCopyMemoryToMicromapEXT = (PFN_vkCmdCopyMemoryToMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMemoryToMicromapEXT");
	vkCmdWriteMicromapsPropertiesEXT = (PFN_vkCmdWriteMicromapsPropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteMicromapsPropertiesEXT");
	vkGetDeviceMicromapCompatibilityEXT = (PFN_vkGetDeviceMicromapCompatibilityEXT)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceMicromapCompatibilityEXT");
#endif
#if defined(VK_KHR_get_memory_requirements2) 
	vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)global_table.vkGetDeviceProcAddr(device, "vkGetBufferMemoryRequirements2KHR");
	vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)global_table.vkGetDeviceProcAddr(device, "vkGetImageSparseMemoryRequirements2KHR");
	vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)global_table.vkGetDeviceProcAddr(device, "vkGetImageMemoryRequirements2KHR");
#endif
#if defined(VK_FUCHSIA_buffer_collection) 
	vkGetBufferCollectionPropertiesFUCHSIA = (PFN_vkGetBufferCollectionPropertiesFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkGetBufferCollectionPropertiesFUCHSIA");
	vkDestroyBufferCollectionFUCHSIA = (PFN_vkDestroyBufferCollectionFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkDestroyBufferCollectionFUCHSIA");
	vkCreateBufferCollectionFUCHSIA = (PFN_vkCreateBufferCollectionFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkCreateBufferCollectionFUCHSIA");
	vkSetBufferCollectionImageConstraintsFUCHSIA = (PFN_vkSetBufferCollectionImageConstraintsFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkSetBufferCollectionImageConstraintsFUCHSIA");
	vkSetBufferCollectionBufferConstraintsFUCHSIA = (PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkSetBufferCollectionBufferConstraintsFUCHSIA");
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2) 
	vkImportFenceSciSyncObjNV = (PFN_vkImportFenceSciSyncObjNV)global_table.vkGetDeviceProcAddr(device, "vkImportFenceSciSyncObjNV");
	vkGetFenceSciSyncFenceNV = (PFN_vkGetFenceSciSyncFenceNV)global_table.vkGetDeviceProcAddr(device, "vkGetFenceSciSyncFenceNV");
	vkImportFenceSciSyncFenceNV = (PFN_vkImportFenceSciSyncFenceNV)global_table.vkGetDeviceProcAddr(device, "vkImportFenceSciSyncFenceNV");
	vkGetFenceSciSyncObjNV = (PFN_vkGetFenceSciSyncObjNV)global_table.vkGetDeviceProcAddr(device, "vkGetFenceSciSyncObjNV");
#endif
#if defined(VK_KHR_map_memory2) 
	vkUnmapMemory2KHR = (PFN_vkUnmapMemory2KHR)global_table.vkGetDeviceProcAddr(device, "vkUnmapMemory2KHR");
	vkMapMemory2KHR = (PFN_vkMapMemory2KHR)global_table.vkGetDeviceProcAddr(device, "vkMapMemory2KHR");
#endif
#if defined(VK_AMD_shader_info) 
	vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)global_table.vkGetDeviceProcAddr(device, "vkGetShaderInfoAMD");
#endif
#if defined(VK_KHR_deferred_host_operations) 
	vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeferredOperationMaxConcurrencyKHR");
	vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeferredOperationResultKHR");
	vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateDeferredOperationKHR");
	vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroyDeferredOperationKHR");
	vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)global_table.vkGetDeviceProcAddr(device, "vkDeferredOperationJoinKHR");
#endif
#if defined(VK_NV_fragment_shading_rate_enums) 
	vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetFragmentShadingRateEnumNV");
#endif
#if defined(VK_NV_ray_tracing) 
	vkCompileDeferredNV = (PFN_vkCompileDeferredNV)global_table.vkGetDeviceProcAddr(device, "vkCompileDeferredNV");
	vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)global_table.vkGetDeviceProcAddr(device, "vkGetAccelerationStructureHandleNV");
	vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)global_table.vkGetDeviceProcAddr(device, "vkGetRayTracingShaderGroupHandlesNV");
	vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)global_table.vkGetDeviceProcAddr(device, "vkCmdTraceRaysNV");
	vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
	vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)global_table.vkGetDeviceProcAddr(device, "vkCreateAccelerationStructureNV");
	vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)global_table.vkGetDeviceProcAddr(device, "vkDestroyAccelerationStructureNV");
	vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)global_table.vkGetDeviceProcAddr(device, "vkGetAccelerationStructureMemoryRequirementsNV");
	vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)global_table.vkGetDeviceProcAddr(device, "vkBindAccelerationStructureMemoryNV");
	vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)global_table.vkGetDeviceProcAddr(device, "vkCmdBuildAccelerationStructureNV");
	vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyAccelerationStructureNV");
	vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)global_table.vkGetDeviceProcAddr(device, "vkCreateRayTracingPipelinesNV");
#endif
#if defined(VK_KHR_synchronization2) 
	vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdResetEvent2KHR");
	vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdWaitEvents2KHR");
	vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetEvent2KHR");
	vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteTimestamp2KHR");
	vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdPipelineBarrier2KHR");
	vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)global_table.vkGetDeviceProcAddr(device, "vkQueueSubmit2KHR");
	vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteBufferMarker2AMD");
	vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)global_table.vkGetDeviceProcAddr(device, "vkGetQueueCheckpointData2NV");
#endif
#if defined(VK_KHR_video_queue) 
	vkCreateVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateVideoSessionParametersKHR");
	vkCreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateVideoSessionKHR");
	vkBindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)global_table.vkGetDeviceProcAddr(device, "vkBindVideoSessionMemoryKHR");
	vkUpdateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR)global_table.vkGetDeviceProcAddr(device, "vkUpdateVideoSessionParametersKHR");
	vkDestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroyVideoSessionKHR");
	vkGetVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR)global_table.vkGetDeviceProcAddr(device, "vkGetVideoSessionMemoryRequirementsKHR");
	vkDestroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroyVideoSessionParametersKHR");
	vkCmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginVideoCodingKHR");
	vkCmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdEndVideoCodingKHR");
	vkCmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdControlVideoCodingKHR");
#endif
#if defined(VK_KHR_push_descriptor) || defined(VK_KHR_push_descriptor) || defined(VK_KHR_descriptor_update_template) 
	vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#if defined(VK_KHR_descriptor_update_template) 
	vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)global_table.vkGetDeviceProcAddr(device, "vkUpdateDescriptorSetWithTemplateKHR");
	vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateDescriptorUpdateTemplateKHR");
	vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroyDescriptorUpdateTemplateKHR");
#endif
#if defined(VK_KHR_push_descriptor) 
	vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSetKHR");
#endif
#if defined(VK_NVX_binary_import) 
	vkCreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX)global_table.vkGetDeviceProcAddr(device, "vkCreateCuFunctionNVX");
	vkCreateCuModuleNVX = (PFN_vkCreateCuModuleNVX)global_table.vkGetDeviceProcAddr(device, "vkCreateCuModuleNVX");
	vkDestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX)global_table.vkGetDeviceProcAddr(device, "vkDestroyCuModuleNVX");
	vkDestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX)global_table.vkGetDeviceProcAddr(device, "vkDestroyCuFunctionNVX");
	vkCmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX)global_table.vkGetDeviceProcAddr(device, "vkCmdCuLaunchKernelNVX");
#endif
#if defined(VK_NV_shading_rate_image) 
	vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewportShadingRatePaletteNV");
	vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoarseSampleOrderNV");
	vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)global_table.vkGetDeviceProcAddr(device, "vkCmdBindShadingRateImageNV");
#endif
#if defined(VK_KHR_buffer_device_address) 
	vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)global_table.vkGetDeviceProcAddr(device, "vkGetBufferDeviceAddressKHR");
	vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
	vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)global_table.vkGetDeviceProcAddr(device, "vkGetBufferOpaqueCaptureAddressKHR");
#endif
#if defined(VK_VERSION_1_3) 
	vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteTimestamp2");
	vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthCompareOp");
	vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPrimitiveTopology");
	vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceBufferMemoryRequirements");
	vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2)global_table.vkGetDeviceProcAddr(device, "vkCmdPipelineBarrier2");
	vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthWriteEnable");
	vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewportWithCount");
	vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot)global_table.vkGetDeviceProcAddr(device, "vkCreatePrivateDataSlot");
	vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot)global_table.vkGetDeviceProcAddr(device, "vkDestroyPrivateDataSlot");
	vkSetPrivateData = (PFN_vkSetPrivateData)global_table.vkGetDeviceProcAddr(device, "vkSetPrivateData");
	vkGetPrivateData = (PFN_vkGetPrivateData)global_table.vkGetDeviceProcAddr(device, "vkGetPrivateData");
	vkCmdSetEvent2 = (PFN_vkCmdSetEvent2)global_table.vkGetDeviceProcAddr(device, "vkCmdSetEvent2");
	vkCmdResetEvent2 = (PFN_vkCmdResetEvent2)global_table.vkGetDeviceProcAddr(device, "vkCmdResetEvent2");
	vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2)global_table.vkGetDeviceProcAddr(device, "vkCmdWaitEvents2");
	vkQueueSubmit2 = (PFN_vkQueueSubmit2)global_table.vkGetDeviceProcAddr(device, "vkQueueSubmit2");
	vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyBuffer2");
	vkCmdCopyImage2 = (PFN_vkCmdCopyImage2)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyImage2");
	vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyBufferToImage2");
	vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyImageToBuffer2");
	vkCmdBlitImage2 = (PFN_vkCmdBlitImage2)global_table.vkGetDeviceProcAddr(device, "vkCmdBlitImage2");
	vkCmdResolveImage2 = (PFN_vkCmdResolveImage2)global_table.vkGetDeviceProcAddr(device, "vkCmdResolveImage2");
	vkCmdBeginRendering = (PFN_vkCmdBeginRendering)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginRendering");
	vkCmdEndRendering = (PFN_vkCmdEndRendering)global_table.vkGetDeviceProcAddr(device, "vkCmdEndRendering");
	vkCmdSetCullMode = (PFN_vkCmdSetCullMode)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCullMode");
	vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace)global_table.vkGetDeviceProcAddr(device, "vkCmdSetFrontFace");
	vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount)global_table.vkGetDeviceProcAddr(device, "vkCmdSetScissorWithCount");
	vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2)global_table.vkGetDeviceProcAddr(device, "vkCmdBindVertexBuffers2");
	vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthTestEnable");
	vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBoundsTestEnable");
	vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable)global_table.vkGetDeviceProcAddr(device, "vkCmdSetStencilTestEnable");
	vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp)global_table.vkGetDeviceProcAddr(device, "vkCmdSetStencilOp");
	vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRasterizerDiscardEnable");
	vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBiasEnable");
	vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPrimitiveRestartEnable");
	vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceImageMemoryRequirements");
	vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceImageSparseMemoryRequirements");
#endif
#if defined(VK_KHR_ray_tracing_pipeline) 
	vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdTraceRaysIndirectKHR");
	vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRayTracingPipelineStackSizeKHR");
	vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetRayTracingShaderGroupHandlesKHR");
	vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)global_table.vkGetDeviceProcAddr(device, "vkGetRayTracingShaderGroupStackSizeKHR");
	vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdTraceRaysKHR");
	vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
	vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateRayTracingPipelinesKHR");
#endif
#if defined(VK_VERSION_1_2) 
	vkResetQueryPool = (PFN_vkResetQueryPool)global_table.vkGetDeviceProcAddr(device, "vkResetQueryPool");
	vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddress");
	vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginRenderPass2");
	vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndirectCount");
	vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirectCount");
	vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)global_table.vkGetDeviceProcAddr(device, "vkCreateRenderPass2");
	vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)global_table.vkGetDeviceProcAddr(device, "vkCmdNextSubpass2");
	vkWaitSemaphores = (PFN_vkWaitSemaphores)global_table.vkGetDeviceProcAddr(device, "vkWaitSemaphores");
	vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)global_table.vkGetDeviceProcAddr(device, "vkCmdEndRenderPass2");
	vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreCounterValue");
	vkSignalSemaphore = (PFN_vkSignalSemaphore)global_table.vkGetDeviceProcAddr(device, "vkSignalSemaphore");
	vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)global_table.vkGetDeviceProcAddr(device, "vkGetBufferDeviceAddress");
	vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)global_table.vkGetDeviceProcAddr(device, "vkGetBufferOpaqueCaptureAddress");
#endif
#if defined(VK_NV_device_generated_commands) 
	vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)global_table.vkGetDeviceProcAddr(device, "vkCmdPreprocessGeneratedCommandsNV");
	vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)global_table.vkGetDeviceProcAddr(device, "vkCmdBindPipelineShaderGroupNV");
	vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)global_table.vkGetDeviceProcAddr(device, "vkDestroyIndirectCommandsLayoutNV");
	vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)global_table.vkGetDeviceProcAddr(device, "vkGetGeneratedCommandsMemoryRequirementsNV");
	vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)global_table.vkGetDeviceProcAddr(device, "vkCreateIndirectCommandsLayoutNV");
	vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)global_table.vkGetDeviceProcAddr(device, "vkCmdExecuteGeneratedCommandsNV");
#endif
#if defined(VK_EXT_pipeline_properties) 
	vkGetPipelinePropertiesEXT = (PFN_vkGetPipelinePropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkGetPipelinePropertiesEXT");
#endif
#if defined(VK_EXT_shader_module_identifier) 
	vkGetShaderModuleIdentifierEXT = (PFN_vkGetShaderModuleIdentifierEXT)global_table.vkGetDeviceProcAddr(device, "vkGetShaderModuleIdentifierEXT");
	vkGetShaderModuleCreateInfoIdentifierEXT = (PFN_vkGetShaderModuleCreateInfoIdentifierEXT)global_table.vkGetDeviceProcAddr(device, "vkGetShaderModuleCreateInfoIdentifierEXT");
#endif
#if defined(VK_NV_clip_space_w_scaling) 
	vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewportWScalingNV");
#endif
#if defined(VK_HUAWEI_subpass_shading) 
	vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = (PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI");
	vkCmdSubpassShadingHUAWEI = (PFN_vkCmdSubpassShadingHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkCmdSubpassShadingHUAWEI");
#endif
#if defined(VK_INTEL_performance_query) 
	vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPerformanceStreamMarkerINTEL");
	vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)global_table.vkGetDeviceProcAddr(device, "vkReleasePerformanceConfigurationINTEL");
	vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)global_table.vkGetDeviceProcAddr(device, "vkInitializePerformanceApiINTEL");
	vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)global_table.vkGetDeviceProcAddr(device, "vkUninitializePerformanceApiINTEL");
	vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPerformanceMarkerINTEL");
	vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPerformanceOverrideINTEL");
	vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)global_table.vkGetDeviceProcAddr(device, "vkAcquirePerformanceConfigurationINTEL");
	vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)global_table.vkGetDeviceProcAddr(device, "vkQueueSetPerformanceConfigurationINTEL");
	vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)global_table.vkGetDeviceProcAddr(device, "vkGetPerformanceParameterINTEL");
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state3) 
	vkCmdSetAlphaToCoverageEnableEXT = (PFN_vkCmdSetAlphaToCoverageEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetAlphaToCoverageEnableEXT");
	vkCmdSetCoverageModulationModeNV = (PFN_vkCmdSetCoverageModulationModeNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoverageModulationModeNV");
	vkCmdSetSampleMaskEXT = (PFN_vkCmdSetSampleMaskEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetSampleMaskEXT");
	vkCmdSetColorBlendEnableEXT = (PFN_vkCmdSetColorBlendEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetColorBlendEnableEXT");
	vkCmdSetCoverageToColorLocationNV = (PFN_vkCmdSetCoverageToColorLocationNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoverageToColorLocationNV");
	vkCmdSetCoverageModulationTableNV = (PFN_vkCmdSetCoverageModulationTableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoverageModulationTableNV");
	vkCmdSetProvokingVertexModeEXT = (PFN_vkCmdSetProvokingVertexModeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetProvokingVertexModeEXT");
	vkCmdSetColorWriteMaskEXT = (PFN_vkCmdSetColorWriteMaskEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetColorWriteMaskEXT");
	vkCmdSetSampleLocationsEnableEXT = (PFN_vkCmdSetSampleLocationsEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetSampleLocationsEnableEXT");
	vkCmdSetAlphaToOneEnableEXT = (PFN_vkCmdSetAlphaToOneEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetAlphaToOneEnableEXT");
	vkCmdSetDepthClipNegativeOneToOneEXT = (PFN_vkCmdSetDepthClipNegativeOneToOneEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthClipNegativeOneToOneEXT");
	vkCmdSetTessellationDomainOriginEXT = (PFN_vkCmdSetTessellationDomainOriginEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetTessellationDomainOriginEXT");
	vkCmdSetDepthClampEnableEXT = (PFN_vkCmdSetDepthClampEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthClampEnableEXT");
	vkCmdSetPolygonModeEXT = (PFN_vkCmdSetPolygonModeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPolygonModeEXT");
	vkCmdSetRasterizationSamplesEXT = (PFN_vkCmdSetRasterizationSamplesEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRasterizationSamplesEXT");
	vkCmdSetLogicOpEnableEXT = (PFN_vkCmdSetLogicOpEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetLogicOpEnableEXT");
	vkCmdSetColorBlendEquationEXT = (PFN_vkCmdSetColorBlendEquationEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetColorBlendEquationEXT");
	vkCmdSetRasterizationStreamEXT = (PFN_vkCmdSetRasterizationStreamEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRasterizationStreamEXT");
	vkCmdSetConservativeRasterizationModeEXT = (PFN_vkCmdSetConservativeRasterizationModeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetConservativeRasterizationModeEXT");
	vkCmdSetExtraPrimitiveOverestimationSizeEXT = (PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
	vkCmdSetDepthClipEnableEXT = (PFN_vkCmdSetDepthClipEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthClipEnableEXT");
	vkCmdSetColorBlendAdvancedEXT = (PFN_vkCmdSetColorBlendAdvancedEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetColorBlendAdvancedEXT");
	vkCmdSetLineRasterizationModeEXT = (PFN_vkCmdSetLineRasterizationModeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetLineRasterizationModeEXT");
	vkCmdSetLineStippleEnableEXT = (PFN_vkCmdSetLineStippleEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetLineStippleEnableEXT");
	vkCmdSetViewportWScalingEnableNV = (PFN_vkCmdSetViewportWScalingEnableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewportWScalingEnableNV");
	vkCmdSetViewportSwizzleNV = (PFN_vkCmdSetViewportSwizzleNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewportSwizzleNV");
	vkCmdSetCoverageToColorEnableNV = (PFN_vkCmdSetCoverageToColorEnableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoverageToColorEnableNV");
	vkCmdSetCoverageModulationTableEnableNV = (PFN_vkCmdSetCoverageModulationTableEnableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoverageModulationTableEnableNV");
	vkCmdSetShadingRateImageEnableNV = (PFN_vkCmdSetShadingRateImageEnableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetShadingRateImageEnableNV");
	vkCmdSetRepresentativeFragmentTestEnableNV = (PFN_vkCmdSetRepresentativeFragmentTestEnableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRepresentativeFragmentTestEnableNV");
	vkCmdSetCoverageReductionModeNV = (PFN_vkCmdSetCoverageReductionModeNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoverageReductionModeNV");
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state) 
	vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetStencilTestEnableEXT");
	vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthTestEnableEXT");
	vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCullModeEXT");
	vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetFrontFaceEXT");
	vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPrimitiveTopologyEXT");
	vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewportWithCountEXT");
	vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetScissorWithCountEXT");
	vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBindVertexBuffers2EXT");
	vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthWriteEnableEXT");
	vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthCompareOpEXT");
	vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBoundsTestEnableEXT");
	vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetStencilOpEXT");
#endif
#if defined(VK_EXT_multi_draw) 
	vkCmdDrawMultiEXT = (PFN_vkCmdDrawMultiEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMultiEXT");
	vkCmdDrawMultiIndexedEXT = (PFN_vkCmdDrawMultiIndexedEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMultiIndexedEXT");
#endif
#if defined(VK_NV_external_memory_rdma) 
	vkGetMemoryRemoteAddressNV = (PFN_vkGetMemoryRemoteAddressNV)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryRemoteAddressNV");
#endif
#if defined(VK_EXT_shader_object) 
	vkCreateShadersEXT = (PFN_vkCreateShadersEXT)global_table.vkGetDeviceProcAddr(device, "vkCreateShadersEXT");
	vkDestroyShaderEXT = (PFN_vkDestroyShaderEXT)global_table.vkGetDeviceProcAddr(device, "vkDestroyShaderEXT");
	vkGetShaderBinaryDataEXT = (PFN_vkGetShaderBinaryDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetShaderBinaryDataEXT");
	vkCmdBindShadersEXT = (PFN_vkCmdBindShadersEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBindShadersEXT");
#endif
#if defined(VK_KHR_bind_memory2) 
	vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)global_table.vkGetDeviceProcAddr(device, "vkBindBufferMemory2KHR");
	vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)global_table.vkGetDeviceProcAddr(device, "vkBindImageMemory2KHR");
#endif
#if defined(VK_EXT_debug_utils) 
	vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)global_table.vkGetDeviceProcAddr(device, "vkQueueEndDebugUtilsLabelEXT");
	vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)global_table.vkGetDeviceProcAddr(device, "vkQueueBeginDebugUtilsLabelEXT");
	vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginDebugUtilsLabelEXT");
	vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)global_table.vkGetDeviceProcAddr(device, "vkSetDebugUtilsObjectNameEXT");
	vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)global_table.vkGetDeviceProcAddr(device, "vkQueueInsertDebugUtilsLabelEXT");
	vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)global_table.vkGetDeviceProcAddr(device, "vkSetDebugUtilsObjectTagEXT");
	vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdEndDebugUtilsLabelEXT");
	vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdInsertDebugUtilsLabelEXT");
#endif
#if defined(VK_NV_low_latency2) 
	vkQueueNotifyOutOfBandNV = (PFN_vkQueueNotifyOutOfBandNV)global_table.vkGetDeviceProcAddr(device, "vkQueueNotifyOutOfBandNV");
	vkSetLatencySleepModeNV = (PFN_vkSetLatencySleepModeNV)global_table.vkGetDeviceProcAddr(device, "vkSetLatencySleepModeNV");
	vkLatencySleepNV = (PFN_vkLatencySleepNV)global_table.vkGetDeviceProcAddr(device, "vkLatencySleepNV");
	vkSetLatencyMarkerNV = (PFN_vkSetLatencyMarkerNV)global_table.vkGetDeviceProcAddr(device, "vkSetLatencyMarkerNV");
	vkGetLatencyTimingsNV = (PFN_vkGetLatencyTimingsNV)global_table.vkGetDeviceProcAddr(device, "vkGetLatencyTimingsNV");
#endif
#if defined(VK_EXT_display_control) 
	vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)global_table.vkGetDeviceProcAddr(device, "vkRegisterDeviceEventEXT");
	vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)global_table.vkGetDeviceProcAddr(device, "vkRegisterDisplayEventEXT");
	vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)global_table.vkGetDeviceProcAddr(device, "vkDisplayPowerControlEXT");
	vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainCounterEXT");
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) 
	vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroySamplerYcbcrConversionKHR");
	vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateSamplerYcbcrConversionKHR");
#endif
#if defined(VK_KHR_pipeline_executable_properties) 
	vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)global_table.vkGetDeviceProcAddr(device, "vkGetPipelineExecutableStatisticsKHR");
	vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)global_table.vkGetDeviceProcAddr(device, "vkGetPipelineExecutableInternalRepresentationsKHR");
	vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetPipelineExecutablePropertiesKHR");
#endif
#if defined(VK_AMDX_shader_enqueue) 
	vkCreateExecutionGraphPipelinesAMDX = (PFN_vkCreateExecutionGraphPipelinesAMDX)global_table.vkGetDeviceProcAddr(device, "vkCreateExecutionGraphPipelinesAMDX");
	vkGetExecutionGraphPipelineNodeIndexAMDX = (PFN_vkGetExecutionGraphPipelineNodeIndexAMDX)global_table.vkGetDeviceProcAddr(device, "vkGetExecutionGraphPipelineNodeIndexAMDX");
	vkCmdDispatchGraphIndirectCountAMDX = (PFN_vkCmdDispatchGraphIndirectCountAMDX)global_table.vkGetDeviceProcAddr(device, "vkCmdDispatchGraphIndirectCountAMDX");
	vkGetExecutionGraphPipelineScratchSizeAMDX = (PFN_vkGetExecutionGraphPipelineScratchSizeAMDX)global_table.vkGetDeviceProcAddr(device, "vkGetExecutionGraphPipelineScratchSizeAMDX");
	vkCmdDispatchGraphAMDX = (PFN_vkCmdDispatchGraphAMDX)global_table.vkGetDeviceProcAddr(device, "vkCmdDispatchGraphAMDX");
	vkCmdInitializeGraphScratchMemoryAMDX = (PFN_vkCmdInitializeGraphScratchMemoryAMDX)global_table.vkGetDeviceProcAddr(device, "vkCmdInitializeGraphScratchMemoryAMDX");
	vkCmdDispatchGraphIndirectAMDX = (PFN_vkCmdDispatchGraphIndirectAMDX)global_table.vkGetDeviceProcAddr(device, "vkCmdDispatchGraphIndirectAMDX");
#endif
#if defined(VK_KHR_acceleration_structure) 
	vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR)global_table.vkGetDeviceProcAddr(device, "vkCopyAccelerationStructureToMemoryKHR");
	vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)global_table.vkGetDeviceProcAddr(device, "vkCopyAccelerationStructureKHR");
	vkGetAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetAccelerationStructureBuildSizesKHR");
	vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR)global_table.vkGetDeviceProcAddr(device, "vkWriteAccelerationStructuresPropertiesKHR");
	vkBuildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR)global_table.vkGetDeviceProcAddr(device, "vkBuildAccelerationStructuresKHR");
	vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR)global_table.vkGetDeviceProcAddr(device, "vkCopyMemoryToAccelerationStructureKHR");
	vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyAccelerationStructureKHR");
	vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteAccelerationStructuresPropertiesKHR");
	vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroyAccelerationStructureKHR");
	vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceAccelerationStructureCompatibilityKHR");
	vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR)global_table.vkGetDeviceProcAddr(device, "vkGetAccelerationStructureDeviceAddressKHR");
	vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateAccelerationStructureKHR");
	vkCmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBuildAccelerationStructuresKHR");
	vkCmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBuildAccelerationStructuresIndirectKHR");
	vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyAccelerationStructureToMemoryKHR");
	vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMemoryToAccelerationStructureKHR");
#endif
#if defined(VK_QNX_external_memory_screen_buffer) 
	vkGetScreenBufferPropertiesQNX = (PFN_vkGetScreenBufferPropertiesQNX)global_table.vkGetDeviceProcAddr(device, "vkGetScreenBufferPropertiesQNX");
#endif
#if defined(VK_NV_external_memory_win32) 
	vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryWin32HandleNV");
#endif
#if defined(VK_NV_memory_decompression) 
	vkCmdDecompressMemoryNV = (PFN_vkCmdDecompressMemoryNV)global_table.vkGetDeviceProcAddr(device, "vkCmdDecompressMemoryNV");
	vkCmdDecompressMemoryIndirectCountNV = (PFN_vkCmdDecompressMemoryIndirectCountNV)global_table.vkGetDeviceProcAddr(device, "vkCmdDecompressMemoryIndirectCountNV");
#endif
#if defined(VK_KHR_dynamic_rendering) 
	vkCmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdEndRenderingKHR");
	vkCmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginRenderingKHR");
#endif
#if defined(VK_EXT_pageable_device_local_memory) 
	vkSetDeviceMemoryPriorityEXT = (PFN_vkSetDeviceMemoryPriorityEXT)global_table.vkGetDeviceProcAddr(device, "vkSetDeviceMemoryPriorityEXT");
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) 
	vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)global_table.vkGetDeviceProcAddr(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
	vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif
#if defined(VK_EXT_host_image_copy) 
	vkCopyMemoryToImageEXT = (PFN_vkCopyMemoryToImageEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMemoryToImageEXT");
	vkCopyImageToMemoryEXT = (PFN_vkCopyImageToMemoryEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyImageToMemoryEXT");
	vkCopyImageToImageEXT = (PFN_vkCopyImageToImageEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyImageToImageEXT");
	vkTransitionImageLayoutEXT = (PFN_vkTransitionImageLayoutEXT)global_table.vkGetDeviceProcAddr(device, "vkTransitionImageLayoutEXT");
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2) 
	vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPrimitiveRestartEnableEXT");
	vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRasterizerDiscardEnableEXT");
	vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPatchControlPointsEXT");
	vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBiasEnableEXT");
	vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetLogicOpEXT");
#endif
#if defined(VK_EXT_external_memory_host) 
	vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryHostPointerPropertiesEXT");
#endif
#if defined(VK_KHR_external_semaphore_fd) 
	vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)global_table.vkGetDeviceProcAddr(device, "vkImportSemaphoreFdKHR");
	vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreFdKHR");
#endif
#if defined(VK_KHR_performance_query) 
	vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)global_table.vkGetDeviceProcAddr(device, "vkReleaseProfilingLockKHR");
	vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)global_table.vkGetDeviceProcAddr(device, "vkAcquireProfilingLockKHR");
#endif
#if defined(VK_HUAWEI_cluster_culling_shader) 
	vkCmdDrawClusterIndirectHUAWEI = (PFN_vkCmdDrawClusterIndirectHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawClusterIndirectHUAWEI");
	vkCmdDrawClusterHUAWEI = (PFN_vkCmdDrawClusterHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawClusterHUAWEI");
#endif
#if defined(VK_NV_external_memory_sci_buf) 
	vkGetMemorySciBufNV = (PFN_vkGetMemorySciBufNV)global_table.vkGetDeviceProcAddr(device, "vkGetMemorySciBufNV");
#endif
#if defined(VK_KHR_external_memory_win32) 
	vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryWin32HandleKHR");
	vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryWin32HandlePropertiesKHR");
#endif
#if defined(VK_EXT_mesh_shader) 
	vkCmdDrawMeshTasksEXT = (PFN_vkCmdDrawMeshTasksEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksEXT");
	vkCmdDrawMeshTasksIndirectEXT = (PFN_vkCmdDrawMeshTasksIndirectEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksIndirectEXT");
	vkCmdDrawMeshTasksIndirectCountEXT = (PFN_vkCmdDrawMeshTasksIndirectCountEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksIndirectCountEXT");
#endif
#if defined(VK_EXT_full_screen_exclusive) 
	vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)global_table.vkGetDeviceProcAddr(device, "vkReleaseFullScreenExclusiveModeEXT");
	vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)global_table.vkGetDeviceProcAddr(device, "vkAcquireFullScreenExclusiveModeEXT");
#endif
#if defined(VK_EXT_private_data) 
	vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)global_table.vkGetDeviceProcAddr(device, "vkSetPrivateDataEXT");
	vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)global_table.vkGetDeviceProcAddr(device, "vkDestroyPrivateDataSlotEXT");
	vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)global_table.vkGetDeviceProcAddr(device, "vkCreatePrivateDataSlotEXT");
	vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetPrivateDataEXT");
#endif
#if defined(VK_HUAWEI_invocation_mask) 
	vkCmdBindInvocationMaskHUAWEI = (PFN_vkCmdBindInvocationMaskHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkCmdBindInvocationMaskHUAWEI");
#endif
#if defined(VK_QCOM_tile_properties) 
	vkGetDynamicRenderingTilePropertiesQCOM = (PFN_vkGetDynamicRenderingTilePropertiesQCOM)global_table.vkGetDeviceProcAddr(device, "vkGetDynamicRenderingTilePropertiesQCOM");
	vkGetFramebufferTilePropertiesQCOM = (PFN_vkGetFramebufferTilePropertiesQCOM)global_table.vkGetDeviceProcAddr(device, "vkGetFramebufferTilePropertiesQCOM");
#endif
#if defined(VK_KHR_external_fence_win32) 
	vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)global_table.vkGetDeviceProcAddr(device, "vkGetFenceWin32HandleKHR");
	vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)global_table.vkGetDeviceProcAddr(device, "vkImportFenceWin32HandleKHR");
#endif
#if defined(VK_KHR_create_renderpass2) 
	vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginRenderPass2KHR");
	vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdEndRenderPass2KHR");
	vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdNextSubpass2KHR");
	vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)global_table.vkGetDeviceProcAddr(device, "vkCreateRenderPass2KHR");
#endif
#if defined(VK_EXT_depth_bias_control) 
	vkCmdSetDepthBias2EXT = (PFN_vkCmdSetDepthBias2EXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBias2EXT");
#endif
#if defined(VK_KHR_copy_commands2) 
	vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyImageToBuffer2KHR");
	vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyBuffer2KHR");
	vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyImage2KHR");
	vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyBufferToImage2KHR");
	vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBlitImage2KHR");
	vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdResolveImage2KHR");
#endif
#if defined(VK_EXT_color_write_enable) 
	vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetColorWriteEnableEXT");
#endif
#if defined(VK_NVX_image_view_handle) 
	vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)global_table.vkGetDeviceProcAddr(device, "vkGetImageViewAddressNVX");
	vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)global_table.vkGetDeviceProcAddr(device, "vkGetImageViewHandleNVX");
#endif
#if defined(VK_KHR_video_encode_queue) 
	vkGetEncodedVideoSessionParametersKHR = (PFN_vkGetEncodedVideoSessionParametersKHR)global_table.vkGetDeviceProcAddr(device, "vkGetEncodedVideoSessionParametersKHR");
	vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdEncodeVideoKHR");
#endif
#if defined(VK_EXT_host_query_reset) 
	vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)global_table.vkGetDeviceProcAddr(device, "vkResetQueryPoolEXT");
#endif
#if defined(VK_ANDROID_native_buffer) 
	vkGetSwapchainGrallocUsageANDROID = (PFN_vkGetSwapchainGrallocUsageANDROID)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainGrallocUsageANDROID");
	vkAcquireImageANDROID = (PFN_vkAcquireImageANDROID)global_table.vkGetDeviceProcAddr(device, "vkAcquireImageANDROID");
	vkQueueSignalReleaseImageANDROID = (PFN_vkQueueSignalReleaseImageANDROID)global_table.vkGetDeviceProcAddr(device, "vkQueueSignalReleaseImageANDROID");
	vkGetSwapchainGrallocUsage2ANDROID = (PFN_vkGetSwapchainGrallocUsage2ANDROID)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainGrallocUsage2ANDROID");
#endif
#if defined(VK_NV_external_sci_sync) 
	vkGetSemaphoreSciSyncObjNV = (PFN_vkGetSemaphoreSciSyncObjNV)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreSciSyncObjNV");
	vkImportSemaphoreSciSyncObjNV = (PFN_vkImportSemaphoreSciSyncObjNV)global_table.vkGetDeviceProcAddr(device, "vkImportSemaphoreSciSyncObjNV");
#endif
#if defined(VK_KHR_external_memory_fd) 
	vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryFdPropertiesKHR");
	vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryFdKHR");
#endif
#if defined(VK_EXT_transform_feedback) 
	vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdEndQueryIndexedEXT");
	vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndirectByteCountEXT");
	vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdEndTransformFeedbackEXT");
	vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBindTransformFeedbackBuffersEXT");
	vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginTransformFeedbackEXT");
	vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginQueryIndexedEXT");
#endif
#if defined(VK_NV_copy_memory_indirect) 
	vkCmdCopyMemoryToImageIndirectNV = (PFN_vkCmdCopyMemoryToImageIndirectNV)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMemoryToImageIndirectNV");
	vkCmdCopyMemoryIndirectNV = (PFN_vkCmdCopyMemoryIndirectNV)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMemoryIndirectNV");
#endif
#if defined(VK_KHR_external_semaphore_win32) 
	vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)global_table.vkGetDeviceProcAddr(device, "vkImportSemaphoreWin32HandleKHR");
	vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreWin32HandleKHR");
#endif
#if defined(VK_EXT_validation_cache) 
	vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)global_table.vkGetDeviceProcAddr(device, "vkCreateValidationCacheEXT");
	vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)global_table.vkGetDeviceProcAddr(device, "vkGetValidationCacheDataEXT");
	vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)global_table.vkGetDeviceProcAddr(device, "vkDestroyValidationCacheEXT");
	vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)global_table.vkGetDeviceProcAddr(device, "vkMergeValidationCachesEXT");
#endif
#if defined(VK_KHR_timeline_semaphore) 
	vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)global_table.vkGetDeviceProcAddr(device, "vkWaitSemaphoresKHR");
	vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreCounterValueKHR");
	vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)global_table.vkGetDeviceProcAddr(device, "vkSignalSemaphoreKHR");
#endif
#if defined(VK_KHR_swapchain) 
	vkQueuePresentKHR = (PFN_vkQueuePresentKHR)global_table.vkGetDeviceProcAddr(device, "vkQueuePresentKHR");
	vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateSwapchainKHR");
	vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroySwapchainKHR");
	vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainImagesKHR");
	vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)global_table.vkGetDeviceProcAddr(device, "vkAcquireNextImageKHR");
#endif
#if defined(VK_KHR_draw_indirect_count) 
	vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndirectCountKHR");
	vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirectCountKHR");
#endif
#if defined(VK_KHR_ray_tracing_maintenance1) 
	vkCmdTraceRaysIndirect2KHR = (PFN_vkCmdTraceRaysIndirect2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdTraceRaysIndirect2KHR");
#endif
#if defined(VK_KHR_fragment_shading_rate) 
	vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetFragmentShadingRateKHR");
#endif
#if defined(VKSC_VERSION_1_0) 
	vkGetCommandPoolMemoryConsumption = (PFN_vkGetCommandPoolMemoryConsumption)global_table.vkGetDeviceProcAddr(device, "vkGetCommandPoolMemoryConsumption");
	vkGetFaultData = (PFN_vkGetFaultData)global_table.vkGetDeviceProcAddr(device, "vkGetFaultData");
#endif
#if defined(VK_KHR_maintenance5) 
	vkGetDeviceImageSubresourceLayoutKHR = (PFN_vkGetDeviceImageSubresourceLayoutKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceImageSubresourceLayoutKHR");
	vkCmdBindIndexBuffer2KHR = (PFN_vkCmdBindIndexBuffer2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBindIndexBuffer2KHR");
	vkGetRenderingAreaGranularityKHR = (PFN_vkGetRenderingAreaGranularityKHR)global_table.vkGetDeviceProcAddr(device, "vkGetRenderingAreaGranularityKHR");
	vkGetImageSubresourceLayout2KHR = (PFN_vkGetImageSubresourceLayout2KHR)global_table.vkGetDeviceProcAddr(device, "vkGetImageSubresourceLayout2KHR");
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group) 
	vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
	vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
	vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)global_table.vkGetDeviceProcAddr(device, "vkAcquireNextImage2KHR");
#endif
#if defined(VK_KHR_display_swapchain) 
	vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateSharedSwapchainsKHR");
#endif
#if defined(VK_KHR_maintenance3) 
	vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutSupportKHR");
#endif
#if defined(VK_NV_device_generated_commands_compute) 
	vkCmdUpdatePipelineIndirectBufferNV = (PFN_vkCmdUpdatePipelineIndirectBufferNV)global_table.vkGetDeviceProcAddr(device, "vkCmdUpdatePipelineIndirectBufferNV");
	vkGetPipelineIndirectDeviceAddressNV = (PFN_vkGetPipelineIndirectDeviceAddressNV)global_table.vkGetDeviceProcAddr(device, "vkGetPipelineIndirectDeviceAddressNV");
	vkGetPipelineIndirectMemoryRequirementsNV = (PFN_vkGetPipelineIndirectMemoryRequirementsNV)global_table.vkGetDeviceProcAddr(device, "vkGetPipelineIndirectMemoryRequirementsNV");
#endif
#if defined(VK_EXT_conditional_rendering) 
	vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdEndConditionalRenderingEXT");
	vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBeginConditionalRenderingEXT");
#endif
#if defined(VK_KHR_video_decode_queue) 
	vkCmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdDecodeVideoKHR");
#endif
#if defined(VK_EXT_hdr_metadata) 
	vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)global_table.vkGetDeviceProcAddr(device, "vkSetHdrMetadataEXT");
#endif
#if defined(VK_KHR_maintenance4) 
	vkGetDeviceBufferMemoryRequirementsKHR = (PFN_vkGetDeviceBufferMemoryRequirementsKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceBufferMemoryRequirementsKHR");
	vkGetDeviceImageMemoryRequirementsKHR = (PFN_vkGetDeviceImageMemoryRequirementsKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceImageMemoryRequirementsKHR");
	vkGetDeviceImageSparseMemoryRequirementsKHR = (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceImageSparseMemoryRequirementsKHR");
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_vertex_input_dynamic_state) 
	vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetVertexInputEXT");
#endif
#if defined(VK_KHR_shared_presentable_image) 
	vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainStatusKHR");
#endif
#if defined(VK_EXT_discard_rectangles) 
	vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDiscardRectangleEXT");
	vkCmdSetDiscardRectangleModeEXT = (PFN_vkCmdSetDiscardRectangleModeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDiscardRectangleModeEXT");
	vkCmdSetDiscardRectangleEnableEXT = (PFN_vkCmdSetDiscardRectangleEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDiscardRectangleEnableEXT");
#endif
#if defined(VK_EXT_host_image_copy) || defined(VK_EXT_image_compression_control) 
	vkGetImageSubresourceLayout2EXT = (PFN_vkGetImageSubresourceLayout2EXT)global_table.vkGetDeviceProcAddr(device, "vkGetImageSubresourceLayout2EXT");
#endif
#if defined(VK_EXT_sample_locations) 
	vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetSampleLocationsEXT");
#endif
#if defined(VK_FUCHSIA_external_memory) 
	vkGetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryZirconHandleFUCHSIA");
	vkGetMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif
#if defined(VK_EXT_full_screen_exclusive) || defined(VK_EXT_full_screen_exclusive) 
	vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif
#if defined(VK_NV_mesh_shader) 
	vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksNV");
	vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksIndirectNV");
	vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksIndirectCountNV");
#endif
#if defined(VK_AMD_draw_indirect_count) 
	vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndirectCountAMD");
	vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirectCountAMD");
#endif
#if defined(VK_KHR_maintenance1) 
	vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)global_table.vkGetDeviceProcAddr(device, "vkTrimCommandPoolKHR");
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) 
	vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)global_table.vkGetDeviceProcAddr(device, "vkGetQueueCheckpointDataNV");
	vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCheckpointNV");
#endif
#if defined(VK_GOOGLE_display_timing) 
	vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)global_table.vkGetDeviceProcAddr(device, "vkGetRefreshCycleDurationGOOGLE");
	vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)global_table.vkGetDeviceProcAddr(device, "vkGetPastPresentationTimingGOOGLE");
#endif
#if defined(VK_AMD_display_native_hdr) 
	vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)global_table.vkGetDeviceProcAddr(device, "vkSetLocalDimmingAMD");
#endif
#if defined(VK_KHR_external_fence_fd) 
	vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)global_table.vkGetDeviceProcAddr(device, "vkImportFenceFdKHR");
	vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)global_table.vkGetDeviceProcAddr(device, "vkGetFenceFdKHR");
#endif
#if defined(VK_KHR_present_wait) 
	vkWaitForPresentKHR = (PFN_vkWaitForPresentKHR)global_table.vkGetDeviceProcAddr(device, "vkWaitForPresentKHR");
#endif
#if defined(VK_EXT_metal_objects) 
	vkExportMetalObjectsEXT = (PFN_vkExportMetalObjectsEXT)global_table.vkGetDeviceProcAddr(device, "vkExportMetalObjectsEXT");
#endif
#if defined(VK_EXT_swapchain_maintenance1) 
	vkReleaseSwapchainImagesEXT = (PFN_vkReleaseSwapchainImagesEXT)global_table.vkGetDeviceProcAddr(device, "vkReleaseSwapchainImagesEXT");
#endif
#if defined(VK_EXT_image_drm_format_modifier) 
	vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif
#if defined(VK_EXT_calibrated_timestamps) 
	vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)global_table.vkGetDeviceProcAddr(device, "vkGetCalibratedTimestampsEXT");
#endif
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state) 
	vkCmdSetAttachmentFeedbackLoopEnableEXT = (PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
#endif
#if defined(VK_NV_scissor_exclusive) 
	vkCmdSetExclusiveScissorEnableNV = (PFN_vkCmdSetExclusiveScissorEnableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetExclusiveScissorEnableNV");
	vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetExclusiveScissorNV");
#endif
#if defined(VK_EXT_buffer_device_address) 
	vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)global_table.vkGetDeviceProcAddr(device, "vkGetBufferDeviceAddressEXT");
#endif
#if defined(VK_EXT_line_rasterization) 
	vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetLineStippleEXT");
#endif
#if defined(VK_FUCHSIA_external_semaphore) 
	vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreZirconHandleFUCHSIA");
	vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif
#if defined(VK_KHR_object_refresh) 
	vkCmdRefreshObjectsKHR = (PFN_vkCmdRefreshObjectsKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdRefreshObjectsKHR");
#endif
#if defined(VK_EXT_device_fault) 
	vkGetDeviceFaultInfoEXT = (PFN_vkGetDeviceFaultInfoEXT)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceFaultInfoEXT");
#endif
#if defined(VK_NV_external_sci_sync2) 
	vkCreateSemaphoreSciSyncPoolNV = (PFN_vkCreateSemaphoreSciSyncPoolNV)global_table.vkGetDeviceProcAddr(device, "vkCreateSemaphoreSciSyncPoolNV");
	vkDestroySemaphoreSciSyncPoolNV = (PFN_vkDestroySemaphoreSciSyncPoolNV)global_table.vkGetDeviceProcAddr(device, "vkDestroySemaphoreSciSyncPoolNV");
#endif
#if defined(VK_VALVE_descriptor_set_host_mapping) 
	vkGetDescriptorSetLayoutHostMappingInfoVALVE = (PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
	vkGetDescriptorSetHostMappingVALVE = (PFN_vkGetDescriptorSetHostMappingVALVE)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetHostMappingVALVE");
#endif
}
public:
#if defined(VK_VERSION_1_0) 
operator PFN_vkDestroyDevice()const noexcept { return vkDestroyDevice;};
operator PFN_vkResetEvent()const noexcept { return vkResetEvent;};
operator PFN_vkMapMemory()const noexcept { return vkMapMemory;};
operator PFN_vkGetDeviceQueue()const noexcept { return vkGetDeviceQueue;};
operator PFN_vkQueueSubmit()const noexcept { return vkQueueSubmit;};
operator PFN_vkGetDeviceMemoryCommitment()const noexcept { return vkGetDeviceMemoryCommitment;};
operator PFN_vkAllocateMemory()const noexcept { return vkAllocateMemory;};
operator PFN_vkDestroyPipeline()const noexcept { return vkDestroyPipeline;};
operator PFN_vkQueueWaitIdle()const noexcept { return vkQueueWaitIdle;};
operator PFN_vkCmdDispatchIndirect()const noexcept { return vkCmdDispatchIndirect;};
operator PFN_vkCreateDescriptorSetLayout()const noexcept { return vkCreateDescriptorSetLayout;};
operator PFN_vkCreateImage()const noexcept { return vkCreateImage;};
operator PFN_vkFreeMemory()const noexcept { return vkFreeMemory;};
operator PFN_vkDeviceWaitIdle()const noexcept { return vkDeviceWaitIdle;};
operator PFN_vkResetDescriptorPool()const noexcept { return vkResetDescriptorPool;};
operator PFN_vkSetEvent()const noexcept { return vkSetEvent;};
operator PFN_vkUnmapMemory()const noexcept { return vkUnmapMemory;};
operator PFN_vkCreateSampler()const noexcept { return vkCreateSampler;};
operator PFN_vkCreateEvent()const noexcept { return vkCreateEvent;};
operator PFN_vkFlushMappedMemoryRanges()const noexcept { return vkFlushMappedMemoryRanges;};
operator PFN_vkDestroyDescriptorSetLayout()const noexcept { return vkDestroyDescriptorSetLayout;};
operator PFN_vkGetFenceStatus()const noexcept { return vkGetFenceStatus;};
operator PFN_vkInvalidateMappedMemoryRanges()const noexcept { return vkInvalidateMappedMemoryRanges;};
operator PFN_vkCmdUpdateBuffer()const noexcept { return vkCmdUpdateBuffer;};
operator PFN_vkBindBufferMemory()const noexcept { return vkBindBufferMemory;};
operator PFN_vkBindImageMemory()const noexcept { return vkBindImageMemory;};
operator PFN_vkGetBufferMemoryRequirements()const noexcept { return vkGetBufferMemoryRequirements;};
operator PFN_vkDestroySampler()const noexcept { return vkDestroySampler;};
operator PFN_vkDestroyImageView()const noexcept { return vkDestroyImageView;};
operator PFN_vkGetImageMemoryRequirements()const noexcept { return vkGetImageMemoryRequirements;};
operator PFN_vkCreateQueryPool()const noexcept { return vkCreateQueryPool;};
operator PFN_vkGetImageSparseMemoryRequirements()const noexcept { return vkGetImageSparseMemoryRequirements;};
operator PFN_vkQueueBindSparse()const noexcept { return vkQueueBindSparse;};
operator PFN_vkCreateFence()const noexcept { return vkCreateFence;};
operator PFN_vkCreateCommandPool()const noexcept { return vkCreateCommandPool;};
operator PFN_vkDestroyFence()const noexcept { return vkDestroyFence;};
operator PFN_vkGetRenderAreaGranularity()const noexcept { return vkGetRenderAreaGranularity;};
operator PFN_vkResetFences()const noexcept { return vkResetFences;};
operator PFN_vkWaitForFences()const noexcept { return vkWaitForFences;};
operator PFN_vkCreateSemaphore()const noexcept { return vkCreateSemaphore;};
operator PFN_vkDestroyBuffer()const noexcept { return vkDestroyBuffer;};
operator PFN_vkDestroySemaphore()const noexcept { return vkDestroySemaphore;};
operator PFN_vkGetEventStatus()const noexcept { return vkGetEventStatus;};
operator PFN_vkDestroyEvent()const noexcept { return vkDestroyEvent;};
operator PFN_vkDestroyQueryPool()const noexcept { return vkDestroyQueryPool;};
operator PFN_vkGetQueryPoolResults()const noexcept { return vkGetQueryPoolResults;};
operator PFN_vkCreateBuffer()const noexcept { return vkCreateBuffer;};
operator PFN_vkCreateBufferView()const noexcept { return vkCreateBufferView;};
operator PFN_vkDestroyBufferView()const noexcept { return vkDestroyBufferView;};
operator PFN_vkDestroyImage()const noexcept { return vkDestroyImage;};
operator PFN_vkGetImageSubresourceLayout()const noexcept { return vkGetImageSubresourceLayout;};
operator PFN_vkCreatePipelineLayout()const noexcept { return vkCreatePipelineLayout;};
operator PFN_vkCmdNextSubpass()const noexcept { return vkCmdNextSubpass;};
operator PFN_vkCreateImageView()const noexcept { return vkCreateImageView;};
operator PFN_vkCreateShaderModule()const noexcept { return vkCreateShaderModule;};
operator PFN_vkDestroyShaderModule()const noexcept { return vkDestroyShaderModule;};
operator PFN_vkCmdBindIndexBuffer()const noexcept { return vkCmdBindIndexBuffer;};
operator PFN_vkCmdFillBuffer()const noexcept { return vkCmdFillBuffer;};
operator PFN_vkGetPipelineCacheData()const noexcept { return vkGetPipelineCacheData;};
operator PFN_vkCreatePipelineCache()const noexcept { return vkCreatePipelineCache;};
operator PFN_vkDestroyPipelineCache()const noexcept { return vkDestroyPipelineCache;};
operator PFN_vkMergePipelineCaches()const noexcept { return vkMergePipelineCaches;};
operator PFN_vkCreateComputePipelines()const noexcept { return vkCreateComputePipelines;};
operator PFN_vkCreateGraphicsPipelines()const noexcept { return vkCreateGraphicsPipelines;};
operator PFN_vkDestroyPipelineLayout()const noexcept { return vkDestroyPipelineLayout;};
operator PFN_vkCmdCopyImage()const noexcept { return vkCmdCopyImage;};
operator PFN_vkCreateDescriptorPool()const noexcept { return vkCreateDescriptorPool;};
operator PFN_vkDestroyDescriptorPool()const noexcept { return vkDestroyDescriptorPool;};
operator PFN_vkCreateFramebuffer()const noexcept { return vkCreateFramebuffer;};
operator PFN_vkAllocateDescriptorSets()const noexcept { return vkAllocateDescriptorSets;};
operator PFN_vkFreeDescriptorSets()const noexcept { return vkFreeDescriptorSets;};
operator PFN_vkCmdSetLineWidth()const noexcept { return vkCmdSetLineWidth;};
operator PFN_vkUpdateDescriptorSets()const noexcept { return vkUpdateDescriptorSets;};
operator PFN_vkDestroyFramebuffer()const noexcept { return vkDestroyFramebuffer;};
operator PFN_vkCreateRenderPass()const noexcept { return vkCreateRenderPass;};
operator PFN_vkDestroyRenderPass()const noexcept { return vkDestroyRenderPass;};
operator PFN_vkDestroyCommandPool()const noexcept { return vkDestroyCommandPool;};
operator PFN_vkResetCommandPool()const noexcept { return vkResetCommandPool;};
operator PFN_vkAllocateCommandBuffers()const noexcept { return vkAllocateCommandBuffers;};
operator PFN_vkFreeCommandBuffers()const noexcept { return vkFreeCommandBuffers;};
operator PFN_vkBeginCommandBuffer()const noexcept { return vkBeginCommandBuffer;};
operator PFN_vkEndCommandBuffer()const noexcept { return vkEndCommandBuffer;};
operator PFN_vkResetCommandBuffer()const noexcept { return vkResetCommandBuffer;};
operator PFN_vkCmdBindPipeline()const noexcept { return vkCmdBindPipeline;};
operator PFN_vkCmdPipelineBarrier()const noexcept { return vkCmdPipelineBarrier;};
operator PFN_vkCmdSetViewport()const noexcept { return vkCmdSetViewport;};
operator PFN_vkCmdSetScissor()const noexcept { return vkCmdSetScissor;};
operator PFN_vkCmdSetDepthBias()const noexcept { return vkCmdSetDepthBias;};
operator PFN_vkCmdSetBlendConstants()const noexcept { return vkCmdSetBlendConstants;};
operator PFN_vkCmdBindVertexBuffers()const noexcept { return vkCmdBindVertexBuffers;};
operator PFN_vkCmdSetDepthBounds()const noexcept { return vkCmdSetDepthBounds;};
operator PFN_vkCmdSetStencilCompareMask()const noexcept { return vkCmdSetStencilCompareMask;};
operator PFN_vkCmdSetStencilWriteMask()const noexcept { return vkCmdSetStencilWriteMask;};
operator PFN_vkCmdSetStencilReference()const noexcept { return vkCmdSetStencilReference;};
operator PFN_vkCmdBindDescriptorSets()const noexcept { return vkCmdBindDescriptorSets;};
operator PFN_vkCmdDraw()const noexcept { return vkCmdDraw;};
operator PFN_vkCmdDrawIndexed()const noexcept { return vkCmdDrawIndexed;};
operator PFN_vkCmdDrawIndirect()const noexcept { return vkCmdDrawIndirect;};
operator PFN_vkCmdDrawIndexedIndirect()const noexcept { return vkCmdDrawIndexedIndirect;};
operator PFN_vkCmdDispatch()const noexcept { return vkCmdDispatch;};
operator PFN_vkCmdCopyBuffer()const noexcept { return vkCmdCopyBuffer;};
operator PFN_vkCmdBlitImage()const noexcept { return vkCmdBlitImage;};
operator PFN_vkCmdCopyBufferToImage()const noexcept { return vkCmdCopyBufferToImage;};
operator PFN_vkCmdCopyImageToBuffer()const noexcept { return vkCmdCopyImageToBuffer;};
operator PFN_vkCmdClearColorImage()const noexcept { return vkCmdClearColorImage;};
operator PFN_vkCmdClearDepthStencilImage()const noexcept { return vkCmdClearDepthStencilImage;};
operator PFN_vkCmdClearAttachments()const noexcept { return vkCmdClearAttachments;};
operator PFN_vkCmdResolveImage()const noexcept { return vkCmdResolveImage;};
operator PFN_vkCmdSetEvent()const noexcept { return vkCmdSetEvent;};
operator PFN_vkCmdResetEvent()const noexcept { return vkCmdResetEvent;};
operator PFN_vkCmdWaitEvents()const noexcept { return vkCmdWaitEvents;};
operator PFN_vkCmdBeginQuery()const noexcept { return vkCmdBeginQuery;};
operator PFN_vkCmdEndQuery()const noexcept { return vkCmdEndQuery;};
operator PFN_vkCmdResetQueryPool()const noexcept { return vkCmdResetQueryPool;};
operator PFN_vkCmdWriteTimestamp()const noexcept { return vkCmdWriteTimestamp;};
operator PFN_vkCmdCopyQueryPoolResults()const noexcept { return vkCmdCopyQueryPoolResults;};
operator PFN_vkCmdPushConstants()const noexcept { return vkCmdPushConstants;};
operator PFN_vkCmdBeginRenderPass()const noexcept { return vkCmdBeginRenderPass;};
operator PFN_vkCmdEndRenderPass()const noexcept { return vkCmdEndRenderPass;};
operator PFN_vkCmdExecuteCommands()const noexcept { return vkCmdExecuteCommands;};
#endif
#if defined(VK_KHR_device_group) 
operator PFN_vkCmdSetDeviceMaskKHR()const noexcept { return vkCmdSetDeviceMaskKHR;};
operator PFN_vkCmdDispatchBaseKHR()const noexcept { return vkCmdDispatchBaseKHR;};
operator PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR()const noexcept { return vkGetDeviceGroupPeerMemoryFeaturesKHR;};
#endif
#if defined(VK_VERSION_1_1) 
operator PFN_vkBindBufferMemory2()const noexcept { return vkBindBufferMemory2;};
operator PFN_vkGetDeviceGroupPeerMemoryFeatures()const noexcept { return vkGetDeviceGroupPeerMemoryFeatures;};
operator PFN_vkGetBufferMemoryRequirements2()const noexcept { return vkGetBufferMemoryRequirements2;};
operator PFN_vkBindImageMemory2()const noexcept { return vkBindImageMemory2;};
operator PFN_vkCmdSetDeviceMask()const noexcept { return vkCmdSetDeviceMask;};
operator PFN_vkCmdDispatchBase()const noexcept { return vkCmdDispatchBase;};
operator PFN_vkGetImageMemoryRequirements2()const noexcept { return vkGetImageMemoryRequirements2;};
operator PFN_vkGetImageSparseMemoryRequirements2()const noexcept { return vkGetImageSparseMemoryRequirements2;};
operator PFN_vkGetDescriptorSetLayoutSupport()const noexcept { return vkGetDescriptorSetLayoutSupport;};
operator PFN_vkTrimCommandPool()const noexcept { return vkTrimCommandPool;};
operator PFN_vkGetDeviceQueue2()const noexcept { return vkGetDeviceQueue2;};
operator PFN_vkCreateSamplerYcbcrConversion()const noexcept { return vkCreateSamplerYcbcrConversion;};
operator PFN_vkDestroySamplerYcbcrConversion()const noexcept { return vkDestroySamplerYcbcrConversion;};
operator PFN_vkCreateDescriptorUpdateTemplate()const noexcept { return vkCreateDescriptorUpdateTemplate;};
operator PFN_vkDestroyDescriptorUpdateTemplate()const noexcept { return vkDestroyDescriptorUpdateTemplate;};
operator PFN_vkUpdateDescriptorSetWithTemplate()const noexcept { return vkUpdateDescriptorSetWithTemplate;};
#endif
#if defined(VK_EXT_descriptor_buffer) 
operator PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT()const noexcept { return vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT;};
operator PFN_vkCmdSetDescriptorBufferOffsetsEXT()const noexcept { return vkCmdSetDescriptorBufferOffsetsEXT;};
operator PFN_vkGetDescriptorEXT()const noexcept { return vkGetDescriptorEXT;};
operator PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT()const noexcept { return vkGetSamplerOpaqueCaptureDescriptorDataEXT;};
operator PFN_vkGetDescriptorSetLayoutSizeEXT()const noexcept { return vkGetDescriptorSetLayoutSizeEXT;};
operator PFN_vkGetDescriptorSetLayoutBindingOffsetEXT()const noexcept { return vkGetDescriptorSetLayoutBindingOffsetEXT;};
operator PFN_vkCmdBindDescriptorBuffersEXT()const noexcept { return vkCmdBindDescriptorBuffersEXT;};
operator PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT()const noexcept { return vkCmdBindDescriptorBufferEmbeddedSamplersEXT;};
operator PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT()const noexcept { return vkGetBufferOpaqueCaptureDescriptorDataEXT;};
operator PFN_vkGetImageOpaqueCaptureDescriptorDataEXT()const noexcept { return vkGetImageOpaqueCaptureDescriptorDataEXT;};
operator PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT()const noexcept { return vkGetImageViewOpaqueCaptureDescriptorDataEXT;};
#endif
#if defined(VK_EXT_debug_marker) 
operator PFN_vkDebugMarkerSetObjectTagEXT()const noexcept { return vkDebugMarkerSetObjectTagEXT;};
operator PFN_vkCmdDebugMarkerInsertEXT()const noexcept { return vkCmdDebugMarkerInsertEXT;};
operator PFN_vkCmdDebugMarkerBeginEXT()const noexcept { return vkCmdDebugMarkerBeginEXT;};
operator PFN_vkDebugMarkerSetObjectNameEXT()const noexcept { return vkDebugMarkerSetObjectNameEXT;};
operator PFN_vkCmdDebugMarkerEndEXT()const noexcept { return vkCmdDebugMarkerEndEXT;};
#endif
#if defined(VK_AMD_buffer_marker) 
operator PFN_vkCmdWriteBufferMarkerAMD()const noexcept { return vkCmdWriteBufferMarkerAMD;};
#endif
#if defined(VK_NV_optical_flow) 
operator PFN_vkBindOpticalFlowSessionImageNV()const noexcept { return vkBindOpticalFlowSessionImageNV;};
operator PFN_vkCmdOpticalFlowExecuteNV()const noexcept { return vkCmdOpticalFlowExecuteNV;};
operator PFN_vkCreateOpticalFlowSessionNV()const noexcept { return vkCreateOpticalFlowSessionNV;};
operator PFN_vkDestroyOpticalFlowSessionNV()const noexcept { return vkDestroyOpticalFlowSessionNV;};
#endif
#if defined(VK_EXT_opacity_micromap) 
operator PFN_vkCreateMicromapEXT()const noexcept { return vkCreateMicromapEXT;};
operator PFN_vkCopyMemoryToMicromapEXT()const noexcept { return vkCopyMemoryToMicromapEXT;};
operator PFN_vkBuildMicromapsEXT()const noexcept { return vkBuildMicromapsEXT;};
operator PFN_vkCmdCopyMicromapEXT()const noexcept { return vkCmdCopyMicromapEXT;};
operator PFN_vkGetMicromapBuildSizesEXT()const noexcept { return vkGetMicromapBuildSizesEXT;};
operator PFN_vkWriteMicromapsPropertiesEXT()const noexcept { return vkWriteMicromapsPropertiesEXT;};
operator PFN_vkCopyMicromapEXT()const noexcept { return vkCopyMicromapEXT;};
operator PFN_vkDestroyMicromapEXT()const noexcept { return vkDestroyMicromapEXT;};
operator PFN_vkCmdBuildMicromapsEXT()const noexcept { return vkCmdBuildMicromapsEXT;};
operator PFN_vkCopyMicromapToMemoryEXT()const noexcept { return vkCopyMicromapToMemoryEXT;};
operator PFN_vkCmdCopyMicromapToMemoryEXT()const noexcept { return vkCmdCopyMicromapToMemoryEXT;};
operator PFN_vkCmdCopyMemoryToMicromapEXT()const noexcept { return vkCmdCopyMemoryToMicromapEXT;};
operator PFN_vkCmdWriteMicromapsPropertiesEXT()const noexcept { return vkCmdWriteMicromapsPropertiesEXT;};
operator PFN_vkGetDeviceMicromapCompatibilityEXT()const noexcept { return vkGetDeviceMicromapCompatibilityEXT;};
#endif
#if defined(VK_KHR_get_memory_requirements2) 
operator PFN_vkGetBufferMemoryRequirements2KHR()const noexcept { return vkGetBufferMemoryRequirements2KHR;};
operator PFN_vkGetImageSparseMemoryRequirements2KHR()const noexcept { return vkGetImageSparseMemoryRequirements2KHR;};
operator PFN_vkGetImageMemoryRequirements2KHR()const noexcept { return vkGetImageMemoryRequirements2KHR;};
#endif
#if defined(VK_FUCHSIA_buffer_collection) 
operator PFN_vkGetBufferCollectionPropertiesFUCHSIA()const noexcept { return vkGetBufferCollectionPropertiesFUCHSIA;};
operator PFN_vkDestroyBufferCollectionFUCHSIA()const noexcept { return vkDestroyBufferCollectionFUCHSIA;};
operator PFN_vkCreateBufferCollectionFUCHSIA()const noexcept { return vkCreateBufferCollectionFUCHSIA;};
operator PFN_vkSetBufferCollectionImageConstraintsFUCHSIA()const noexcept { return vkSetBufferCollectionImageConstraintsFUCHSIA;};
operator PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA()const noexcept { return vkSetBufferCollectionBufferConstraintsFUCHSIA;};
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2) 
operator PFN_vkImportFenceSciSyncObjNV()const noexcept { return vkImportFenceSciSyncObjNV;};
operator PFN_vkGetFenceSciSyncFenceNV()const noexcept { return vkGetFenceSciSyncFenceNV;};
operator PFN_vkImportFenceSciSyncFenceNV()const noexcept { return vkImportFenceSciSyncFenceNV;};
operator PFN_vkGetFenceSciSyncObjNV()const noexcept { return vkGetFenceSciSyncObjNV;};
#endif
#if defined(VK_KHR_map_memory2) 
operator PFN_vkUnmapMemory2KHR()const noexcept { return vkUnmapMemory2KHR;};
operator PFN_vkMapMemory2KHR()const noexcept { return vkMapMemory2KHR;};
#endif
#if defined(VK_AMD_shader_info) 
operator PFN_vkGetShaderInfoAMD()const noexcept { return vkGetShaderInfoAMD;};
#endif
#if defined(VK_KHR_deferred_host_operations) 
operator PFN_vkGetDeferredOperationMaxConcurrencyKHR()const noexcept { return vkGetDeferredOperationMaxConcurrencyKHR;};
operator PFN_vkGetDeferredOperationResultKHR()const noexcept { return vkGetDeferredOperationResultKHR;};
operator PFN_vkCreateDeferredOperationKHR()const noexcept { return vkCreateDeferredOperationKHR;};
operator PFN_vkDestroyDeferredOperationKHR()const noexcept { return vkDestroyDeferredOperationKHR;};
operator PFN_vkDeferredOperationJoinKHR()const noexcept { return vkDeferredOperationJoinKHR;};
#endif
#if defined(VK_NV_fragment_shading_rate_enums) 
operator PFN_vkCmdSetFragmentShadingRateEnumNV()const noexcept { return vkCmdSetFragmentShadingRateEnumNV;};
#endif
#if defined(VK_NV_ray_tracing) 
operator PFN_vkCompileDeferredNV()const noexcept { return vkCompileDeferredNV;};
operator PFN_vkGetAccelerationStructureHandleNV()const noexcept { return vkGetAccelerationStructureHandleNV;};
operator PFN_vkGetRayTracingShaderGroupHandlesNV()const noexcept { return vkGetRayTracingShaderGroupHandlesNV;};
operator PFN_vkCmdTraceRaysNV()const noexcept { return vkCmdTraceRaysNV;};
operator PFN_vkCmdWriteAccelerationStructuresPropertiesNV()const noexcept { return vkCmdWriteAccelerationStructuresPropertiesNV;};
operator PFN_vkCreateAccelerationStructureNV()const noexcept { return vkCreateAccelerationStructureNV;};
operator PFN_vkDestroyAccelerationStructureNV()const noexcept { return vkDestroyAccelerationStructureNV;};
operator PFN_vkGetAccelerationStructureMemoryRequirementsNV()const noexcept { return vkGetAccelerationStructureMemoryRequirementsNV;};
operator PFN_vkBindAccelerationStructureMemoryNV()const noexcept { return vkBindAccelerationStructureMemoryNV;};
operator PFN_vkCmdBuildAccelerationStructureNV()const noexcept { return vkCmdBuildAccelerationStructureNV;};
operator PFN_vkCmdCopyAccelerationStructureNV()const noexcept { return vkCmdCopyAccelerationStructureNV;};
operator PFN_vkCreateRayTracingPipelinesNV()const noexcept { return vkCreateRayTracingPipelinesNV;};
#endif
#if defined(VK_KHR_synchronization2) 
operator PFN_vkCmdResetEvent2KHR()const noexcept { return vkCmdResetEvent2KHR;};
operator PFN_vkCmdWaitEvents2KHR()const noexcept { return vkCmdWaitEvents2KHR;};
operator PFN_vkCmdSetEvent2KHR()const noexcept { return vkCmdSetEvent2KHR;};
operator PFN_vkCmdWriteTimestamp2KHR()const noexcept { return vkCmdWriteTimestamp2KHR;};
operator PFN_vkCmdPipelineBarrier2KHR()const noexcept { return vkCmdPipelineBarrier2KHR;};
operator PFN_vkQueueSubmit2KHR()const noexcept { return vkQueueSubmit2KHR;};
operator PFN_vkCmdWriteBufferMarker2AMD()const noexcept { return vkCmdWriteBufferMarker2AMD;};
operator PFN_vkGetQueueCheckpointData2NV()const noexcept { return vkGetQueueCheckpointData2NV;};
#endif
#if defined(VK_KHR_video_queue) 
operator PFN_vkCreateVideoSessionParametersKHR()const noexcept { return vkCreateVideoSessionParametersKHR;};
operator PFN_vkCreateVideoSessionKHR()const noexcept { return vkCreateVideoSessionKHR;};
operator PFN_vkBindVideoSessionMemoryKHR()const noexcept { return vkBindVideoSessionMemoryKHR;};
operator PFN_vkUpdateVideoSessionParametersKHR()const noexcept { return vkUpdateVideoSessionParametersKHR;};
operator PFN_vkDestroyVideoSessionKHR()const noexcept { return vkDestroyVideoSessionKHR;};
operator PFN_vkGetVideoSessionMemoryRequirementsKHR()const noexcept { return vkGetVideoSessionMemoryRequirementsKHR;};
operator PFN_vkDestroyVideoSessionParametersKHR()const noexcept { return vkDestroyVideoSessionParametersKHR;};
operator PFN_vkCmdBeginVideoCodingKHR()const noexcept { return vkCmdBeginVideoCodingKHR;};
operator PFN_vkCmdEndVideoCodingKHR()const noexcept { return vkCmdEndVideoCodingKHR;};
operator PFN_vkCmdControlVideoCodingKHR()const noexcept { return vkCmdControlVideoCodingKHR;};
#endif
#if defined(VK_KHR_push_descriptor) || defined(VK_KHR_push_descriptor) || defined(VK_KHR_descriptor_update_template) 
operator PFN_vkCmdPushDescriptorSetWithTemplateKHR()const noexcept { return vkCmdPushDescriptorSetWithTemplateKHR;};
#endif
#if defined(VK_KHR_descriptor_update_template) 
operator PFN_vkUpdateDescriptorSetWithTemplateKHR()const noexcept { return vkUpdateDescriptorSetWithTemplateKHR;};
operator PFN_vkCreateDescriptorUpdateTemplateKHR()const noexcept { return vkCreateDescriptorUpdateTemplateKHR;};
operator PFN_vkDestroyDescriptorUpdateTemplateKHR()const noexcept { return vkDestroyDescriptorUpdateTemplateKHR;};
#endif
#if defined(VK_KHR_push_descriptor) 
operator PFN_vkCmdPushDescriptorSetKHR()const noexcept { return vkCmdPushDescriptorSetKHR;};
#endif
#if defined(VK_NVX_binary_import) 
operator PFN_vkCreateCuFunctionNVX()const noexcept { return vkCreateCuFunctionNVX;};
operator PFN_vkCreateCuModuleNVX()const noexcept { return vkCreateCuModuleNVX;};
operator PFN_vkDestroyCuModuleNVX()const noexcept { return vkDestroyCuModuleNVX;};
operator PFN_vkDestroyCuFunctionNVX()const noexcept { return vkDestroyCuFunctionNVX;};
operator PFN_vkCmdCuLaunchKernelNVX()const noexcept { return vkCmdCuLaunchKernelNVX;};
#endif
#if defined(VK_NV_shading_rate_image) 
operator PFN_vkCmdSetViewportShadingRatePaletteNV()const noexcept { return vkCmdSetViewportShadingRatePaletteNV;};
operator PFN_vkCmdSetCoarseSampleOrderNV()const noexcept { return vkCmdSetCoarseSampleOrderNV;};
operator PFN_vkCmdBindShadingRateImageNV()const noexcept { return vkCmdBindShadingRateImageNV;};
#endif
#if defined(VK_KHR_buffer_device_address) 
operator PFN_vkGetBufferDeviceAddressKHR()const noexcept { return vkGetBufferDeviceAddressKHR;};
operator PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR()const noexcept { return vkGetDeviceMemoryOpaqueCaptureAddressKHR;};
operator PFN_vkGetBufferOpaqueCaptureAddressKHR()const noexcept { return vkGetBufferOpaqueCaptureAddressKHR;};
#endif
#if defined(VK_VERSION_1_3) 
operator PFN_vkCmdWriteTimestamp2()const noexcept { return vkCmdWriteTimestamp2;};
operator PFN_vkCmdSetDepthCompareOp()const noexcept { return vkCmdSetDepthCompareOp;};
operator PFN_vkCmdSetPrimitiveTopology()const noexcept { return vkCmdSetPrimitiveTopology;};
operator PFN_vkGetDeviceBufferMemoryRequirements()const noexcept { return vkGetDeviceBufferMemoryRequirements;};
operator PFN_vkCmdPipelineBarrier2()const noexcept { return vkCmdPipelineBarrier2;};
operator PFN_vkCmdSetDepthWriteEnable()const noexcept { return vkCmdSetDepthWriteEnable;};
operator PFN_vkCmdSetViewportWithCount()const noexcept { return vkCmdSetViewportWithCount;};
operator PFN_vkCreatePrivateDataSlot()const noexcept { return vkCreatePrivateDataSlot;};
operator PFN_vkDestroyPrivateDataSlot()const noexcept { return vkDestroyPrivateDataSlot;};
operator PFN_vkSetPrivateData()const noexcept { return vkSetPrivateData;};
operator PFN_vkGetPrivateData()const noexcept { return vkGetPrivateData;};
operator PFN_vkCmdSetEvent2()const noexcept { return vkCmdSetEvent2;};
operator PFN_vkCmdResetEvent2()const noexcept { return vkCmdResetEvent2;};
operator PFN_vkCmdWaitEvents2()const noexcept { return vkCmdWaitEvents2;};
operator PFN_vkQueueSubmit2()const noexcept { return vkQueueSubmit2;};
operator PFN_vkCmdCopyBuffer2()const noexcept { return vkCmdCopyBuffer2;};
operator PFN_vkCmdCopyImage2()const noexcept { return vkCmdCopyImage2;};
operator PFN_vkCmdCopyBufferToImage2()const noexcept { return vkCmdCopyBufferToImage2;};
operator PFN_vkCmdCopyImageToBuffer2()const noexcept { return vkCmdCopyImageToBuffer2;};
operator PFN_vkCmdBlitImage2()const noexcept { return vkCmdBlitImage2;};
operator PFN_vkCmdResolveImage2()const noexcept { return vkCmdResolveImage2;};
operator PFN_vkCmdBeginRendering()const noexcept { return vkCmdBeginRendering;};
operator PFN_vkCmdEndRendering()const noexcept { return vkCmdEndRendering;};
operator PFN_vkCmdSetCullMode()const noexcept { return vkCmdSetCullMode;};
operator PFN_vkCmdSetFrontFace()const noexcept { return vkCmdSetFrontFace;};
operator PFN_vkCmdSetScissorWithCount()const noexcept { return vkCmdSetScissorWithCount;};
operator PFN_vkCmdBindVertexBuffers2()const noexcept { return vkCmdBindVertexBuffers2;};
operator PFN_vkCmdSetDepthTestEnable()const noexcept { return vkCmdSetDepthTestEnable;};
operator PFN_vkCmdSetDepthBoundsTestEnable()const noexcept { return vkCmdSetDepthBoundsTestEnable;};
operator PFN_vkCmdSetStencilTestEnable()const noexcept { return vkCmdSetStencilTestEnable;};
operator PFN_vkCmdSetStencilOp()const noexcept { return vkCmdSetStencilOp;};
operator PFN_vkCmdSetRasterizerDiscardEnable()const noexcept { return vkCmdSetRasterizerDiscardEnable;};
operator PFN_vkCmdSetDepthBiasEnable()const noexcept { return vkCmdSetDepthBiasEnable;};
operator PFN_vkCmdSetPrimitiveRestartEnable()const noexcept { return vkCmdSetPrimitiveRestartEnable;};
operator PFN_vkGetDeviceImageMemoryRequirements()const noexcept { return vkGetDeviceImageMemoryRequirements;};
operator PFN_vkGetDeviceImageSparseMemoryRequirements()const noexcept { return vkGetDeviceImageSparseMemoryRequirements;};
#endif
#if defined(VK_KHR_ray_tracing_pipeline) 
operator PFN_vkCmdTraceRaysIndirectKHR()const noexcept { return vkCmdTraceRaysIndirectKHR;};
operator PFN_vkCmdSetRayTracingPipelineStackSizeKHR()const noexcept { return vkCmdSetRayTracingPipelineStackSizeKHR;};
operator PFN_vkGetRayTracingShaderGroupHandlesKHR()const noexcept { return vkGetRayTracingShaderGroupHandlesKHR;};
operator PFN_vkGetRayTracingShaderGroupStackSizeKHR()const noexcept { return vkGetRayTracingShaderGroupStackSizeKHR;};
operator PFN_vkCmdTraceRaysKHR()const noexcept { return vkCmdTraceRaysKHR;};
operator PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR()const noexcept { return vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;};
operator PFN_vkCreateRayTracingPipelinesKHR()const noexcept { return vkCreateRayTracingPipelinesKHR;};
#endif
#if defined(VK_VERSION_1_2) 
operator PFN_vkResetQueryPool()const noexcept { return vkResetQueryPool;};
operator PFN_vkGetDeviceMemoryOpaqueCaptureAddress()const noexcept { return vkGetDeviceMemoryOpaqueCaptureAddress;};
operator PFN_vkCmdBeginRenderPass2()const noexcept { return vkCmdBeginRenderPass2;};
operator PFN_vkCmdDrawIndirectCount()const noexcept { return vkCmdDrawIndirectCount;};
operator PFN_vkCmdDrawIndexedIndirectCount()const noexcept { return vkCmdDrawIndexedIndirectCount;};
operator PFN_vkCreateRenderPass2()const noexcept { return vkCreateRenderPass2;};
operator PFN_vkCmdNextSubpass2()const noexcept { return vkCmdNextSubpass2;};
operator PFN_vkWaitSemaphores()const noexcept { return vkWaitSemaphores;};
operator PFN_vkCmdEndRenderPass2()const noexcept { return vkCmdEndRenderPass2;};
operator PFN_vkGetSemaphoreCounterValue()const noexcept { return vkGetSemaphoreCounterValue;};
operator PFN_vkSignalSemaphore()const noexcept { return vkSignalSemaphore;};
operator PFN_vkGetBufferDeviceAddress()const noexcept { return vkGetBufferDeviceAddress;};
operator PFN_vkGetBufferOpaqueCaptureAddress()const noexcept { return vkGetBufferOpaqueCaptureAddress;};
#endif
#if defined(VK_NV_device_generated_commands) 
operator PFN_vkCmdPreprocessGeneratedCommandsNV()const noexcept { return vkCmdPreprocessGeneratedCommandsNV;};
operator PFN_vkCmdBindPipelineShaderGroupNV()const noexcept { return vkCmdBindPipelineShaderGroupNV;};
operator PFN_vkDestroyIndirectCommandsLayoutNV()const noexcept { return vkDestroyIndirectCommandsLayoutNV;};
operator PFN_vkGetGeneratedCommandsMemoryRequirementsNV()const noexcept { return vkGetGeneratedCommandsMemoryRequirementsNV;};
operator PFN_vkCreateIndirectCommandsLayoutNV()const noexcept { return vkCreateIndirectCommandsLayoutNV;};
operator PFN_vkCmdExecuteGeneratedCommandsNV()const noexcept { return vkCmdExecuteGeneratedCommandsNV;};
#endif
#if defined(VK_EXT_pipeline_properties) 
operator PFN_vkGetPipelinePropertiesEXT()const noexcept { return vkGetPipelinePropertiesEXT;};
#endif
#if defined(VK_EXT_shader_module_identifier) 
operator PFN_vkGetShaderModuleIdentifierEXT()const noexcept { return vkGetShaderModuleIdentifierEXT;};
operator PFN_vkGetShaderModuleCreateInfoIdentifierEXT()const noexcept { return vkGetShaderModuleCreateInfoIdentifierEXT;};
#endif
#if defined(VK_NV_clip_space_w_scaling) 
operator PFN_vkCmdSetViewportWScalingNV()const noexcept { return vkCmdSetViewportWScalingNV;};
#endif
#if defined(VK_HUAWEI_subpass_shading) 
operator PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI()const noexcept { return vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI;};
operator PFN_vkCmdSubpassShadingHUAWEI()const noexcept { return vkCmdSubpassShadingHUAWEI;};
#endif
#if defined(VK_INTEL_performance_query) 
operator PFN_vkCmdSetPerformanceStreamMarkerINTEL()const noexcept { return vkCmdSetPerformanceStreamMarkerINTEL;};
operator PFN_vkReleasePerformanceConfigurationINTEL()const noexcept { return vkReleasePerformanceConfigurationINTEL;};
operator PFN_vkInitializePerformanceApiINTEL()const noexcept { return vkInitializePerformanceApiINTEL;};
operator PFN_vkUninitializePerformanceApiINTEL()const noexcept { return vkUninitializePerformanceApiINTEL;};
operator PFN_vkCmdSetPerformanceMarkerINTEL()const noexcept { return vkCmdSetPerformanceMarkerINTEL;};
operator PFN_vkCmdSetPerformanceOverrideINTEL()const noexcept { return vkCmdSetPerformanceOverrideINTEL;};
operator PFN_vkAcquirePerformanceConfigurationINTEL()const noexcept { return vkAcquirePerformanceConfigurationINTEL;};
operator PFN_vkQueueSetPerformanceConfigurationINTEL()const noexcept { return vkQueueSetPerformanceConfigurationINTEL;};
operator PFN_vkGetPerformanceParameterINTEL()const noexcept { return vkGetPerformanceParameterINTEL;};
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state3) 
operator PFN_vkCmdSetAlphaToCoverageEnableEXT()const noexcept { return vkCmdSetAlphaToCoverageEnableEXT;};
operator PFN_vkCmdSetCoverageModulationModeNV()const noexcept { return vkCmdSetCoverageModulationModeNV;};
operator PFN_vkCmdSetSampleMaskEXT()const noexcept { return vkCmdSetSampleMaskEXT;};
operator PFN_vkCmdSetColorBlendEnableEXT()const noexcept { return vkCmdSetColorBlendEnableEXT;};
operator PFN_vkCmdSetCoverageToColorLocationNV()const noexcept { return vkCmdSetCoverageToColorLocationNV;};
operator PFN_vkCmdSetCoverageModulationTableNV()const noexcept { return vkCmdSetCoverageModulationTableNV;};
operator PFN_vkCmdSetProvokingVertexModeEXT()const noexcept { return vkCmdSetProvokingVertexModeEXT;};
operator PFN_vkCmdSetColorWriteMaskEXT()const noexcept { return vkCmdSetColorWriteMaskEXT;};
operator PFN_vkCmdSetSampleLocationsEnableEXT()const noexcept { return vkCmdSetSampleLocationsEnableEXT;};
operator PFN_vkCmdSetAlphaToOneEnableEXT()const noexcept { return vkCmdSetAlphaToOneEnableEXT;};
operator PFN_vkCmdSetDepthClipNegativeOneToOneEXT()const noexcept { return vkCmdSetDepthClipNegativeOneToOneEXT;};
operator PFN_vkCmdSetTessellationDomainOriginEXT()const noexcept { return vkCmdSetTessellationDomainOriginEXT;};
operator PFN_vkCmdSetDepthClampEnableEXT()const noexcept { return vkCmdSetDepthClampEnableEXT;};
operator PFN_vkCmdSetPolygonModeEXT()const noexcept { return vkCmdSetPolygonModeEXT;};
operator PFN_vkCmdSetRasterizationSamplesEXT()const noexcept { return vkCmdSetRasterizationSamplesEXT;};
operator PFN_vkCmdSetLogicOpEnableEXT()const noexcept { return vkCmdSetLogicOpEnableEXT;};
operator PFN_vkCmdSetColorBlendEquationEXT()const noexcept { return vkCmdSetColorBlendEquationEXT;};
operator PFN_vkCmdSetRasterizationStreamEXT()const noexcept { return vkCmdSetRasterizationStreamEXT;};
operator PFN_vkCmdSetConservativeRasterizationModeEXT()const noexcept { return vkCmdSetConservativeRasterizationModeEXT;};
operator PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT()const noexcept { return vkCmdSetExtraPrimitiveOverestimationSizeEXT;};
operator PFN_vkCmdSetDepthClipEnableEXT()const noexcept { return vkCmdSetDepthClipEnableEXT;};
operator PFN_vkCmdSetColorBlendAdvancedEXT()const noexcept { return vkCmdSetColorBlendAdvancedEXT;};
operator PFN_vkCmdSetLineRasterizationModeEXT()const noexcept { return vkCmdSetLineRasterizationModeEXT;};
operator PFN_vkCmdSetLineStippleEnableEXT()const noexcept { return vkCmdSetLineStippleEnableEXT;};
operator PFN_vkCmdSetViewportWScalingEnableNV()const noexcept { return vkCmdSetViewportWScalingEnableNV;};
operator PFN_vkCmdSetViewportSwizzleNV()const noexcept { return vkCmdSetViewportSwizzleNV;};
operator PFN_vkCmdSetCoverageToColorEnableNV()const noexcept { return vkCmdSetCoverageToColorEnableNV;};
operator PFN_vkCmdSetCoverageModulationTableEnableNV()const noexcept { return vkCmdSetCoverageModulationTableEnableNV;};
operator PFN_vkCmdSetShadingRateImageEnableNV()const noexcept { return vkCmdSetShadingRateImageEnableNV;};
operator PFN_vkCmdSetRepresentativeFragmentTestEnableNV()const noexcept { return vkCmdSetRepresentativeFragmentTestEnableNV;};
operator PFN_vkCmdSetCoverageReductionModeNV()const noexcept { return vkCmdSetCoverageReductionModeNV;};
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state) 
operator PFN_vkCmdSetStencilTestEnableEXT()const noexcept { return vkCmdSetStencilTestEnableEXT;};
operator PFN_vkCmdSetDepthTestEnableEXT()const noexcept { return vkCmdSetDepthTestEnableEXT;};
operator PFN_vkCmdSetCullModeEXT()const noexcept { return vkCmdSetCullModeEXT;};
operator PFN_vkCmdSetFrontFaceEXT()const noexcept { return vkCmdSetFrontFaceEXT;};
operator PFN_vkCmdSetPrimitiveTopologyEXT()const noexcept { return vkCmdSetPrimitiveTopologyEXT;};
operator PFN_vkCmdSetViewportWithCountEXT()const noexcept { return vkCmdSetViewportWithCountEXT;};
operator PFN_vkCmdSetScissorWithCountEXT()const noexcept { return vkCmdSetScissorWithCountEXT;};
operator PFN_vkCmdBindVertexBuffers2EXT()const noexcept { return vkCmdBindVertexBuffers2EXT;};
operator PFN_vkCmdSetDepthWriteEnableEXT()const noexcept { return vkCmdSetDepthWriteEnableEXT;};
operator PFN_vkCmdSetDepthCompareOpEXT()const noexcept { return vkCmdSetDepthCompareOpEXT;};
operator PFN_vkCmdSetDepthBoundsTestEnableEXT()const noexcept { return vkCmdSetDepthBoundsTestEnableEXT;};
operator PFN_vkCmdSetStencilOpEXT()const noexcept { return vkCmdSetStencilOpEXT;};
#endif
#if defined(VK_EXT_multi_draw) 
operator PFN_vkCmdDrawMultiEXT()const noexcept { return vkCmdDrawMultiEXT;};
operator PFN_vkCmdDrawMultiIndexedEXT()const noexcept { return vkCmdDrawMultiIndexedEXT;};
#endif
#if defined(VK_NV_external_memory_rdma) 
operator PFN_vkGetMemoryRemoteAddressNV()const noexcept { return vkGetMemoryRemoteAddressNV;};
#endif
#if defined(VK_EXT_shader_object) 
operator PFN_vkCreateShadersEXT()const noexcept { return vkCreateShadersEXT;};
operator PFN_vkDestroyShaderEXT()const noexcept { return vkDestroyShaderEXT;};
operator PFN_vkGetShaderBinaryDataEXT()const noexcept { return vkGetShaderBinaryDataEXT;};
operator PFN_vkCmdBindShadersEXT()const noexcept { return vkCmdBindShadersEXT;};
#endif
#if defined(VK_KHR_bind_memory2) 
operator PFN_vkBindBufferMemory2KHR()const noexcept { return vkBindBufferMemory2KHR;};
operator PFN_vkBindImageMemory2KHR()const noexcept { return vkBindImageMemory2KHR;};
#endif
#if defined(VK_EXT_debug_utils) 
operator PFN_vkQueueEndDebugUtilsLabelEXT()const noexcept { return vkQueueEndDebugUtilsLabelEXT;};
operator PFN_vkQueueBeginDebugUtilsLabelEXT()const noexcept { return vkQueueBeginDebugUtilsLabelEXT;};
operator PFN_vkCmdBeginDebugUtilsLabelEXT()const noexcept { return vkCmdBeginDebugUtilsLabelEXT;};
operator PFN_vkSetDebugUtilsObjectNameEXT()const noexcept { return vkSetDebugUtilsObjectNameEXT;};
operator PFN_vkQueueInsertDebugUtilsLabelEXT()const noexcept { return vkQueueInsertDebugUtilsLabelEXT;};
operator PFN_vkSetDebugUtilsObjectTagEXT()const noexcept { return vkSetDebugUtilsObjectTagEXT;};
operator PFN_vkCmdEndDebugUtilsLabelEXT()const noexcept { return vkCmdEndDebugUtilsLabelEXT;};
operator PFN_vkCmdInsertDebugUtilsLabelEXT()const noexcept { return vkCmdInsertDebugUtilsLabelEXT;};
#endif
#if defined(VK_NV_low_latency2) 
operator PFN_vkQueueNotifyOutOfBandNV()const noexcept { return vkQueueNotifyOutOfBandNV;};
operator PFN_vkSetLatencySleepModeNV()const noexcept { return vkSetLatencySleepModeNV;};
operator PFN_vkLatencySleepNV()const noexcept { return vkLatencySleepNV;};
operator PFN_vkSetLatencyMarkerNV()const noexcept { return vkSetLatencyMarkerNV;};
operator PFN_vkGetLatencyTimingsNV()const noexcept { return vkGetLatencyTimingsNV;};
#endif
#if defined(VK_EXT_display_control) 
operator PFN_vkRegisterDeviceEventEXT()const noexcept { return vkRegisterDeviceEventEXT;};
operator PFN_vkRegisterDisplayEventEXT()const noexcept { return vkRegisterDisplayEventEXT;};
operator PFN_vkDisplayPowerControlEXT()const noexcept { return vkDisplayPowerControlEXT;};
operator PFN_vkGetSwapchainCounterEXT()const noexcept { return vkGetSwapchainCounterEXT;};
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) 
operator PFN_vkDestroySamplerYcbcrConversionKHR()const noexcept { return vkDestroySamplerYcbcrConversionKHR;};
operator PFN_vkCreateSamplerYcbcrConversionKHR()const noexcept { return vkCreateSamplerYcbcrConversionKHR;};
#endif
#if defined(VK_KHR_pipeline_executable_properties) 
operator PFN_vkGetPipelineExecutableStatisticsKHR()const noexcept { return vkGetPipelineExecutableStatisticsKHR;};
operator PFN_vkGetPipelineExecutableInternalRepresentationsKHR()const noexcept { return vkGetPipelineExecutableInternalRepresentationsKHR;};
operator PFN_vkGetPipelineExecutablePropertiesKHR()const noexcept { return vkGetPipelineExecutablePropertiesKHR;};
#endif
#if defined(VK_AMDX_shader_enqueue) 
operator PFN_vkCreateExecutionGraphPipelinesAMDX()const noexcept { return vkCreateExecutionGraphPipelinesAMDX;};
operator PFN_vkGetExecutionGraphPipelineNodeIndexAMDX()const noexcept { return vkGetExecutionGraphPipelineNodeIndexAMDX;};
operator PFN_vkCmdDispatchGraphIndirectCountAMDX()const noexcept { return vkCmdDispatchGraphIndirectCountAMDX;};
operator PFN_vkGetExecutionGraphPipelineScratchSizeAMDX()const noexcept { return vkGetExecutionGraphPipelineScratchSizeAMDX;};
operator PFN_vkCmdDispatchGraphAMDX()const noexcept { return vkCmdDispatchGraphAMDX;};
operator PFN_vkCmdInitializeGraphScratchMemoryAMDX()const noexcept { return vkCmdInitializeGraphScratchMemoryAMDX;};
operator PFN_vkCmdDispatchGraphIndirectAMDX()const noexcept { return vkCmdDispatchGraphIndirectAMDX;};
#endif
#if defined(VK_KHR_acceleration_structure) 
operator PFN_vkCopyAccelerationStructureToMemoryKHR()const noexcept { return vkCopyAccelerationStructureToMemoryKHR;};
operator PFN_vkCopyAccelerationStructureKHR()const noexcept { return vkCopyAccelerationStructureKHR;};
operator PFN_vkGetAccelerationStructureBuildSizesKHR()const noexcept { return vkGetAccelerationStructureBuildSizesKHR;};
operator PFN_vkWriteAccelerationStructuresPropertiesKHR()const noexcept { return vkWriteAccelerationStructuresPropertiesKHR;};
operator PFN_vkBuildAccelerationStructuresKHR()const noexcept { return vkBuildAccelerationStructuresKHR;};
operator PFN_vkCopyMemoryToAccelerationStructureKHR()const noexcept { return vkCopyMemoryToAccelerationStructureKHR;};
operator PFN_vkCmdCopyAccelerationStructureKHR()const noexcept { return vkCmdCopyAccelerationStructureKHR;};
operator PFN_vkCmdWriteAccelerationStructuresPropertiesKHR()const noexcept { return vkCmdWriteAccelerationStructuresPropertiesKHR;};
operator PFN_vkDestroyAccelerationStructureKHR()const noexcept { return vkDestroyAccelerationStructureKHR;};
operator PFN_vkGetDeviceAccelerationStructureCompatibilityKHR()const noexcept { return vkGetDeviceAccelerationStructureCompatibilityKHR;};
operator PFN_vkGetAccelerationStructureDeviceAddressKHR()const noexcept { return vkGetAccelerationStructureDeviceAddressKHR;};
operator PFN_vkCreateAccelerationStructureKHR()const noexcept { return vkCreateAccelerationStructureKHR;};
operator PFN_vkCmdBuildAccelerationStructuresKHR()const noexcept { return vkCmdBuildAccelerationStructuresKHR;};
operator PFN_vkCmdBuildAccelerationStructuresIndirectKHR()const noexcept { return vkCmdBuildAccelerationStructuresIndirectKHR;};
operator PFN_vkCmdCopyAccelerationStructureToMemoryKHR()const noexcept { return vkCmdCopyAccelerationStructureToMemoryKHR;};
operator PFN_vkCmdCopyMemoryToAccelerationStructureKHR()const noexcept { return vkCmdCopyMemoryToAccelerationStructureKHR;};
#endif
#if defined(VK_QNX_external_memory_screen_buffer) 
operator PFN_vkGetScreenBufferPropertiesQNX()const noexcept { return vkGetScreenBufferPropertiesQNX;};
#endif
#if defined(VK_NV_external_memory_win32) 
operator PFN_vkGetMemoryWin32HandleNV()const noexcept { return vkGetMemoryWin32HandleNV;};
#endif
#if defined(VK_NV_memory_decompression) 
operator PFN_vkCmdDecompressMemoryNV()const noexcept { return vkCmdDecompressMemoryNV;};
operator PFN_vkCmdDecompressMemoryIndirectCountNV()const noexcept { return vkCmdDecompressMemoryIndirectCountNV;};
#endif
#if defined(VK_KHR_dynamic_rendering) 
operator PFN_vkCmdEndRenderingKHR()const noexcept { return vkCmdEndRenderingKHR;};
operator PFN_vkCmdBeginRenderingKHR()const noexcept { return vkCmdBeginRenderingKHR;};
#endif
#if defined(VK_EXT_pageable_device_local_memory) 
operator PFN_vkSetDeviceMemoryPriorityEXT()const noexcept { return vkSetDeviceMemoryPriorityEXT;};
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) 
operator PFN_vkGetAndroidHardwareBufferPropertiesANDROID()const noexcept { return vkGetAndroidHardwareBufferPropertiesANDROID;};
operator PFN_vkGetMemoryAndroidHardwareBufferANDROID()const noexcept { return vkGetMemoryAndroidHardwareBufferANDROID;};
#endif
#if defined(VK_EXT_host_image_copy) 
operator PFN_vkCopyMemoryToImageEXT()const noexcept { return vkCopyMemoryToImageEXT;};
operator PFN_vkCopyImageToMemoryEXT()const noexcept { return vkCopyImageToMemoryEXT;};
operator PFN_vkCopyImageToImageEXT()const noexcept { return vkCopyImageToImageEXT;};
operator PFN_vkTransitionImageLayoutEXT()const noexcept { return vkTransitionImageLayoutEXT;};
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2) 
operator PFN_vkCmdSetPrimitiveRestartEnableEXT()const noexcept { return vkCmdSetPrimitiveRestartEnableEXT;};
operator PFN_vkCmdSetRasterizerDiscardEnableEXT()const noexcept { return vkCmdSetRasterizerDiscardEnableEXT;};
operator PFN_vkCmdSetPatchControlPointsEXT()const noexcept { return vkCmdSetPatchControlPointsEXT;};
operator PFN_vkCmdSetDepthBiasEnableEXT()const noexcept { return vkCmdSetDepthBiasEnableEXT;};
operator PFN_vkCmdSetLogicOpEXT()const noexcept { return vkCmdSetLogicOpEXT;};
#endif
#if defined(VK_EXT_external_memory_host) 
operator PFN_vkGetMemoryHostPointerPropertiesEXT()const noexcept { return vkGetMemoryHostPointerPropertiesEXT;};
#endif
#if defined(VK_KHR_external_semaphore_fd) 
operator PFN_vkImportSemaphoreFdKHR()const noexcept { return vkImportSemaphoreFdKHR;};
operator PFN_vkGetSemaphoreFdKHR()const noexcept { return vkGetSemaphoreFdKHR;};
#endif
#if defined(VK_KHR_performance_query) 
operator PFN_vkReleaseProfilingLockKHR()const noexcept { return vkReleaseProfilingLockKHR;};
operator PFN_vkAcquireProfilingLockKHR()const noexcept { return vkAcquireProfilingLockKHR;};
#endif
#if defined(VK_HUAWEI_cluster_culling_shader) 
operator PFN_vkCmdDrawClusterIndirectHUAWEI()const noexcept { return vkCmdDrawClusterIndirectHUAWEI;};
operator PFN_vkCmdDrawClusterHUAWEI()const noexcept { return vkCmdDrawClusterHUAWEI;};
#endif
#if defined(VK_NV_external_memory_sci_buf) 
operator PFN_vkGetMemorySciBufNV()const noexcept { return vkGetMemorySciBufNV;};
#endif
#if defined(VK_KHR_external_memory_win32) 
operator PFN_vkGetMemoryWin32HandleKHR()const noexcept { return vkGetMemoryWin32HandleKHR;};
operator PFN_vkGetMemoryWin32HandlePropertiesKHR()const noexcept { return vkGetMemoryWin32HandlePropertiesKHR;};
#endif
#if defined(VK_EXT_mesh_shader) 
operator PFN_vkCmdDrawMeshTasksEXT()const noexcept { return vkCmdDrawMeshTasksEXT;};
operator PFN_vkCmdDrawMeshTasksIndirectEXT()const noexcept { return vkCmdDrawMeshTasksIndirectEXT;};
operator PFN_vkCmdDrawMeshTasksIndirectCountEXT()const noexcept { return vkCmdDrawMeshTasksIndirectCountEXT;};
#endif
#if defined(VK_EXT_full_screen_exclusive) 
operator PFN_vkReleaseFullScreenExclusiveModeEXT()const noexcept { return vkReleaseFullScreenExclusiveModeEXT;};
operator PFN_vkAcquireFullScreenExclusiveModeEXT()const noexcept { return vkAcquireFullScreenExclusiveModeEXT;};
#endif
#if defined(VK_EXT_private_data) 
operator PFN_vkSetPrivateDataEXT()const noexcept { return vkSetPrivateDataEXT;};
operator PFN_vkDestroyPrivateDataSlotEXT()const noexcept { return vkDestroyPrivateDataSlotEXT;};
operator PFN_vkCreatePrivateDataSlotEXT()const noexcept { return vkCreatePrivateDataSlotEXT;};
operator PFN_vkGetPrivateDataEXT()const noexcept { return vkGetPrivateDataEXT;};
#endif
#if defined(VK_HUAWEI_invocation_mask) 
operator PFN_vkCmdBindInvocationMaskHUAWEI()const noexcept { return vkCmdBindInvocationMaskHUAWEI;};
#endif
#if defined(VK_QCOM_tile_properties) 
operator PFN_vkGetDynamicRenderingTilePropertiesQCOM()const noexcept { return vkGetDynamicRenderingTilePropertiesQCOM;};
operator PFN_vkGetFramebufferTilePropertiesQCOM()const noexcept { return vkGetFramebufferTilePropertiesQCOM;};
#endif
#if defined(VK_KHR_external_fence_win32) 
operator PFN_vkGetFenceWin32HandleKHR()const noexcept { return vkGetFenceWin32HandleKHR;};
operator PFN_vkImportFenceWin32HandleKHR()const noexcept { return vkImportFenceWin32HandleKHR;};
#endif
#if defined(VK_KHR_create_renderpass2) 
operator PFN_vkCmdBeginRenderPass2KHR()const noexcept { return vkCmdBeginRenderPass2KHR;};
operator PFN_vkCmdEndRenderPass2KHR()const noexcept { return vkCmdEndRenderPass2KHR;};
operator PFN_vkCmdNextSubpass2KHR()const noexcept { return vkCmdNextSubpass2KHR;};
operator PFN_vkCreateRenderPass2KHR()const noexcept { return vkCreateRenderPass2KHR;};
#endif
#if defined(VK_EXT_depth_bias_control) 
operator PFN_vkCmdSetDepthBias2EXT()const noexcept { return vkCmdSetDepthBias2EXT;};
#endif
#if defined(VK_KHR_copy_commands2) 
operator PFN_vkCmdCopyImageToBuffer2KHR()const noexcept { return vkCmdCopyImageToBuffer2KHR;};
operator PFN_vkCmdCopyBuffer2KHR()const noexcept { return vkCmdCopyBuffer2KHR;};
operator PFN_vkCmdCopyImage2KHR()const noexcept { return vkCmdCopyImage2KHR;};
operator PFN_vkCmdCopyBufferToImage2KHR()const noexcept { return vkCmdCopyBufferToImage2KHR;};
operator PFN_vkCmdBlitImage2KHR()const noexcept { return vkCmdBlitImage2KHR;};
operator PFN_vkCmdResolveImage2KHR()const noexcept { return vkCmdResolveImage2KHR;};
#endif
#if defined(VK_EXT_color_write_enable) 
operator PFN_vkCmdSetColorWriteEnableEXT()const noexcept { return vkCmdSetColorWriteEnableEXT;};
#endif
#if defined(VK_NVX_image_view_handle) 
operator PFN_vkGetImageViewAddressNVX()const noexcept { return vkGetImageViewAddressNVX;};
operator PFN_vkGetImageViewHandleNVX()const noexcept { return vkGetImageViewHandleNVX;};
#endif
#if defined(VK_KHR_video_encode_queue) 
operator PFN_vkGetEncodedVideoSessionParametersKHR()const noexcept { return vkGetEncodedVideoSessionParametersKHR;};
operator PFN_vkCmdEncodeVideoKHR()const noexcept { return vkCmdEncodeVideoKHR;};
#endif
#if defined(VK_EXT_host_query_reset) 
operator PFN_vkResetQueryPoolEXT()const noexcept { return vkResetQueryPoolEXT;};
#endif
#if defined(VK_ANDROID_native_buffer) 
operator PFN_vkGetSwapchainGrallocUsageANDROID()const noexcept { return vkGetSwapchainGrallocUsageANDROID;};
operator PFN_vkAcquireImageANDROID()const noexcept { return vkAcquireImageANDROID;};
operator PFN_vkQueueSignalReleaseImageANDROID()const noexcept { return vkQueueSignalReleaseImageANDROID;};
operator PFN_vkGetSwapchainGrallocUsage2ANDROID()const noexcept { return vkGetSwapchainGrallocUsage2ANDROID;};
#endif
#if defined(VK_NV_external_sci_sync) 
operator PFN_vkGetSemaphoreSciSyncObjNV()const noexcept { return vkGetSemaphoreSciSyncObjNV;};
operator PFN_vkImportSemaphoreSciSyncObjNV()const noexcept { return vkImportSemaphoreSciSyncObjNV;};
#endif
#if defined(VK_KHR_external_memory_fd) 
operator PFN_vkGetMemoryFdPropertiesKHR()const noexcept { return vkGetMemoryFdPropertiesKHR;};
operator PFN_vkGetMemoryFdKHR()const noexcept { return vkGetMemoryFdKHR;};
#endif
#if defined(VK_EXT_transform_feedback) 
operator PFN_vkCmdEndQueryIndexedEXT()const noexcept { return vkCmdEndQueryIndexedEXT;};
operator PFN_vkCmdDrawIndirectByteCountEXT()const noexcept { return vkCmdDrawIndirectByteCountEXT;};
operator PFN_vkCmdEndTransformFeedbackEXT()const noexcept { return vkCmdEndTransformFeedbackEXT;};
operator PFN_vkCmdBindTransformFeedbackBuffersEXT()const noexcept { return vkCmdBindTransformFeedbackBuffersEXT;};
operator PFN_vkCmdBeginTransformFeedbackEXT()const noexcept { return vkCmdBeginTransformFeedbackEXT;};
operator PFN_vkCmdBeginQueryIndexedEXT()const noexcept { return vkCmdBeginQueryIndexedEXT;};
#endif
#if defined(VK_NV_copy_memory_indirect) 
operator PFN_vkCmdCopyMemoryToImageIndirectNV()const noexcept { return vkCmdCopyMemoryToImageIndirectNV;};
operator PFN_vkCmdCopyMemoryIndirectNV()const noexcept { return vkCmdCopyMemoryIndirectNV;};
#endif
#if defined(VK_KHR_external_semaphore_win32) 
operator PFN_vkImportSemaphoreWin32HandleKHR()const noexcept { return vkImportSemaphoreWin32HandleKHR;};
operator PFN_vkGetSemaphoreWin32HandleKHR()const noexcept { return vkGetSemaphoreWin32HandleKHR;};
#endif
#if defined(VK_EXT_validation_cache) 
operator PFN_vkCreateValidationCacheEXT()const noexcept { return vkCreateValidationCacheEXT;};
operator PFN_vkGetValidationCacheDataEXT()const noexcept { return vkGetValidationCacheDataEXT;};
operator PFN_vkDestroyValidationCacheEXT()const noexcept { return vkDestroyValidationCacheEXT;};
operator PFN_vkMergeValidationCachesEXT()const noexcept { return vkMergeValidationCachesEXT;};
#endif
#if defined(VK_KHR_timeline_semaphore) 
operator PFN_vkWaitSemaphoresKHR()const noexcept { return vkWaitSemaphoresKHR;};
operator PFN_vkGetSemaphoreCounterValueKHR()const noexcept { return vkGetSemaphoreCounterValueKHR;};
operator PFN_vkSignalSemaphoreKHR()const noexcept { return vkSignalSemaphoreKHR;};
#endif
#if defined(VK_KHR_swapchain) 
operator PFN_vkQueuePresentKHR()const noexcept { return vkQueuePresentKHR;};
operator PFN_vkCreateSwapchainKHR()const noexcept { return vkCreateSwapchainKHR;};
operator PFN_vkDestroySwapchainKHR()const noexcept { return vkDestroySwapchainKHR;};
operator PFN_vkGetSwapchainImagesKHR()const noexcept { return vkGetSwapchainImagesKHR;};
operator PFN_vkAcquireNextImageKHR()const noexcept { return vkAcquireNextImageKHR;};
#endif
#if defined(VK_KHR_draw_indirect_count) 
operator PFN_vkCmdDrawIndirectCountKHR()const noexcept { return vkCmdDrawIndirectCountKHR;};
operator PFN_vkCmdDrawIndexedIndirectCountKHR()const noexcept { return vkCmdDrawIndexedIndirectCountKHR;};
#endif
#if defined(VK_KHR_ray_tracing_maintenance1) 
operator PFN_vkCmdTraceRaysIndirect2KHR()const noexcept { return vkCmdTraceRaysIndirect2KHR;};
#endif
#if defined(VK_KHR_fragment_shading_rate) 
operator PFN_vkCmdSetFragmentShadingRateKHR()const noexcept { return vkCmdSetFragmentShadingRateKHR;};
#endif
#if defined(VKSC_VERSION_1_0) 
operator PFN_vkGetCommandPoolMemoryConsumption()const noexcept { return vkGetCommandPoolMemoryConsumption;};
operator PFN_vkGetFaultData()const noexcept { return vkGetFaultData;};
#endif
#if defined(VK_KHR_maintenance5) 
operator PFN_vkGetDeviceImageSubresourceLayoutKHR()const noexcept { return vkGetDeviceImageSubresourceLayoutKHR;};
operator PFN_vkCmdBindIndexBuffer2KHR()const noexcept { return vkCmdBindIndexBuffer2KHR;};
operator PFN_vkGetRenderingAreaGranularityKHR()const noexcept { return vkGetRenderingAreaGranularityKHR;};
operator PFN_vkGetImageSubresourceLayout2KHR()const noexcept { return vkGetImageSubresourceLayout2KHR;};
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group) 
operator PFN_vkGetDeviceGroupPresentCapabilitiesKHR()const noexcept { return vkGetDeviceGroupPresentCapabilitiesKHR;};
operator PFN_vkGetDeviceGroupSurfacePresentModesKHR()const noexcept { return vkGetDeviceGroupSurfacePresentModesKHR;};
operator PFN_vkAcquireNextImage2KHR()const noexcept { return vkAcquireNextImage2KHR;};
#endif
#if defined(VK_KHR_display_swapchain) 
operator PFN_vkCreateSharedSwapchainsKHR()const noexcept { return vkCreateSharedSwapchainsKHR;};
#endif
#if defined(VK_KHR_maintenance3) 
operator PFN_vkGetDescriptorSetLayoutSupportKHR()const noexcept { return vkGetDescriptorSetLayoutSupportKHR;};
#endif
#if defined(VK_NV_device_generated_commands_compute) 
operator PFN_vkCmdUpdatePipelineIndirectBufferNV()const noexcept { return vkCmdUpdatePipelineIndirectBufferNV;};
operator PFN_vkGetPipelineIndirectDeviceAddressNV()const noexcept { return vkGetPipelineIndirectDeviceAddressNV;};
operator PFN_vkGetPipelineIndirectMemoryRequirementsNV()const noexcept { return vkGetPipelineIndirectMemoryRequirementsNV;};
#endif
#if defined(VK_EXT_conditional_rendering) 
operator PFN_vkCmdEndConditionalRenderingEXT()const noexcept { return vkCmdEndConditionalRenderingEXT;};
operator PFN_vkCmdBeginConditionalRenderingEXT()const noexcept { return vkCmdBeginConditionalRenderingEXT;};
#endif
#if defined(VK_KHR_video_decode_queue) 
operator PFN_vkCmdDecodeVideoKHR()const noexcept { return vkCmdDecodeVideoKHR;};
#endif
#if defined(VK_EXT_hdr_metadata) 
operator PFN_vkSetHdrMetadataEXT()const noexcept { return vkSetHdrMetadataEXT;};
#endif
#if defined(VK_KHR_maintenance4) 
operator PFN_vkGetDeviceBufferMemoryRequirementsKHR()const noexcept { return vkGetDeviceBufferMemoryRequirementsKHR;};
operator PFN_vkGetDeviceImageMemoryRequirementsKHR()const noexcept { return vkGetDeviceImageMemoryRequirementsKHR;};
operator PFN_vkGetDeviceImageSparseMemoryRequirementsKHR()const noexcept { return vkGetDeviceImageSparseMemoryRequirementsKHR;};
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_vertex_input_dynamic_state) 
operator PFN_vkCmdSetVertexInputEXT()const noexcept { return vkCmdSetVertexInputEXT;};
#endif
#if defined(VK_KHR_shared_presentable_image) 
operator PFN_vkGetSwapchainStatusKHR()const noexcept { return vkGetSwapchainStatusKHR;};
#endif
#if defined(VK_EXT_discard_rectangles) 
operator PFN_vkCmdSetDiscardRectangleEXT()const noexcept { return vkCmdSetDiscardRectangleEXT;};
operator PFN_vkCmdSetDiscardRectangleModeEXT()const noexcept { return vkCmdSetDiscardRectangleModeEXT;};
operator PFN_vkCmdSetDiscardRectangleEnableEXT()const noexcept { return vkCmdSetDiscardRectangleEnableEXT;};
#endif
#if defined(VK_EXT_host_image_copy) || defined(VK_EXT_image_compression_control) 
operator PFN_vkGetImageSubresourceLayout2EXT()const noexcept { return vkGetImageSubresourceLayout2EXT;};
#endif
#if defined(VK_EXT_sample_locations) 
operator PFN_vkCmdSetSampleLocationsEXT()const noexcept { return vkCmdSetSampleLocationsEXT;};
#endif
#if defined(VK_FUCHSIA_external_memory) 
operator PFN_vkGetMemoryZirconHandleFUCHSIA()const noexcept { return vkGetMemoryZirconHandleFUCHSIA;};
operator PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA()const noexcept { return vkGetMemoryZirconHandlePropertiesFUCHSIA;};
#endif
#if defined(VK_EXT_full_screen_exclusive) || defined(VK_EXT_full_screen_exclusive) 
operator PFN_vkGetDeviceGroupSurfacePresentModes2EXT()const noexcept { return vkGetDeviceGroupSurfacePresentModes2EXT;};
#endif
#if defined(VK_NV_mesh_shader) 
operator PFN_vkCmdDrawMeshTasksNV()const noexcept { return vkCmdDrawMeshTasksNV;};
operator PFN_vkCmdDrawMeshTasksIndirectNV()const noexcept { return vkCmdDrawMeshTasksIndirectNV;};
operator PFN_vkCmdDrawMeshTasksIndirectCountNV()const noexcept { return vkCmdDrawMeshTasksIndirectCountNV;};
#endif
#if defined(VK_AMD_draw_indirect_count) 
operator PFN_vkCmdDrawIndirectCountAMD()const noexcept { return vkCmdDrawIndirectCountAMD;};
operator PFN_vkCmdDrawIndexedIndirectCountAMD()const noexcept { return vkCmdDrawIndexedIndirectCountAMD;};
#endif
#if defined(VK_KHR_maintenance1) 
operator PFN_vkTrimCommandPoolKHR()const noexcept { return vkTrimCommandPoolKHR;};
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) 
operator PFN_vkGetQueueCheckpointDataNV()const noexcept { return vkGetQueueCheckpointDataNV;};
operator PFN_vkCmdSetCheckpointNV()const noexcept { return vkCmdSetCheckpointNV;};
#endif
#if defined(VK_GOOGLE_display_timing) 
operator PFN_vkGetRefreshCycleDurationGOOGLE()const noexcept { return vkGetRefreshCycleDurationGOOGLE;};
operator PFN_vkGetPastPresentationTimingGOOGLE()const noexcept { return vkGetPastPresentationTimingGOOGLE;};
#endif
#if defined(VK_AMD_display_native_hdr) 
operator PFN_vkSetLocalDimmingAMD()const noexcept { return vkSetLocalDimmingAMD;};
#endif
#if defined(VK_KHR_external_fence_fd) 
operator PFN_vkImportFenceFdKHR()const noexcept { return vkImportFenceFdKHR;};
operator PFN_vkGetFenceFdKHR()const noexcept { return vkGetFenceFdKHR;};
#endif
#if defined(VK_KHR_present_wait) 
operator PFN_vkWaitForPresentKHR()const noexcept { return vkWaitForPresentKHR;};
#endif
#if defined(VK_EXT_metal_objects) 
operator PFN_vkExportMetalObjectsEXT()const noexcept { return vkExportMetalObjectsEXT;};
#endif
#if defined(VK_EXT_swapchain_maintenance1) 
operator PFN_vkReleaseSwapchainImagesEXT()const noexcept { return vkReleaseSwapchainImagesEXT;};
#endif
#if defined(VK_EXT_image_drm_format_modifier) 
operator PFN_vkGetImageDrmFormatModifierPropertiesEXT()const noexcept { return vkGetImageDrmFormatModifierPropertiesEXT;};
#endif
#if defined(VK_EXT_calibrated_timestamps) 
operator PFN_vkGetCalibratedTimestampsEXT()const noexcept { return vkGetCalibratedTimestampsEXT;};
#endif
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state) 
operator PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT()const noexcept { return vkCmdSetAttachmentFeedbackLoopEnableEXT;};
#endif
#if defined(VK_NV_scissor_exclusive) 
operator PFN_vkCmdSetExclusiveScissorEnableNV()const noexcept { return vkCmdSetExclusiveScissorEnableNV;};
operator PFN_vkCmdSetExclusiveScissorNV()const noexcept { return vkCmdSetExclusiveScissorNV;};
#endif
#if defined(VK_EXT_buffer_device_address) 
operator PFN_vkGetBufferDeviceAddressEXT()const noexcept { return vkGetBufferDeviceAddressEXT;};
#endif
#if defined(VK_EXT_line_rasterization) 
operator PFN_vkCmdSetLineStippleEXT()const noexcept { return vkCmdSetLineStippleEXT;};
#endif
#if defined(VK_FUCHSIA_external_semaphore) 
operator PFN_vkGetSemaphoreZirconHandleFUCHSIA()const noexcept { return vkGetSemaphoreZirconHandleFUCHSIA;};
operator PFN_vkImportSemaphoreZirconHandleFUCHSIA()const noexcept { return vkImportSemaphoreZirconHandleFUCHSIA;};
#endif
#if defined(VK_KHR_object_refresh) 
operator PFN_vkCmdRefreshObjectsKHR()const noexcept { return vkCmdRefreshObjectsKHR;};
#endif
#if defined(VK_EXT_device_fault) 
operator PFN_vkGetDeviceFaultInfoEXT()const noexcept { return vkGetDeviceFaultInfoEXT;};
#endif
#if defined(VK_NV_external_sci_sync2) 
operator PFN_vkCreateSemaphoreSciSyncPoolNV()const noexcept { return vkCreateSemaphoreSciSyncPoolNV;};
operator PFN_vkDestroySemaphoreSciSyncPoolNV()const noexcept { return vkDestroySemaphoreSciSyncPoolNV;};
#endif
#if defined(VK_VALVE_descriptor_set_host_mapping) 
operator PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE()const noexcept { return vkGetDescriptorSetLayoutHostMappingInfoVALVE;};
operator PFN_vkGetDescriptorSetHostMappingVALVE()const noexcept { return vkGetDescriptorSetHostMappingVALVE;};
#endif

public:
#if defined(VK_VERSION_1_0) 
PFN_vkDestroyDevice vkDestroyDevice;
PFN_vkResetEvent vkResetEvent;
PFN_vkMapMemory vkMapMemory;
PFN_vkGetDeviceQueue vkGetDeviceQueue;
PFN_vkQueueSubmit vkQueueSubmit;
PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
PFN_vkAllocateMemory vkAllocateMemory;
PFN_vkDestroyPipeline vkDestroyPipeline;
PFN_vkQueueWaitIdle vkQueueWaitIdle;
PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
PFN_vkCreateImage vkCreateImage;
PFN_vkFreeMemory vkFreeMemory;
PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
PFN_vkResetDescriptorPool vkResetDescriptorPool;
PFN_vkSetEvent vkSetEvent;
PFN_vkUnmapMemory vkUnmapMemory;
PFN_vkCreateSampler vkCreateSampler;
PFN_vkCreateEvent vkCreateEvent;
PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
PFN_vkGetFenceStatus vkGetFenceStatus;
PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
PFN_vkBindBufferMemory vkBindBufferMemory;
PFN_vkBindImageMemory vkBindImageMemory;
PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
PFN_vkDestroySampler vkDestroySampler;
PFN_vkDestroyImageView vkDestroyImageView;
PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
PFN_vkCreateQueryPool vkCreateQueryPool;
PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
PFN_vkQueueBindSparse vkQueueBindSparse;
PFN_vkCreateFence vkCreateFence;
PFN_vkCreateCommandPool vkCreateCommandPool;
PFN_vkDestroyFence vkDestroyFence;
PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
PFN_vkResetFences vkResetFences;
PFN_vkWaitForFences vkWaitForFences;
PFN_vkCreateSemaphore vkCreateSemaphore;
PFN_vkDestroyBuffer vkDestroyBuffer;
PFN_vkDestroySemaphore vkDestroySemaphore;
PFN_vkGetEventStatus vkGetEventStatus;
PFN_vkDestroyEvent vkDestroyEvent;
PFN_vkDestroyQueryPool vkDestroyQueryPool;
PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
PFN_vkCreateBuffer vkCreateBuffer;
PFN_vkCreateBufferView vkCreateBufferView;
PFN_vkDestroyBufferView vkDestroyBufferView;
PFN_vkDestroyImage vkDestroyImage;
PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
PFN_vkCmdNextSubpass vkCmdNextSubpass;
PFN_vkCreateImageView vkCreateImageView;
PFN_vkCreateShaderModule vkCreateShaderModule;
PFN_vkDestroyShaderModule vkDestroyShaderModule;
PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
PFN_vkCmdFillBuffer vkCmdFillBuffer;
PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
PFN_vkCreatePipelineCache vkCreatePipelineCache;
PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
PFN_vkMergePipelineCaches vkMergePipelineCaches;
PFN_vkCreateComputePipelines vkCreateComputePipelines;
PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
PFN_vkCmdCopyImage vkCmdCopyImage;
PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
PFN_vkCreateFramebuffer vkCreateFramebuffer;
PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
PFN_vkCreateRenderPass vkCreateRenderPass;
PFN_vkDestroyRenderPass vkDestroyRenderPass;
PFN_vkDestroyCommandPool vkDestroyCommandPool;
PFN_vkResetCommandPool vkResetCommandPool;
PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
PFN_vkEndCommandBuffer vkEndCommandBuffer;
PFN_vkResetCommandBuffer vkResetCommandBuffer;
PFN_vkCmdBindPipeline vkCmdBindPipeline;
PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
PFN_vkCmdSetViewport vkCmdSetViewport;
PFN_vkCmdSetScissor vkCmdSetScissor;
PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
PFN_vkCmdDraw vkCmdDraw;
PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
PFN_vkCmdDispatch vkCmdDispatch;
PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
PFN_vkCmdBlitImage vkCmdBlitImage;
PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
PFN_vkCmdClearColorImage vkCmdClearColorImage;
PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
PFN_vkCmdClearAttachments vkCmdClearAttachments;
PFN_vkCmdResolveImage vkCmdResolveImage;
PFN_vkCmdSetEvent vkCmdSetEvent;
PFN_vkCmdResetEvent vkCmdResetEvent;
PFN_vkCmdWaitEvents vkCmdWaitEvents;
PFN_vkCmdBeginQuery vkCmdBeginQuery;
PFN_vkCmdEndQuery vkCmdEndQuery;
PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
PFN_vkCmdPushConstants vkCmdPushConstants;
PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
#endif
#if defined(VK_KHR_device_group) 
PFN_vkCmdSetDeviceMaskKHR vkCmdSetDeviceMaskKHR;
PFN_vkCmdDispatchBaseKHR vkCmdDispatchBaseKHR;
PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR;
#endif
#if defined(VK_VERSION_1_1) 
PFN_vkBindBufferMemory2 vkBindBufferMemory2;
PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
PFN_vkBindImageMemory2 vkBindImageMemory2;
PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
PFN_vkCmdDispatchBase vkCmdDispatchBase;
PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;
PFN_vkTrimCommandPool vkTrimCommandPool;
PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
#endif
#if defined(VK_EXT_descriptor_buffer) 
PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT;
PFN_vkCmdSetDescriptorBufferOffsetsEXT vkCmdSetDescriptorBufferOffsetsEXT;
PFN_vkGetDescriptorEXT vkGetDescriptorEXT;
PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT vkGetSamplerOpaqueCaptureDescriptorDataEXT;
PFN_vkGetDescriptorSetLayoutSizeEXT vkGetDescriptorSetLayoutSizeEXT;
PFN_vkGetDescriptorSetLayoutBindingOffsetEXT vkGetDescriptorSetLayoutBindingOffsetEXT;
PFN_vkCmdBindDescriptorBuffersEXT vkCmdBindDescriptorBuffersEXT;
PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT vkCmdBindDescriptorBufferEmbeddedSamplersEXT;
PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT vkGetBufferOpaqueCaptureDescriptorDataEXT;
PFN_vkGetImageOpaqueCaptureDescriptorDataEXT vkGetImageOpaqueCaptureDescriptorDataEXT;
PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT vkGetImageViewOpaqueCaptureDescriptorDataEXT;
#endif
#if defined(VK_EXT_debug_marker) 
PFN_vkDebugMarkerSetObjectTagEXT vkDebugMarkerSetObjectTagEXT;
PFN_vkCmdDebugMarkerInsertEXT vkCmdDebugMarkerInsertEXT;
PFN_vkCmdDebugMarkerBeginEXT vkCmdDebugMarkerBeginEXT;
PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT;
PFN_vkCmdDebugMarkerEndEXT vkCmdDebugMarkerEndEXT;
#endif
#if defined(VK_AMD_buffer_marker) 
PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD;
#endif
#if defined(VK_NV_optical_flow) 
PFN_vkBindOpticalFlowSessionImageNV vkBindOpticalFlowSessionImageNV;
PFN_vkCmdOpticalFlowExecuteNV vkCmdOpticalFlowExecuteNV;
PFN_vkCreateOpticalFlowSessionNV vkCreateOpticalFlowSessionNV;
PFN_vkDestroyOpticalFlowSessionNV vkDestroyOpticalFlowSessionNV;
#endif
#if defined(VK_EXT_opacity_micromap) 
PFN_vkCreateMicromapEXT vkCreateMicromapEXT;
PFN_vkCopyMemoryToMicromapEXT vkCopyMemoryToMicromapEXT;
PFN_vkBuildMicromapsEXT vkBuildMicromapsEXT;
PFN_vkCmdCopyMicromapEXT vkCmdCopyMicromapEXT;
PFN_vkGetMicromapBuildSizesEXT vkGetMicromapBuildSizesEXT;
PFN_vkWriteMicromapsPropertiesEXT vkWriteMicromapsPropertiesEXT;
PFN_vkCopyMicromapEXT vkCopyMicromapEXT;
PFN_vkDestroyMicromapEXT vkDestroyMicromapEXT;
PFN_vkCmdBuildMicromapsEXT vkCmdBuildMicromapsEXT;
PFN_vkCopyMicromapToMemoryEXT vkCopyMicromapToMemoryEXT;
PFN_vkCmdCopyMicromapToMemoryEXT vkCmdCopyMicromapToMemoryEXT;
PFN_vkCmdCopyMemoryToMicromapEXT vkCmdCopyMemoryToMicromapEXT;
PFN_vkCmdWriteMicromapsPropertiesEXT vkCmdWriteMicromapsPropertiesEXT;
PFN_vkGetDeviceMicromapCompatibilityEXT vkGetDeviceMicromapCompatibilityEXT;
#endif
#if defined(VK_KHR_get_memory_requirements2) 
PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR;
PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;
#endif
#if defined(VK_FUCHSIA_buffer_collection) 
PFN_vkGetBufferCollectionPropertiesFUCHSIA vkGetBufferCollectionPropertiesFUCHSIA;
PFN_vkDestroyBufferCollectionFUCHSIA vkDestroyBufferCollectionFUCHSIA;
PFN_vkCreateBufferCollectionFUCHSIA vkCreateBufferCollectionFUCHSIA;
PFN_vkSetBufferCollectionImageConstraintsFUCHSIA vkSetBufferCollectionImageConstraintsFUCHSIA;
PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA vkSetBufferCollectionBufferConstraintsFUCHSIA;
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2) 
PFN_vkImportFenceSciSyncObjNV vkImportFenceSciSyncObjNV;
PFN_vkGetFenceSciSyncFenceNV vkGetFenceSciSyncFenceNV;
PFN_vkImportFenceSciSyncFenceNV vkImportFenceSciSyncFenceNV;
PFN_vkGetFenceSciSyncObjNV vkGetFenceSciSyncObjNV;
#endif
#if defined(VK_KHR_map_memory2) 
PFN_vkUnmapMemory2KHR vkUnmapMemory2KHR;
PFN_vkMapMemory2KHR vkMapMemory2KHR;
#endif
#if defined(VK_AMD_shader_info) 
PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD;
#endif
#if defined(VK_KHR_deferred_host_operations) 
PFN_vkGetDeferredOperationMaxConcurrencyKHR vkGetDeferredOperationMaxConcurrencyKHR;
PFN_vkGetDeferredOperationResultKHR vkGetDeferredOperationResultKHR;
PFN_vkCreateDeferredOperationKHR vkCreateDeferredOperationKHR;
PFN_vkDestroyDeferredOperationKHR vkDestroyDeferredOperationKHR;
PFN_vkDeferredOperationJoinKHR vkDeferredOperationJoinKHR;
#endif
#if defined(VK_NV_fragment_shading_rate_enums) 
PFN_vkCmdSetFragmentShadingRateEnumNV vkCmdSetFragmentShadingRateEnumNV;
#endif
#if defined(VK_NV_ray_tracing) 
PFN_vkCompileDeferredNV vkCompileDeferredNV;
PFN_vkGetAccelerationStructureHandleNV vkGetAccelerationStructureHandleNV;
PFN_vkGetRayTracingShaderGroupHandlesNV vkGetRayTracingShaderGroupHandlesNV;
PFN_vkCmdTraceRaysNV vkCmdTraceRaysNV;
PFN_vkCmdWriteAccelerationStructuresPropertiesNV vkCmdWriteAccelerationStructuresPropertiesNV;
PFN_vkCreateAccelerationStructureNV vkCreateAccelerationStructureNV;
PFN_vkDestroyAccelerationStructureNV vkDestroyAccelerationStructureNV;
PFN_vkGetAccelerationStructureMemoryRequirementsNV vkGetAccelerationStructureMemoryRequirementsNV;
PFN_vkBindAccelerationStructureMemoryNV vkBindAccelerationStructureMemoryNV;
PFN_vkCmdBuildAccelerationStructureNV vkCmdBuildAccelerationStructureNV;
PFN_vkCmdCopyAccelerationStructureNV vkCmdCopyAccelerationStructureNV;
PFN_vkCreateRayTracingPipelinesNV vkCreateRayTracingPipelinesNV;
#endif
#if defined(VK_KHR_synchronization2) 
PFN_vkCmdResetEvent2KHR vkCmdResetEvent2KHR;
PFN_vkCmdWaitEvents2KHR vkCmdWaitEvents2KHR;
PFN_vkCmdSetEvent2KHR vkCmdSetEvent2KHR;
PFN_vkCmdWriteTimestamp2KHR vkCmdWriteTimestamp2KHR;
PFN_vkCmdPipelineBarrier2KHR vkCmdPipelineBarrier2KHR;
PFN_vkQueueSubmit2KHR vkQueueSubmit2KHR;
PFN_vkCmdWriteBufferMarker2AMD vkCmdWriteBufferMarker2AMD;
PFN_vkGetQueueCheckpointData2NV vkGetQueueCheckpointData2NV;
#endif
#if defined(VK_KHR_video_queue) 
PFN_vkCreateVideoSessionParametersKHR vkCreateVideoSessionParametersKHR;
PFN_vkCreateVideoSessionKHR vkCreateVideoSessionKHR;
PFN_vkBindVideoSessionMemoryKHR vkBindVideoSessionMemoryKHR;
PFN_vkUpdateVideoSessionParametersKHR vkUpdateVideoSessionParametersKHR;
PFN_vkDestroyVideoSessionKHR vkDestroyVideoSessionKHR;
PFN_vkGetVideoSessionMemoryRequirementsKHR vkGetVideoSessionMemoryRequirementsKHR;
PFN_vkDestroyVideoSessionParametersKHR vkDestroyVideoSessionParametersKHR;
PFN_vkCmdBeginVideoCodingKHR vkCmdBeginVideoCodingKHR;
PFN_vkCmdEndVideoCodingKHR vkCmdEndVideoCodingKHR;
PFN_vkCmdControlVideoCodingKHR vkCmdControlVideoCodingKHR;
#endif
#if defined(VK_KHR_push_descriptor) || defined(VK_KHR_push_descriptor) || defined(VK_KHR_descriptor_update_template) 
PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;
#endif
#if defined(VK_KHR_descriptor_update_template) 
PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR;
PFN_vkCreateDescriptorUpdateTemplateKHR vkCreateDescriptorUpdateTemplateKHR;
PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR;
#endif
#if defined(VK_KHR_push_descriptor) 
PFN_vkCmdPushDescriptorSetKHR vkCmdPushDescriptorSetKHR;
#endif
#if defined(VK_NVX_binary_import) 
PFN_vkCreateCuFunctionNVX vkCreateCuFunctionNVX;
PFN_vkCreateCuModuleNVX vkCreateCuModuleNVX;
PFN_vkDestroyCuModuleNVX vkDestroyCuModuleNVX;
PFN_vkDestroyCuFunctionNVX vkDestroyCuFunctionNVX;
PFN_vkCmdCuLaunchKernelNVX vkCmdCuLaunchKernelNVX;
#endif
#if defined(VK_NV_shading_rate_image) 
PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV;
PFN_vkCmdSetCoarseSampleOrderNV vkCmdSetCoarseSampleOrderNV;
PFN_vkCmdBindShadingRateImageNV vkCmdBindShadingRateImageNV;
#endif
#if defined(VK_KHR_buffer_device_address) 
PFN_vkGetBufferDeviceAddressKHR vkGetBufferDeviceAddressKHR;
PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR vkGetDeviceMemoryOpaqueCaptureAddressKHR;
PFN_vkGetBufferOpaqueCaptureAddressKHR vkGetBufferOpaqueCaptureAddressKHR;
#endif
#if defined(VK_VERSION_1_3) 
PFN_vkCmdWriteTimestamp2 vkCmdWriteTimestamp2;
PFN_vkCmdSetDepthCompareOp vkCmdSetDepthCompareOp;
PFN_vkCmdSetPrimitiveTopology vkCmdSetPrimitiveTopology;
PFN_vkGetDeviceBufferMemoryRequirements vkGetDeviceBufferMemoryRequirements;
PFN_vkCmdPipelineBarrier2 vkCmdPipelineBarrier2;
PFN_vkCmdSetDepthWriteEnable vkCmdSetDepthWriteEnable;
PFN_vkCmdSetViewportWithCount vkCmdSetViewportWithCount;
PFN_vkCreatePrivateDataSlot vkCreatePrivateDataSlot;
PFN_vkDestroyPrivateDataSlot vkDestroyPrivateDataSlot;
PFN_vkSetPrivateData vkSetPrivateData;
PFN_vkGetPrivateData vkGetPrivateData;
PFN_vkCmdSetEvent2 vkCmdSetEvent2;
PFN_vkCmdResetEvent2 vkCmdResetEvent2;
PFN_vkCmdWaitEvents2 vkCmdWaitEvents2;
PFN_vkQueueSubmit2 vkQueueSubmit2;
PFN_vkCmdCopyBuffer2 vkCmdCopyBuffer2;
PFN_vkCmdCopyImage2 vkCmdCopyImage2;
PFN_vkCmdCopyBufferToImage2 vkCmdCopyBufferToImage2;
PFN_vkCmdCopyImageToBuffer2 vkCmdCopyImageToBuffer2;
PFN_vkCmdBlitImage2 vkCmdBlitImage2;
PFN_vkCmdResolveImage2 vkCmdResolveImage2;
PFN_vkCmdBeginRendering vkCmdBeginRendering;
PFN_vkCmdEndRendering vkCmdEndRendering;
PFN_vkCmdSetCullMode vkCmdSetCullMode;
PFN_vkCmdSetFrontFace vkCmdSetFrontFace;
PFN_vkCmdSetScissorWithCount vkCmdSetScissorWithCount;
PFN_vkCmdBindVertexBuffers2 vkCmdBindVertexBuffers2;
PFN_vkCmdSetDepthTestEnable vkCmdSetDepthTestEnable;
PFN_vkCmdSetDepthBoundsTestEnable vkCmdSetDepthBoundsTestEnable;
PFN_vkCmdSetStencilTestEnable vkCmdSetStencilTestEnable;
PFN_vkCmdSetStencilOp vkCmdSetStencilOp;
PFN_vkCmdSetRasterizerDiscardEnable vkCmdSetRasterizerDiscardEnable;
PFN_vkCmdSetDepthBiasEnable vkCmdSetDepthBiasEnable;
PFN_vkCmdSetPrimitiveRestartEnable vkCmdSetPrimitiveRestartEnable;
PFN_vkGetDeviceImageMemoryRequirements vkGetDeviceImageMemoryRequirements;
PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements;
#endif
#if defined(VK_KHR_ray_tracing_pipeline) 
PFN_vkCmdTraceRaysIndirectKHR vkCmdTraceRaysIndirectKHR;
PFN_vkCmdSetRayTracingPipelineStackSizeKHR vkCmdSetRayTracingPipelineStackSizeKHR;
PFN_vkGetRayTracingShaderGroupHandlesKHR vkGetRayTracingShaderGroupHandlesKHR;
PFN_vkGetRayTracingShaderGroupStackSizeKHR vkGetRayTracingShaderGroupStackSizeKHR;
PFN_vkCmdTraceRaysKHR vkCmdTraceRaysKHR;
PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
PFN_vkCreateRayTracingPipelinesKHR vkCreateRayTracingPipelinesKHR;
#endif
#if defined(VK_VERSION_1_2) 
PFN_vkResetQueryPool vkResetQueryPool;
PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress;
PFN_vkCmdBeginRenderPass2 vkCmdBeginRenderPass2;
PFN_vkCmdDrawIndirectCount vkCmdDrawIndirectCount;
PFN_vkCmdDrawIndexedIndirectCount vkCmdDrawIndexedIndirectCount;
PFN_vkCreateRenderPass2 vkCreateRenderPass2;
PFN_vkCmdNextSubpass2 vkCmdNextSubpass2;
PFN_vkWaitSemaphores vkWaitSemaphores;
PFN_vkCmdEndRenderPass2 vkCmdEndRenderPass2;
PFN_vkGetSemaphoreCounterValue vkGetSemaphoreCounterValue;
PFN_vkSignalSemaphore vkSignalSemaphore;
PFN_vkGetBufferDeviceAddress vkGetBufferDeviceAddress;
PFN_vkGetBufferOpaqueCaptureAddress vkGetBufferOpaqueCaptureAddress;
#endif
#if defined(VK_NV_device_generated_commands) 
PFN_vkCmdPreprocessGeneratedCommandsNV vkCmdPreprocessGeneratedCommandsNV;
PFN_vkCmdBindPipelineShaderGroupNV vkCmdBindPipelineShaderGroupNV;
PFN_vkDestroyIndirectCommandsLayoutNV vkDestroyIndirectCommandsLayoutNV;
PFN_vkGetGeneratedCommandsMemoryRequirementsNV vkGetGeneratedCommandsMemoryRequirementsNV;
PFN_vkCreateIndirectCommandsLayoutNV vkCreateIndirectCommandsLayoutNV;
PFN_vkCmdExecuteGeneratedCommandsNV vkCmdExecuteGeneratedCommandsNV;
#endif
#if defined(VK_EXT_pipeline_properties) 
PFN_vkGetPipelinePropertiesEXT vkGetPipelinePropertiesEXT;
#endif
#if defined(VK_EXT_shader_module_identifier) 
PFN_vkGetShaderModuleIdentifierEXT vkGetShaderModuleIdentifierEXT;
PFN_vkGetShaderModuleCreateInfoIdentifierEXT vkGetShaderModuleCreateInfoIdentifierEXT;
#endif
#if defined(VK_NV_clip_space_w_scaling) 
PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV;
#endif
#if defined(VK_HUAWEI_subpass_shading) 
PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI;
PFN_vkCmdSubpassShadingHUAWEI vkCmdSubpassShadingHUAWEI;
#endif
#if defined(VK_INTEL_performance_query) 
PFN_vkCmdSetPerformanceStreamMarkerINTEL vkCmdSetPerformanceStreamMarkerINTEL;
PFN_vkReleasePerformanceConfigurationINTEL vkReleasePerformanceConfigurationINTEL;
PFN_vkInitializePerformanceApiINTEL vkInitializePerformanceApiINTEL;
PFN_vkUninitializePerformanceApiINTEL vkUninitializePerformanceApiINTEL;
PFN_vkCmdSetPerformanceMarkerINTEL vkCmdSetPerformanceMarkerINTEL;
PFN_vkCmdSetPerformanceOverrideINTEL vkCmdSetPerformanceOverrideINTEL;
PFN_vkAcquirePerformanceConfigurationINTEL vkAcquirePerformanceConfigurationINTEL;
PFN_vkQueueSetPerformanceConfigurationINTEL vkQueueSetPerformanceConfigurationINTEL;
PFN_vkGetPerformanceParameterINTEL vkGetPerformanceParameterINTEL;
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state3) 
PFN_vkCmdSetAlphaToCoverageEnableEXT vkCmdSetAlphaToCoverageEnableEXT;
PFN_vkCmdSetCoverageModulationModeNV vkCmdSetCoverageModulationModeNV;
PFN_vkCmdSetSampleMaskEXT vkCmdSetSampleMaskEXT;
PFN_vkCmdSetColorBlendEnableEXT vkCmdSetColorBlendEnableEXT;
PFN_vkCmdSetCoverageToColorLocationNV vkCmdSetCoverageToColorLocationNV;
PFN_vkCmdSetCoverageModulationTableNV vkCmdSetCoverageModulationTableNV;
PFN_vkCmdSetProvokingVertexModeEXT vkCmdSetProvokingVertexModeEXT;
PFN_vkCmdSetColorWriteMaskEXT vkCmdSetColorWriteMaskEXT;
PFN_vkCmdSetSampleLocationsEnableEXT vkCmdSetSampleLocationsEnableEXT;
PFN_vkCmdSetAlphaToOneEnableEXT vkCmdSetAlphaToOneEnableEXT;
PFN_vkCmdSetDepthClipNegativeOneToOneEXT vkCmdSetDepthClipNegativeOneToOneEXT;
PFN_vkCmdSetTessellationDomainOriginEXT vkCmdSetTessellationDomainOriginEXT;
PFN_vkCmdSetDepthClampEnableEXT vkCmdSetDepthClampEnableEXT;
PFN_vkCmdSetPolygonModeEXT vkCmdSetPolygonModeEXT;
PFN_vkCmdSetRasterizationSamplesEXT vkCmdSetRasterizationSamplesEXT;
PFN_vkCmdSetLogicOpEnableEXT vkCmdSetLogicOpEnableEXT;
PFN_vkCmdSetColorBlendEquationEXT vkCmdSetColorBlendEquationEXT;
PFN_vkCmdSetRasterizationStreamEXT vkCmdSetRasterizationStreamEXT;
PFN_vkCmdSetConservativeRasterizationModeEXT vkCmdSetConservativeRasterizationModeEXT;
PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT vkCmdSetExtraPrimitiveOverestimationSizeEXT;
PFN_vkCmdSetDepthClipEnableEXT vkCmdSetDepthClipEnableEXT;
PFN_vkCmdSetColorBlendAdvancedEXT vkCmdSetColorBlendAdvancedEXT;
PFN_vkCmdSetLineRasterizationModeEXT vkCmdSetLineRasterizationModeEXT;
PFN_vkCmdSetLineStippleEnableEXT vkCmdSetLineStippleEnableEXT;
PFN_vkCmdSetViewportWScalingEnableNV vkCmdSetViewportWScalingEnableNV;
PFN_vkCmdSetViewportSwizzleNV vkCmdSetViewportSwizzleNV;
PFN_vkCmdSetCoverageToColorEnableNV vkCmdSetCoverageToColorEnableNV;
PFN_vkCmdSetCoverageModulationTableEnableNV vkCmdSetCoverageModulationTableEnableNV;
PFN_vkCmdSetShadingRateImageEnableNV vkCmdSetShadingRateImageEnableNV;
PFN_vkCmdSetRepresentativeFragmentTestEnableNV vkCmdSetRepresentativeFragmentTestEnableNV;
PFN_vkCmdSetCoverageReductionModeNV vkCmdSetCoverageReductionModeNV;
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state) 
PFN_vkCmdSetStencilTestEnableEXT vkCmdSetStencilTestEnableEXT;
PFN_vkCmdSetDepthTestEnableEXT vkCmdSetDepthTestEnableEXT;
PFN_vkCmdSetCullModeEXT vkCmdSetCullModeEXT;
PFN_vkCmdSetFrontFaceEXT vkCmdSetFrontFaceEXT;
PFN_vkCmdSetPrimitiveTopologyEXT vkCmdSetPrimitiveTopologyEXT;
PFN_vkCmdSetViewportWithCountEXT vkCmdSetViewportWithCountEXT;
PFN_vkCmdSetScissorWithCountEXT vkCmdSetScissorWithCountEXT;
PFN_vkCmdBindVertexBuffers2EXT vkCmdBindVertexBuffers2EXT;
PFN_vkCmdSetDepthWriteEnableEXT vkCmdSetDepthWriteEnableEXT;
PFN_vkCmdSetDepthCompareOpEXT vkCmdSetDepthCompareOpEXT;
PFN_vkCmdSetDepthBoundsTestEnableEXT vkCmdSetDepthBoundsTestEnableEXT;
PFN_vkCmdSetStencilOpEXT vkCmdSetStencilOpEXT;
#endif
#if defined(VK_EXT_multi_draw) 
PFN_vkCmdDrawMultiEXT vkCmdDrawMultiEXT;
PFN_vkCmdDrawMultiIndexedEXT vkCmdDrawMultiIndexedEXT;
#endif
#if defined(VK_NV_external_memory_rdma) 
PFN_vkGetMemoryRemoteAddressNV vkGetMemoryRemoteAddressNV;
#endif
#if defined(VK_EXT_shader_object) 
PFN_vkCreateShadersEXT vkCreateShadersEXT;
PFN_vkDestroyShaderEXT vkDestroyShaderEXT;
PFN_vkGetShaderBinaryDataEXT vkGetShaderBinaryDataEXT;
PFN_vkCmdBindShadersEXT vkCmdBindShadersEXT;
#endif
#if defined(VK_KHR_bind_memory2) 
PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;
#endif
#if defined(VK_EXT_debug_utils) 
PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabelEXT;
PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabelEXT;
PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabelEXT;
PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectNameEXT;
PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT;
PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTagEXT;
PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabelEXT;
PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabelEXT;
#endif
#if defined(VK_NV_low_latency2) 
PFN_vkQueueNotifyOutOfBandNV vkQueueNotifyOutOfBandNV;
PFN_vkSetLatencySleepModeNV vkSetLatencySleepModeNV;
PFN_vkLatencySleepNV vkLatencySleepNV;
PFN_vkSetLatencyMarkerNV vkSetLatencyMarkerNV;
PFN_vkGetLatencyTimingsNV vkGetLatencyTimingsNV;
#endif
#if defined(VK_EXT_display_control) 
PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) 
PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR;
PFN_vkCreateSamplerYcbcrConversionKHR vkCreateSamplerYcbcrConversionKHR;
#endif
#if defined(VK_KHR_pipeline_executable_properties) 
PFN_vkGetPipelineExecutableStatisticsKHR vkGetPipelineExecutableStatisticsKHR;
PFN_vkGetPipelineExecutableInternalRepresentationsKHR vkGetPipelineExecutableInternalRepresentationsKHR;
PFN_vkGetPipelineExecutablePropertiesKHR vkGetPipelineExecutablePropertiesKHR;
#endif
#if defined(VK_AMDX_shader_enqueue) 
PFN_vkCreateExecutionGraphPipelinesAMDX vkCreateExecutionGraphPipelinesAMDX;
PFN_vkGetExecutionGraphPipelineNodeIndexAMDX vkGetExecutionGraphPipelineNodeIndexAMDX;
PFN_vkCmdDispatchGraphIndirectCountAMDX vkCmdDispatchGraphIndirectCountAMDX;
PFN_vkGetExecutionGraphPipelineScratchSizeAMDX vkGetExecutionGraphPipelineScratchSizeAMDX;
PFN_vkCmdDispatchGraphAMDX vkCmdDispatchGraphAMDX;
PFN_vkCmdInitializeGraphScratchMemoryAMDX vkCmdInitializeGraphScratchMemoryAMDX;
PFN_vkCmdDispatchGraphIndirectAMDX vkCmdDispatchGraphIndirectAMDX;
#endif
#if defined(VK_KHR_acceleration_structure) 
PFN_vkCopyAccelerationStructureToMemoryKHR vkCopyAccelerationStructureToMemoryKHR;
PFN_vkCopyAccelerationStructureKHR vkCopyAccelerationStructureKHR;
PFN_vkGetAccelerationStructureBuildSizesKHR vkGetAccelerationStructureBuildSizesKHR;
PFN_vkWriteAccelerationStructuresPropertiesKHR vkWriteAccelerationStructuresPropertiesKHR;
PFN_vkBuildAccelerationStructuresKHR vkBuildAccelerationStructuresKHR;
PFN_vkCopyMemoryToAccelerationStructureKHR vkCopyMemoryToAccelerationStructureKHR;
PFN_vkCmdCopyAccelerationStructureKHR vkCmdCopyAccelerationStructureKHR;
PFN_vkCmdWriteAccelerationStructuresPropertiesKHR vkCmdWriteAccelerationStructuresPropertiesKHR;
PFN_vkDestroyAccelerationStructureKHR vkDestroyAccelerationStructureKHR;
PFN_vkGetDeviceAccelerationStructureCompatibilityKHR vkGetDeviceAccelerationStructureCompatibilityKHR;
PFN_vkGetAccelerationStructureDeviceAddressKHR vkGetAccelerationStructureDeviceAddressKHR;
PFN_vkCreateAccelerationStructureKHR vkCreateAccelerationStructureKHR;
PFN_vkCmdBuildAccelerationStructuresKHR vkCmdBuildAccelerationStructuresKHR;
PFN_vkCmdBuildAccelerationStructuresIndirectKHR vkCmdBuildAccelerationStructuresIndirectKHR;
PFN_vkCmdCopyAccelerationStructureToMemoryKHR vkCmdCopyAccelerationStructureToMemoryKHR;
PFN_vkCmdCopyMemoryToAccelerationStructureKHR vkCmdCopyMemoryToAccelerationStructureKHR;
#endif
#if defined(VK_QNX_external_memory_screen_buffer) 
PFN_vkGetScreenBufferPropertiesQNX vkGetScreenBufferPropertiesQNX;
#endif
#if defined(VK_NV_external_memory_win32) 
PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV;
#endif
#if defined(VK_NV_memory_decompression) 
PFN_vkCmdDecompressMemoryNV vkCmdDecompressMemoryNV;
PFN_vkCmdDecompressMemoryIndirectCountNV vkCmdDecompressMemoryIndirectCountNV;
#endif
#if defined(VK_KHR_dynamic_rendering) 
PFN_vkCmdEndRenderingKHR vkCmdEndRenderingKHR;
PFN_vkCmdBeginRenderingKHR vkCmdBeginRenderingKHR;
#endif
#if defined(VK_EXT_pageable_device_local_memory) 
PFN_vkSetDeviceMemoryPriorityEXT vkSetDeviceMemoryPriorityEXT;
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) 
PFN_vkGetAndroidHardwareBufferPropertiesANDROID vkGetAndroidHardwareBufferPropertiesANDROID;
PFN_vkGetMemoryAndroidHardwareBufferANDROID vkGetMemoryAndroidHardwareBufferANDROID;
#endif
#if defined(VK_EXT_host_image_copy) 
PFN_vkCopyMemoryToImageEXT vkCopyMemoryToImageEXT;
PFN_vkCopyImageToMemoryEXT vkCopyImageToMemoryEXT;
PFN_vkCopyImageToImageEXT vkCopyImageToImageEXT;
PFN_vkTransitionImageLayoutEXT vkTransitionImageLayoutEXT;
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2) 
PFN_vkCmdSetPrimitiveRestartEnableEXT vkCmdSetPrimitiveRestartEnableEXT;
PFN_vkCmdSetRasterizerDiscardEnableEXT vkCmdSetRasterizerDiscardEnableEXT;
PFN_vkCmdSetPatchControlPointsEXT vkCmdSetPatchControlPointsEXT;
PFN_vkCmdSetDepthBiasEnableEXT vkCmdSetDepthBiasEnableEXT;
PFN_vkCmdSetLogicOpEXT vkCmdSetLogicOpEXT;
#endif
#if defined(VK_EXT_external_memory_host) 
PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;
#endif
#if defined(VK_KHR_external_semaphore_fd) 
PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;
#endif
#if defined(VK_KHR_performance_query) 
PFN_vkReleaseProfilingLockKHR vkReleaseProfilingLockKHR;
PFN_vkAcquireProfilingLockKHR vkAcquireProfilingLockKHR;
#endif
#if defined(VK_HUAWEI_cluster_culling_shader) 
PFN_vkCmdDrawClusterIndirectHUAWEI vkCmdDrawClusterIndirectHUAWEI;
PFN_vkCmdDrawClusterHUAWEI vkCmdDrawClusterHUAWEI;
#endif
#if defined(VK_NV_external_memory_sci_buf) 
PFN_vkGetMemorySciBufNV vkGetMemorySciBufNV;
#endif
#if defined(VK_KHR_external_memory_win32) 
PFN_vkGetMemoryWin32HandleKHR vkGetMemoryWin32HandleKHR;
PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR;
#endif
#if defined(VK_EXT_mesh_shader) 
PFN_vkCmdDrawMeshTasksEXT vkCmdDrawMeshTasksEXT;
PFN_vkCmdDrawMeshTasksIndirectEXT vkCmdDrawMeshTasksIndirectEXT;
PFN_vkCmdDrawMeshTasksIndirectCountEXT vkCmdDrawMeshTasksIndirectCountEXT;
#endif
#if defined(VK_EXT_full_screen_exclusive) 
PFN_vkReleaseFullScreenExclusiveModeEXT vkReleaseFullScreenExclusiveModeEXT;
PFN_vkAcquireFullScreenExclusiveModeEXT vkAcquireFullScreenExclusiveModeEXT;
#endif
#if defined(VK_EXT_private_data) 
PFN_vkSetPrivateDataEXT vkSetPrivateDataEXT;
PFN_vkDestroyPrivateDataSlotEXT vkDestroyPrivateDataSlotEXT;
PFN_vkCreatePrivateDataSlotEXT vkCreatePrivateDataSlotEXT;
PFN_vkGetPrivateDataEXT vkGetPrivateDataEXT;
#endif
#if defined(VK_HUAWEI_invocation_mask) 
PFN_vkCmdBindInvocationMaskHUAWEI vkCmdBindInvocationMaskHUAWEI;
#endif
#if defined(VK_QCOM_tile_properties) 
PFN_vkGetDynamicRenderingTilePropertiesQCOM vkGetDynamicRenderingTilePropertiesQCOM;
PFN_vkGetFramebufferTilePropertiesQCOM vkGetFramebufferTilePropertiesQCOM;
#endif
#if defined(VK_KHR_external_fence_win32) 
PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR;
PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR;
#endif
#if defined(VK_KHR_create_renderpass2) 
PFN_vkCmdBeginRenderPass2KHR vkCmdBeginRenderPass2KHR;
PFN_vkCmdEndRenderPass2KHR vkCmdEndRenderPass2KHR;
PFN_vkCmdNextSubpass2KHR vkCmdNextSubpass2KHR;
PFN_vkCreateRenderPass2KHR vkCreateRenderPass2KHR;
#endif
#if defined(VK_EXT_depth_bias_control) 
PFN_vkCmdSetDepthBias2EXT vkCmdSetDepthBias2EXT;
#endif
#if defined(VK_KHR_copy_commands2) 
PFN_vkCmdCopyImageToBuffer2KHR vkCmdCopyImageToBuffer2KHR;
PFN_vkCmdCopyBuffer2KHR vkCmdCopyBuffer2KHR;
PFN_vkCmdCopyImage2KHR vkCmdCopyImage2KHR;
PFN_vkCmdCopyBufferToImage2KHR vkCmdCopyBufferToImage2KHR;
PFN_vkCmdBlitImage2KHR vkCmdBlitImage2KHR;
PFN_vkCmdResolveImage2KHR vkCmdResolveImage2KHR;
#endif
#if defined(VK_EXT_color_write_enable) 
PFN_vkCmdSetColorWriteEnableEXT vkCmdSetColorWriteEnableEXT;
#endif
#if defined(VK_NVX_image_view_handle) 
PFN_vkGetImageViewAddressNVX vkGetImageViewAddressNVX;
PFN_vkGetImageViewHandleNVX vkGetImageViewHandleNVX;
#endif
#if defined(VK_KHR_video_encode_queue) 
PFN_vkGetEncodedVideoSessionParametersKHR vkGetEncodedVideoSessionParametersKHR;
PFN_vkCmdEncodeVideoKHR vkCmdEncodeVideoKHR;
#endif
#if defined(VK_EXT_host_query_reset) 
PFN_vkResetQueryPoolEXT vkResetQueryPoolEXT;
#endif
#if defined(VK_ANDROID_native_buffer) 
PFN_vkGetSwapchainGrallocUsageANDROID vkGetSwapchainGrallocUsageANDROID;
PFN_vkAcquireImageANDROID vkAcquireImageANDROID;
PFN_vkQueueSignalReleaseImageANDROID vkQueueSignalReleaseImageANDROID;
PFN_vkGetSwapchainGrallocUsage2ANDROID vkGetSwapchainGrallocUsage2ANDROID;
#endif
#if defined(VK_NV_external_sci_sync) 
PFN_vkGetSemaphoreSciSyncObjNV vkGetSemaphoreSciSyncObjNV;
PFN_vkImportSemaphoreSciSyncObjNV vkImportSemaphoreSciSyncObjNV;
#endif
#if defined(VK_KHR_external_memory_fd) 
PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR;
PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
#endif
#if defined(VK_EXT_transform_feedback) 
PFN_vkCmdEndQueryIndexedEXT vkCmdEndQueryIndexedEXT;
PFN_vkCmdDrawIndirectByteCountEXT vkCmdDrawIndirectByteCountEXT;
PFN_vkCmdEndTransformFeedbackEXT vkCmdEndTransformFeedbackEXT;
PFN_vkCmdBindTransformFeedbackBuffersEXT vkCmdBindTransformFeedbackBuffersEXT;
PFN_vkCmdBeginTransformFeedbackEXT vkCmdBeginTransformFeedbackEXT;
PFN_vkCmdBeginQueryIndexedEXT vkCmdBeginQueryIndexedEXT;
#endif
#if defined(VK_NV_copy_memory_indirect) 
PFN_vkCmdCopyMemoryToImageIndirectNV vkCmdCopyMemoryToImageIndirectNV;
PFN_vkCmdCopyMemoryIndirectNV vkCmdCopyMemoryIndirectNV;
#endif
#if defined(VK_KHR_external_semaphore_win32) 
PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR;
PFN_vkGetSemaphoreWin32HandleKHR vkGetSemaphoreWin32HandleKHR;
#endif
#if defined(VK_EXT_validation_cache) 
PFN_vkCreateValidationCacheEXT vkCreateValidationCacheEXT;
PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT;
PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT;
PFN_vkMergeValidationCachesEXT vkMergeValidationCachesEXT;
#endif
#if defined(VK_KHR_timeline_semaphore) 
PFN_vkWaitSemaphoresKHR vkWaitSemaphoresKHR;
PFN_vkGetSemaphoreCounterValueKHR vkGetSemaphoreCounterValueKHR;
PFN_vkSignalSemaphoreKHR vkSignalSemaphoreKHR;
#endif
#if defined(VK_KHR_swapchain) 
PFN_vkQueuePresentKHR vkQueuePresentKHR;
PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
#endif
#if defined(VK_KHR_draw_indirect_count) 
PFN_vkCmdDrawIndirectCountKHR vkCmdDrawIndirectCountKHR;
PFN_vkCmdDrawIndexedIndirectCountKHR vkCmdDrawIndexedIndirectCountKHR;
#endif
#if defined(VK_KHR_ray_tracing_maintenance1) 
PFN_vkCmdTraceRaysIndirect2KHR vkCmdTraceRaysIndirect2KHR;
#endif
#if defined(VK_KHR_fragment_shading_rate) 
PFN_vkCmdSetFragmentShadingRateKHR vkCmdSetFragmentShadingRateKHR;
#endif
#if defined(VKSC_VERSION_1_0) 
PFN_vkGetCommandPoolMemoryConsumption vkGetCommandPoolMemoryConsumption;
PFN_vkGetFaultData vkGetFaultData;
#endif
#if defined(VK_KHR_maintenance5) 
PFN_vkGetDeviceImageSubresourceLayoutKHR vkGetDeviceImageSubresourceLayoutKHR;
PFN_vkCmdBindIndexBuffer2KHR vkCmdBindIndexBuffer2KHR;
PFN_vkGetRenderingAreaGranularityKHR vkGetRenderingAreaGranularityKHR;
PFN_vkGetImageSubresourceLayout2KHR vkGetImageSubresourceLayout2KHR;
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group) 
PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
#endif
#if defined(VK_KHR_display_swapchain) 
PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
#endif
#if defined(VK_KHR_maintenance3) 
PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR;
#endif
#if defined(VK_NV_device_generated_commands_compute) 
PFN_vkCmdUpdatePipelineIndirectBufferNV vkCmdUpdatePipelineIndirectBufferNV;
PFN_vkGetPipelineIndirectDeviceAddressNV vkGetPipelineIndirectDeviceAddressNV;
PFN_vkGetPipelineIndirectMemoryRequirementsNV vkGetPipelineIndirectMemoryRequirementsNV;
#endif
#if defined(VK_EXT_conditional_rendering) 
PFN_vkCmdEndConditionalRenderingEXT vkCmdEndConditionalRenderingEXT;
PFN_vkCmdBeginConditionalRenderingEXT vkCmdBeginConditionalRenderingEXT;
#endif
#if defined(VK_KHR_video_decode_queue) 
PFN_vkCmdDecodeVideoKHR vkCmdDecodeVideoKHR;
#endif
#if defined(VK_EXT_hdr_metadata) 
PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT;
#endif
#if defined(VK_KHR_maintenance4) 
PFN_vkGetDeviceBufferMemoryRequirementsKHR vkGetDeviceBufferMemoryRequirementsKHR;
PFN_vkGetDeviceImageMemoryRequirementsKHR vkGetDeviceImageMemoryRequirementsKHR;
PFN_vkGetDeviceImageSparseMemoryRequirementsKHR vkGetDeviceImageSparseMemoryRequirementsKHR;
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_vertex_input_dynamic_state) 
PFN_vkCmdSetVertexInputEXT vkCmdSetVertexInputEXT;
#endif
#if defined(VK_KHR_shared_presentable_image) 
PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;
#endif
#if defined(VK_EXT_discard_rectangles) 
PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;
PFN_vkCmdSetDiscardRectangleModeEXT vkCmdSetDiscardRectangleModeEXT;
PFN_vkCmdSetDiscardRectangleEnableEXT vkCmdSetDiscardRectangleEnableEXT;
#endif
#if defined(VK_EXT_host_image_copy) || defined(VK_EXT_image_compression_control) 
PFN_vkGetImageSubresourceLayout2EXT vkGetImageSubresourceLayout2EXT;
#endif
#if defined(VK_EXT_sample_locations) 
PFN_vkCmdSetSampleLocationsEXT vkCmdSetSampleLocationsEXT;
#endif
#if defined(VK_FUCHSIA_external_memory) 
PFN_vkGetMemoryZirconHandleFUCHSIA vkGetMemoryZirconHandleFUCHSIA;
PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA vkGetMemoryZirconHandlePropertiesFUCHSIA;
#endif
#if defined(VK_EXT_full_screen_exclusive) || defined(VK_EXT_full_screen_exclusive) 
PFN_vkGetDeviceGroupSurfacePresentModes2EXT vkGetDeviceGroupSurfacePresentModes2EXT;
#endif
#if defined(VK_NV_mesh_shader) 
PFN_vkCmdDrawMeshTasksNV vkCmdDrawMeshTasksNV;
PFN_vkCmdDrawMeshTasksIndirectNV vkCmdDrawMeshTasksIndirectNV;
PFN_vkCmdDrawMeshTasksIndirectCountNV vkCmdDrawMeshTasksIndirectCountNV;
#endif
#if defined(VK_AMD_draw_indirect_count) 
PFN_vkCmdDrawIndirectCountAMD vkCmdDrawIndirectCountAMD;
PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD;
#endif
#if defined(VK_KHR_maintenance1) 
PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR;
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) 
PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV;
PFN_vkCmdSetCheckpointNV vkCmdSetCheckpointNV;
#endif
#if defined(VK_GOOGLE_display_timing) 
PFN_vkGetRefreshCycleDurationGOOGLE vkGetRefreshCycleDurationGOOGLE;
PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE;
#endif
#if defined(VK_AMD_display_native_hdr) 
PFN_vkSetLocalDimmingAMD vkSetLocalDimmingAMD;
#endif
#if defined(VK_KHR_external_fence_fd) 
PFN_vkImportFenceFdKHR vkImportFenceFdKHR;
PFN_vkGetFenceFdKHR vkGetFenceFdKHR;
#endif
#if defined(VK_KHR_present_wait) 
PFN_vkWaitForPresentKHR vkWaitForPresentKHR;
#endif
#if defined(VK_EXT_metal_objects) 
PFN_vkExportMetalObjectsEXT vkExportMetalObjectsEXT;
#endif
#if defined(VK_EXT_swapchain_maintenance1) 
PFN_vkReleaseSwapchainImagesEXT vkReleaseSwapchainImagesEXT;
#endif
#if defined(VK_EXT_image_drm_format_modifier) 
PFN_vkGetImageDrmFormatModifierPropertiesEXT vkGetImageDrmFormatModifierPropertiesEXT;
#endif
#if defined(VK_EXT_calibrated_timestamps) 
PFN_vkGetCalibratedTimestampsEXT vkGetCalibratedTimestampsEXT;
#endif
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state) 
PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT vkCmdSetAttachmentFeedbackLoopEnableEXT;
#endif
#if defined(VK_NV_scissor_exclusive) 
PFN_vkCmdSetExclusiveScissorEnableNV vkCmdSetExclusiveScissorEnableNV;
PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV;
#endif
#if defined(VK_EXT_buffer_device_address) 
PFN_vkGetBufferDeviceAddressEXT vkGetBufferDeviceAddressEXT;
#endif
#if defined(VK_EXT_line_rasterization) 
PFN_vkCmdSetLineStippleEXT vkCmdSetLineStippleEXT;
#endif
#if defined(VK_FUCHSIA_external_semaphore) 
PFN_vkGetSemaphoreZirconHandleFUCHSIA vkGetSemaphoreZirconHandleFUCHSIA;
PFN_vkImportSemaphoreZirconHandleFUCHSIA vkImportSemaphoreZirconHandleFUCHSIA;
#endif
#if defined(VK_KHR_object_refresh) 
PFN_vkCmdRefreshObjectsKHR vkCmdRefreshObjectsKHR;
#endif
#if defined(VK_EXT_device_fault) 
PFN_vkGetDeviceFaultInfoEXT vkGetDeviceFaultInfoEXT;
#endif
#if defined(VK_NV_external_sci_sync2) 
PFN_vkCreateSemaphoreSciSyncPoolNV vkCreateSemaphoreSciSyncPoolNV;
PFN_vkDestroySemaphoreSciSyncPoolNV vkDestroySemaphoreSciSyncPoolNV;
#endif
#if defined(VK_VALVE_descriptor_set_host_mapping) 
PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE vkGetDescriptorSetLayoutHostMappingInfoVALVE;
PFN_vkGetDescriptorSetHostMappingVALVE vkGetDescriptorSetHostMappingVALVE;
#endif
};

}
