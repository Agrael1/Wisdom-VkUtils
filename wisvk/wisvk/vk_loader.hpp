#pragma once
#include <array>
#include <vulkan/vulkan.h>
#include "vk_libinit.hpp"

namespace wis {

#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_buffer_device_address)
using PFN_vkGetBufferOpaqueCaptureAddress = PFN_vkGetBufferOpaqueCaptureAddressKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_physical_device_properties2)
using PFN_vkGetPhysicalDeviceQueueFamilyProperties2 = PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_private_data)
using PFN_vkCreatePrivateDataSlot = PFN_vkCreatePrivateDataSlotEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetStencilOp = PFN_vkCmdSetStencilOpEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_EXT_host_query_reset)
using PFN_vkResetQueryPool = PFN_vkResetQueryPoolEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_physical_device_properties2)
using PFN_vkGetPhysicalDeviceFeatures2 = PFN_vkGetPhysicalDeviceFeatures2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_physical_device_properties2)
using PFN_vkGetPhysicalDeviceProperties2 = PFN_vkGetPhysicalDeviceProperties2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_device_group)
using PFN_vkGetDeviceGroupPeerMemoryFeatures = PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_physical_device_properties2)
using PFN_vkGetPhysicalDeviceFormatProperties2 = PFN_vkGetPhysicalDeviceFormatProperties2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_physical_device_properties2)
using PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 = PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_physical_device_properties2)
using PFN_vkGetPhysicalDeviceImageFormatProperties2 = PFN_vkGetPhysicalDeviceImageFormatProperties2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_physical_device_properties2)
using PFN_vkGetPhysicalDeviceMemoryProperties2 = PFN_vkGetPhysicalDeviceMemoryProperties2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
using PFN_vkCmdSetDepthBiasEnable = PFN_vkCmdSetDepthBiasEnableEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetCullMode = PFN_vkCmdSetCullModeEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_maintenance1)
using PFN_vkTrimCommandPool = PFN_vkTrimCommandPoolKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_external_semaphore_capabilities)
using PFN_vkGetPhysicalDeviceExternalSemaphoreProperties = PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_external_memory_capabilities)
using PFN_vkGetPhysicalDeviceExternalBufferProperties = PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_memory_requirements2)
using PFN_vkGetImageSparseMemoryRequirements2 = PFN_vkGetImageSparseMemoryRequirements2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_maintenance3)
using PFN_vkGetDescriptorSetLayoutSupport = PFN_vkGetDescriptorSetLayoutSupportKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_external_fence_capabilities)
using PFN_vkGetPhysicalDeviceExternalFenceProperties = PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR;
#endif
#endif
#if !(defined(VK_KHR_calibrated_timestamps))
#if defined(VK_EXT_calibrated_timestamps)
using PFN_vkGetCalibratedTimestampsKHR = PFN_vkGetCalibratedTimestampsEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_device_group_creation)
using PFN_vkEnumeratePhysicalDeviceGroups = PFN_vkEnumeratePhysicalDeviceGroupsKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_bind_memory2)
using PFN_vkBindBufferMemory2 = PFN_vkBindBufferMemory2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_bind_memory2)
using PFN_vkBindImageMemory2 = PFN_vkBindImageMemory2KHR;
#endif
#endif
#if !(defined(VK_KHR_line_rasterization))
#if defined(VK_EXT_line_rasterization)
using PFN_vkCmdSetLineStippleKHR = PFN_vkCmdSetLineStippleEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_descriptor_update_template)
using PFN_vkCreateDescriptorUpdateTemplate = PFN_vkCreateDescriptorUpdateTemplateKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_device_group)
using PFN_vkCmdSetDeviceMask = PFN_vkCmdSetDeviceMaskKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_device_group)
using PFN_vkCmdDispatchBase = PFN_vkCmdDispatchBaseKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_draw_indirect_count)
using PFN_vkCmdDrawIndirectCount = PFN_vkCmdDrawIndirectCountKHR;
#elif defined(VK_AMD_draw_indirect_count)
using PFN_vkCmdDrawIndirectCount = PFN_vkCmdDrawIndirectCountAMD;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetPrimitiveTopology = PFN_vkCmdSetPrimitiveTopologyEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_descriptor_update_template)
using PFN_vkDestroyDescriptorUpdateTemplate = PFN_vkDestroyDescriptorUpdateTemplateKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_descriptor_update_template)
using PFN_vkUpdateDescriptorSetWithTemplate = PFN_vkUpdateDescriptorSetWithTemplateKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_memory_requirements2)
using PFN_vkGetBufferMemoryRequirements2 = PFN_vkGetBufferMemoryRequirements2KHR;
#endif
#endif
#if !(defined(VK_KHR_calibrated_timestamps))
#if defined(VK_EXT_calibrated_timestamps)
using PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_tooling_info)
using PFN_vkGetPhysicalDeviceToolProperties = PFN_vkGetPhysicalDeviceToolPropertiesEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_get_memory_requirements2)
using PFN_vkGetImageMemoryRequirements2 = PFN_vkGetImageMemoryRequirements2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_maintenance4)
using PFN_vkGetDeviceBufferMemoryRequirements = PFN_vkGetDeviceBufferMemoryRequirementsKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_maintenance4)
using PFN_vkGetDeviceImageMemoryRequirements = PFN_vkGetDeviceImageMemoryRequirementsKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_maintenance4)
using PFN_vkGetDeviceImageSparseMemoryRequirements = PFN_vkGetDeviceImageSparseMemoryRequirementsKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_sampler_ycbcr_conversion)
using PFN_vkCreateSamplerYcbcrConversion = PFN_vkCreateSamplerYcbcrConversionKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_sampler_ycbcr_conversion)
using PFN_vkDestroySamplerYcbcrConversion = PFN_vkDestroySamplerYcbcrConversionKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_create_renderpass2)
using PFN_vkCreateRenderPass2 = PFN_vkCreateRenderPass2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetViewportWithCount = PFN_vkCmdSetViewportWithCountEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_create_renderpass2)
using PFN_vkCmdBeginRenderPass2 = PFN_vkCmdBeginRenderPass2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_create_renderpass2)
using PFN_vkCmdNextSubpass2 = PFN_vkCmdNextSubpass2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdBindVertexBuffers2 = PFN_vkCmdBindVertexBuffers2EXT;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_create_renderpass2)
using PFN_vkCmdEndRenderPass2 = PFN_vkCmdEndRenderPass2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_timeline_semaphore)
using PFN_vkWaitSemaphores = PFN_vkWaitSemaphoresKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetStencilTestEnable = PFN_vkCmdSetStencilTestEnableEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_timeline_semaphore)
using PFN_vkGetSemaphoreCounterValue = PFN_vkGetSemaphoreCounterValueKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetFrontFace = PFN_vkCmdSetFrontFaceEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_timeline_semaphore)
using PFN_vkSignalSemaphore = PFN_vkSignalSemaphoreKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_buffer_device_address)
using PFN_vkGetDeviceMemoryOpaqueCaptureAddress = PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_draw_indirect_count)
using PFN_vkCmdDrawIndexedIndirectCount = PFN_vkCmdDrawIndexedIndirectCountKHR;
#elif defined(VK_AMD_draw_indirect_count)
using PFN_vkCmdDrawIndexedIndirectCount = PFN_vkCmdDrawIndexedIndirectCountAMD;
#endif
#endif
#if !(defined(VK_KHR_ray_tracing_pipeline))
#if defined(VK_NV_ray_tracing)
using PFN_vkGetRayTracingShaderGroupHandlesKHR = PFN_vkGetRayTracingShaderGroupHandlesNV;
#endif
#endif
#if !(defined(VK_VERSION_1_2))
#if defined(VK_KHR_buffer_device_address)
using PFN_vkGetBufferDeviceAddress = PFN_vkGetBufferDeviceAddressKHR;
#elif defined(VK_EXT_buffer_device_address)
using PFN_vkGetBufferDeviceAddress = PFN_vkGetBufferDeviceAddressEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetScissorWithCount = PFN_vkCmdSetScissorWithCountEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetDepthTestEnable = PFN_vkCmdSetDepthTestEnableEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetDepthWriteEnable = PFN_vkCmdSetDepthWriteEnableEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetDepthBoundsTestEnable = PFN_vkCmdSetDepthBoundsTestEnableEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
using PFN_vkCmdSetDepthCompareOp = PFN_vkCmdSetDepthCompareOpEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
using PFN_vkCmdSetRasterizerDiscardEnable = PFN_vkCmdSetRasterizerDiscardEnableEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
using PFN_vkCmdSetPrimitiveRestartEnable = PFN_vkCmdSetPrimitiveRestartEnableEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_private_data)
using PFN_vkDestroyPrivateDataSlot = PFN_vkDestroyPrivateDataSlotEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_private_data)
using PFN_vkSetPrivateData = PFN_vkSetPrivateDataEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_private_data)
using PFN_vkGetPrivateData = PFN_vkGetPrivateDataEXT;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_copy_commands2)
using PFN_vkCmdCopyBuffer2 = PFN_vkCmdCopyBuffer2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_copy_commands2)
using PFN_vkCmdCopyImage2 = PFN_vkCmdCopyImage2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_copy_commands2)
using PFN_vkCmdBlitImage2 = PFN_vkCmdBlitImage2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_copy_commands2)
using PFN_vkCmdCopyBufferToImage2 = PFN_vkCmdCopyBufferToImage2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_copy_commands2)
using PFN_vkCmdCopyImageToBuffer2 = PFN_vkCmdCopyImageToBuffer2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_copy_commands2)
using PFN_vkCmdResolveImage2 = PFN_vkCmdResolveImage2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_synchronization2)
using PFN_vkCmdSetEvent2 = PFN_vkCmdSetEvent2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_synchronization2)
using PFN_vkCmdResetEvent2 = PFN_vkCmdResetEvent2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_synchronization2)
using PFN_vkCmdWaitEvents2 = PFN_vkCmdWaitEvents2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_synchronization2)
using PFN_vkCmdPipelineBarrier2 = PFN_vkCmdPipelineBarrier2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_synchronization2)
using PFN_vkQueueSubmit2 = PFN_vkQueueSubmit2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_synchronization2)
using PFN_vkCmdWriteTimestamp2 = PFN_vkCmdWriteTimestamp2KHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_dynamic_rendering)
using PFN_vkCmdBeginRendering = PFN_vkCmdBeginRenderingKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_KHR_dynamic_rendering)
using PFN_vkCmdEndRendering = PFN_vkCmdEndRenderingKHR;
#endif
#endif
#if !(defined(VK_KHR_maintenance5))
#if defined(VK_EXT_host_image_copy) || defined(VK_EXT_image_compression_control)
using PFN_vkGetImageSubresourceLayout2KHR = PFN_vkGetImageSubresourceLayout2EXT;
#endif
#endif

struct VkGlobalTable {
    void Init(LibTokenView token) noexcept
    {
#if defined(VK_VERSION_1_0)
        vkGetInstanceProcAddr = token.GetProcAddress<decltype(vkGetInstanceProcAddr)>("vkGetInstanceProcAddr");
        vkGetDeviceProcAddr = token.GetProcAddress<decltype(vkGetDeviceProcAddr)>("vkGetDeviceProcAddr");
        vkEnumerateInstanceLayerProperties = token.GetProcAddress<decltype(vkEnumerateInstanceLayerProperties)>("vkEnumerateInstanceLayerProperties");
        vkEnumerateInstanceExtensionProperties = token.GetProcAddress<decltype(vkEnumerateInstanceExtensionProperties)>("vkEnumerateInstanceExtensionProperties");
        vkCreateInstance = token.GetProcAddress<decltype(vkCreateInstance)>("vkCreateInstance");
        vkDestroyInstance = token.GetProcAddress<decltype(vkDestroyInstance)>("vkDestroyInstance");
#endif
#if defined(VK_VERSION_1_1)
        vkEnumerateInstanceVersion = token.GetProcAddress<decltype(vkEnumerateInstanceVersion)>("vkEnumerateInstanceVersion");
#endif
    }

public:
#if defined(VK_VERSION_1_0)
    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
    PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
    PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
    PFN_vkCreateInstance vkCreateInstance;
    PFN_vkDestroyInstance vkDestroyInstance;
#endif
#if defined(VK_VERSION_1_1)
    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
#endif
};

struct VkInstanceTable {
    void Init(VkInstance instance, VkGlobalTable global_table) noexcept
    {
#if defined(VK_KHR_xcb_surface)
        vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
        vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateXcbSurfaceKHR");
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_device_group_creation)
        static constexpr std::array vkEnumeratePhysicalDeviceGroups_strings
        {
#if defined(VK_VERSION_1_1)
            "vkEnumeratePhysicalDeviceGroups",
#endif
#if defined(VK_KHR_device_group_creation)
                    "vkEnumeratePhysicalDeviceGroupsKHR",
#endif
        };
        for (auto vkEnumeratePhysicalDeviceGroups_it : vkEnumeratePhysicalDeviceGroups_strings)
            if ((vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)global_table.vkGetInstanceProcAddr(instance, vkEnumeratePhysicalDeviceGroups_it)))
                break;
#endif
#if defined(VK_EXT_directfb_surface)
        vkCreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateDirectFBSurfaceEXT");
        vkGetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif
#if defined(VK_VERSION_1_0)
        vkCreateDevice = (PFN_vkCreateDevice)global_table.vkGetInstanceProcAddr(instance, "vkCreateDevice");
        vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties");
        vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)global_table.vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDevices");
        vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)global_table.vkGetInstanceProcAddr(instance, "vkEnumerateDeviceLayerProperties");
        vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures");
        vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties");
        vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties");
        vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties");
        vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties");
        vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)global_table.vkGetInstanceProcAddr(instance, "vkEnumerateDeviceExtensionProperties");
        vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties");
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
#if defined(VK_EXT_direct_mode_display)
        vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkReleaseDisplayEXT");
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_get_physical_device_properties2)
        static constexpr std::array vkGetPhysicalDeviceQueueFamilyProperties2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceQueueFamilyProperties2",
#endif
#if defined(VK_KHR_get_physical_device_properties2)
                    "vkGetPhysicalDeviceQueueFamilyProperties2KHR",
#endif
        };
        for (auto vkGetPhysicalDeviceQueueFamilyProperties2_it : vkGetPhysicalDeviceQueueFamilyProperties2_strings)
            if ((vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceQueueFamilyProperties2_it)))
                break;
        static constexpr std::array vkGetPhysicalDeviceFeatures2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceFeatures2",
#endif
#if defined(VK_KHR_get_physical_device_properties2)
                    "vkGetPhysicalDeviceFeatures2KHR",
#endif
        };
        for (auto vkGetPhysicalDeviceFeatures2_it : vkGetPhysicalDeviceFeatures2_strings)
            if ((vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceFeatures2_it)))
                break;
        static constexpr std::array vkGetPhysicalDeviceProperties2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceProperties2",
#endif
#if defined(VK_KHR_get_physical_device_properties2)
                    "vkGetPhysicalDeviceProperties2KHR",
#endif
        };
        for (auto vkGetPhysicalDeviceProperties2_it : vkGetPhysicalDeviceProperties2_strings)
            if ((vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceProperties2_it)))
                break;
        static constexpr std::array vkGetPhysicalDeviceFormatProperties2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceFormatProperties2",
#endif
#if defined(VK_KHR_get_physical_device_properties2)
                    "vkGetPhysicalDeviceFormatProperties2KHR",
#endif
        };
        for (auto vkGetPhysicalDeviceFormatProperties2_it : vkGetPhysicalDeviceFormatProperties2_strings)
            if ((vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceFormatProperties2_it)))
                break;
        static constexpr std::array vkGetPhysicalDeviceImageFormatProperties2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceImageFormatProperties2",
#endif
#if defined(VK_KHR_get_physical_device_properties2)
                    "vkGetPhysicalDeviceImageFormatProperties2KHR",
#endif
        };
        for (auto vkGetPhysicalDeviceImageFormatProperties2_it : vkGetPhysicalDeviceImageFormatProperties2_strings)
            if ((vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceImageFormatProperties2_it)))
                break;
        static constexpr std::array vkGetPhysicalDeviceMemoryProperties2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceMemoryProperties2",
#endif
#if defined(VK_KHR_get_physical_device_properties2)
                    "vkGetPhysicalDeviceMemoryProperties2KHR",
#endif
        };
        for (auto vkGetPhysicalDeviceMemoryProperties2_it : vkGetPhysicalDeviceMemoryProperties2_strings)
            if ((vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceMemoryProperties2_it)))
                break;
        static constexpr std::array vkGetPhysicalDeviceSparseImageFormatProperties2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceSparseImageFormatProperties2",
#endif
#if defined(VK_KHR_get_physical_device_properties2)
                    "vkGetPhysicalDeviceSparseImageFormatProperties2KHR",
#endif
        };
        for (auto vkGetPhysicalDeviceSparseImageFormatProperties2_it : vkGetPhysicalDeviceSparseImageFormatProperties2_strings)
            if ((vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceSparseImageFormatProperties2_it)))
                break;
#endif
#if defined(VK_NV_optical_flow)
        vkGetPhysicalDeviceOpticalFlowImageFormatsNV = (PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
#endif
#if defined(VK_EXT_debug_report)
        vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)global_table.vkGetInstanceProcAddr(instance, "vkDebugReportMessageEXT");
        vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)global_table.vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
        vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
#endif
#if defined(VK_KHR_xlib_surface)
        vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateXlibSurfaceKHR");
        vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif
#if defined(VK_EXT_display_surface_counter)
        vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif
#if defined(VK_MVK_macos_surface)
        vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)global_table.vkGetInstanceProcAddr(instance, "vkCreateMacOSSurfaceMVK");
#endif
#if defined(VK_NV_acquire_winrt_display)
        vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)global_table.vkGetInstanceProcAddr(instance, "vkAcquireWinrtDisplayNV");
        vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV)global_table.vkGetInstanceProcAddr(instance, "vkGetWinrtDisplayNV");
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
#if defined(VK_VERSION_1_1) || defined(VK_KHR_external_memory_capabilities)
        static constexpr std::array vkGetPhysicalDeviceExternalBufferProperties_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceExternalBufferProperties",
#endif
#if defined(VK_KHR_external_memory_capabilities)
                    "vkGetPhysicalDeviceExternalBufferPropertiesKHR",
#endif
        };
        for (auto vkGetPhysicalDeviceExternalBufferProperties_it : vkGetPhysicalDeviceExternalBufferProperties_strings)
            if ((vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceExternalBufferProperties_it)))
                break;
#endif
#if defined(VK_NV_cooperative_matrix)
        vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_external_semaphore_capabilities)
        static constexpr std::array vkGetPhysicalDeviceExternalSemaphoreProperties_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceExternalSemaphoreProperties",
#endif
#if defined(VK_KHR_external_semaphore_capabilities)
                    "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR",
#endif
        };
        for (auto vkGetPhysicalDeviceExternalSemaphoreProperties_it : vkGetPhysicalDeviceExternalSemaphoreProperties_strings)
            if ((vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceExternalSemaphoreProperties_it)))
                break;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_external_fence_capabilities)
        static constexpr std::array vkGetPhysicalDeviceExternalFenceProperties_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetPhysicalDeviceExternalFenceProperties",
#endif
#if defined(VK_KHR_external_fence_capabilities)
                    "vkGetPhysicalDeviceExternalFencePropertiesKHR",
#endif
        };
        for (auto vkGetPhysicalDeviceExternalFenceProperties_it : vkGetPhysicalDeviceExternalFenceProperties_strings)
            if ((vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceExternalFenceProperties_it)))
                break;
#endif
#if defined(VK_VERSION_1_3) || defined(VK_EXT_tooling_info)
        static constexpr std::array vkGetPhysicalDeviceToolProperties_strings
        {
#if defined(VK_VERSION_1_3)
            "vkGetPhysicalDeviceToolProperties",
#endif
#if defined(VK_EXT_tooling_info)
                    "vkGetPhysicalDeviceToolPropertiesEXT",
#endif
        };
        for (auto vkGetPhysicalDeviceToolProperties_it : vkGetPhysicalDeviceToolProperties_strings)
            if ((vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceToolProperties_it)))
                break;
#endif
#if defined(VK_KHR_wayland_surface)
        vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)global_table.vkGetInstanceProcAddr(instance, "vkCreateWaylandSurfaceKHR");
        vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
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
#if defined(VK_EXT_acquire_xlib_display)
        vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkAcquireXlibDisplayEXT");
        vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)global_table.vkGetInstanceProcAddr(instance, "vkGetRandROutputDisplayEXT");
#endif
#if defined(VK_EXT_debug_utils)
        vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)global_table.vkGetInstanceProcAddr(instance, "vkSubmitDebugUtilsMessageEXT");
        vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)global_table.vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
        vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)global_table.vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
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
#if defined(VK_EXT_full_screen_exclusive)
        vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
#endif
#if defined(VK_GGP_stream_descriptor_surface)
        vkCreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP)global_table.vkGetInstanceProcAddr(instance, "vkCreateStreamDescriptorSurfaceGGP");
#endif
#if defined(VK_MVK_ios_surface)
        vkCreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)global_table.vkGetInstanceProcAddr(instance, "vkCreateIOSSurfaceMVK");
#endif
#if defined(VK_EXT_calibrated_timestamps) || defined(VK_KHR_calibrated_timestamps)
        static constexpr std::array vkGetPhysicalDeviceCalibrateableTimeDomainsKHR_strings
        {
#if defined(VK_KHR_calibrated_timestamps)
            "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR",
#endif
#if defined(VK_EXT_calibrated_timestamps)
                    "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT",
#endif
        };
        for (auto vkGetPhysicalDeviceCalibrateableTimeDomainsKHR_it : vkGetPhysicalDeviceCalibrateableTimeDomainsKHR_strings)
            if ((vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR)global_table.vkGetInstanceProcAddr(instance, vkGetPhysicalDeviceCalibrateableTimeDomainsKHR_it)))
                break;
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
#if defined(VK_NV_external_memory_sci_buf)
        vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV = (PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
        vkGetPhysicalDeviceSciBufAttributesNV = (PFN_vkGetPhysicalDeviceSciBufAttributesNV)global_table.vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSciBufAttributesNV");
#endif
    }

public:
#if defined(VK_KHR_xcb_surface)
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
    PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_device_group_creation)
    PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
#endif
#if defined(VK_EXT_directfb_surface)
    PFN_vkCreateDirectFBSurfaceEXT vkCreateDirectFBSurfaceEXT;
    PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
#endif
#if defined(VK_VERSION_1_0)
    PFN_vkCreateDevice vkCreateDevice;
    PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
    PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
    PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
    PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
    PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
    PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
    PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
    PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
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
#if defined(VK_EXT_direct_mode_display)
    PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_get_physical_device_properties2)
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
    PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
    PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
    PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
    PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
    PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
#endif
#if defined(VK_NV_optical_flow)
    PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV vkGetPhysicalDeviceOpticalFlowImageFormatsNV;
#endif
#if defined(VK_EXT_debug_report)
    PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
    PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
    PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
#endif
#if defined(VK_KHR_xlib_surface)
    PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif
#if defined(VK_EXT_display_surface_counter)
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;
#endif
#if defined(VK_MVK_macos_surface)
    PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK;
#endif
#if defined(VK_NV_acquire_winrt_display)
    PFN_vkAcquireWinrtDisplayNV vkAcquireWinrtDisplayNV;
    PFN_vkGetWinrtDisplayNV vkGetWinrtDisplayNV;
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
#if defined(VK_VERSION_1_1) || defined(VK_KHR_external_memory_capabilities)
    PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
#endif
#if defined(VK_NV_cooperative_matrix)
    PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_external_semaphore_capabilities)
    PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_external_fence_capabilities)
    PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
#endif
#if defined(VK_VERSION_1_3) || defined(VK_EXT_tooling_info)
    PFN_vkGetPhysicalDeviceToolProperties vkGetPhysicalDeviceToolProperties;
#endif
#if defined(VK_KHR_wayland_surface)
    PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
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
#if defined(VK_EXT_acquire_xlib_display)
    PFN_vkAcquireXlibDisplayEXT vkAcquireXlibDisplayEXT;
    PFN_vkGetRandROutputDisplayEXT vkGetRandROutputDisplayEXT;
#endif
#if defined(VK_EXT_debug_utils)
    PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;
    PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
    PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
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
#if defined(VK_EXT_full_screen_exclusive)
    PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT;
#endif
#if defined(VK_GGP_stream_descriptor_surface)
    PFN_vkCreateStreamDescriptorSurfaceGGP vkCreateStreamDescriptorSurfaceGGP;
#endif
#if defined(VK_MVK_ios_surface)
    PFN_vkCreateIOSSurfaceMVK vkCreateIOSSurfaceMVK;
#endif
#if defined(VK_EXT_calibrated_timestamps) || defined(VK_KHR_calibrated_timestamps)
    PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR vkGetPhysicalDeviceCalibrateableTimeDomainsKHR;
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
#if defined(VK_NV_external_memory_sci_buf)
    PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV;
    PFN_vkGetPhysicalDeviceSciBufAttributesNV vkGetPhysicalDeviceSciBufAttributesNV;
#endif
};

struct VkDeviceTable {
    void Init(VkDevice device, VkGlobalTable global_table) noexcept
    {
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
#if defined(VK_VERSION_1_1) || defined(VK_KHR_bind_memory2)
        static constexpr std::array vkBindBufferMemory2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkBindBufferMemory2",
#endif
#if defined(VK_KHR_bind_memory2)
                    "vkBindBufferMemory2KHR",
#endif
        };
        for (auto vkBindBufferMemory2_it : vkBindBufferMemory2_strings)
            if ((vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)global_table.vkGetDeviceProcAddr(device, vkBindBufferMemory2_it)))
                break;
        static constexpr std::array vkBindImageMemory2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkBindImageMemory2",
#endif
#if defined(VK_KHR_bind_memory2)
                    "vkBindImageMemory2KHR",
#endif
        };
        for (auto vkBindImageMemory2_it : vkBindImageMemory2_strings)
            if ((vkBindImageMemory2 = (PFN_vkBindImageMemory2)global_table.vkGetDeviceProcAddr(device, vkBindImageMemory2_it)))
                break;
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
#if defined(VK_FUCHSIA_buffer_collection)
        vkGetBufferCollectionPropertiesFUCHSIA = (PFN_vkGetBufferCollectionPropertiesFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkGetBufferCollectionPropertiesFUCHSIA");
        vkDestroyBufferCollectionFUCHSIA = (PFN_vkDestroyBufferCollectionFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkDestroyBufferCollectionFUCHSIA");
        vkCreateBufferCollectionFUCHSIA = (PFN_vkCreateBufferCollectionFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkCreateBufferCollectionFUCHSIA");
        vkSetBufferCollectionImageConstraintsFUCHSIA = (PFN_vkSetBufferCollectionImageConstraintsFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkSetBufferCollectionImageConstraintsFUCHSIA");
        vkSetBufferCollectionBufferConstraintsFUCHSIA = (PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkSetBufferCollectionBufferConstraintsFUCHSIA");
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2)
        vkImportFenceSciSyncObjNV = (PFN_vkImportFenceSciSyncObjNV)global_table.vkGetDeviceProcAddr(device, "vkImportFenceSciSyncObjNV");
        vkImportFenceSciSyncFenceNV = (PFN_vkImportFenceSciSyncFenceNV)global_table.vkGetDeviceProcAddr(device, "vkImportFenceSciSyncFenceNV");
        vkGetFenceSciSyncFenceNV = (PFN_vkGetFenceSciSyncFenceNV)global_table.vkGetDeviceProcAddr(device, "vkGetFenceSciSyncFenceNV");
        vkGetFenceSciSyncObjNV = (PFN_vkGetFenceSciSyncObjNV)global_table.vkGetDeviceProcAddr(device, "vkGetFenceSciSyncObjNV");
#endif
#if defined(VK_EXT_opacity_micromap)
        vkCreateMicromapEXT = (PFN_vkCreateMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCreateMicromapEXT");
        vkCopyMemoryToMicromapEXT = (PFN_vkCopyMemoryToMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMemoryToMicromapEXT");
        vkBuildMicromapsEXT = (PFN_vkBuildMicromapsEXT)global_table.vkGetDeviceProcAddr(device, "vkBuildMicromapsEXT");
        vkCmdCopyMicromapEXT = (PFN_vkCmdCopyMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMicromapEXT");
        vkCopyMicromapToMemoryEXT = (PFN_vkCopyMicromapToMemoryEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMicromapToMemoryEXT");
        vkGetMicromapBuildSizesEXT = (PFN_vkGetMicromapBuildSizesEXT)global_table.vkGetDeviceProcAddr(device, "vkGetMicromapBuildSizesEXT");
        vkWriteMicromapsPropertiesEXT = (PFN_vkWriteMicromapsPropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkWriteMicromapsPropertiesEXT");
        vkDestroyMicromapEXT = (PFN_vkDestroyMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkDestroyMicromapEXT");
        vkCmdWriteMicromapsPropertiesEXT = (PFN_vkCmdWriteMicromapsPropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteMicromapsPropertiesEXT");
        vkCmdBuildMicromapsEXT = (PFN_vkCmdBuildMicromapsEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBuildMicromapsEXT");
        vkCopyMicromapEXT = (PFN_vkCopyMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMicromapEXT");
        vkCmdCopyMicromapToMemoryEXT = (PFN_vkCmdCopyMicromapToMemoryEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMicromapToMemoryEXT");
        vkCmdCopyMemoryToMicromapEXT = (PFN_vkCmdCopyMemoryToMicromapEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMemoryToMicromapEXT");
        vkGetDeviceMicromapCompatibilityEXT = (PFN_vkGetDeviceMicromapCompatibilityEXT)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceMicromapCompatibilityEXT");
#endif
#if defined(VK_KHR_map_memory2)
        vkUnmapMemory2KHR = (PFN_vkUnmapMemory2KHR)global_table.vkGetDeviceProcAddr(device, "vkUnmapMemory2KHR");
        vkMapMemory2KHR = (PFN_vkMapMemory2KHR)global_table.vkGetDeviceProcAddr(device, "vkMapMemory2KHR");
#endif
#if defined(VK_HUAWEI_cluster_culling_shader)
        vkCmdDrawClusterHUAWEI = (PFN_vkCmdDrawClusterHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawClusterHUAWEI");
        vkCmdDrawClusterIndirectHUAWEI = (PFN_vkCmdDrawClusterIndirectHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawClusterIndirectHUAWEI");
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
#if defined(VK_KHR_external_fence_win32)
        vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)global_table.vkGetDeviceProcAddr(device, "vkGetFenceWin32HandleKHR");
        vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)global_table.vkGetDeviceProcAddr(device, "vkImportFenceWin32HandleKHR");
#endif
#if defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)
        static constexpr std::array vkCmdWriteTimestamp2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdWriteTimestamp2",
#endif
#if defined(VK_KHR_synchronization2)
                    "vkCmdWriteTimestamp2KHR",
#endif
        };
        for (auto vkCmdWriteTimestamp2_it : vkCmdWriteTimestamp2_strings)
            if ((vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2)global_table.vkGetDeviceProcAddr(device, vkCmdWriteTimestamp2_it)))
                break;
        static constexpr std::array vkCmdPipelineBarrier2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdPipelineBarrier2",
#endif
#if defined(VK_KHR_synchronization2)
                    "vkCmdPipelineBarrier2KHR",
#endif
        };
        for (auto vkCmdPipelineBarrier2_it : vkCmdPipelineBarrier2_strings)
            if ((vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2)global_table.vkGetDeviceProcAddr(device, vkCmdPipelineBarrier2_it)))
                break;
        static constexpr std::array vkCmdSetEvent2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetEvent2",
#endif
#if defined(VK_KHR_synchronization2)
                    "vkCmdSetEvent2KHR",
#endif
        };
        for (auto vkCmdSetEvent2_it : vkCmdSetEvent2_strings)
            if ((vkCmdSetEvent2 = (PFN_vkCmdSetEvent2)global_table.vkGetDeviceProcAddr(device, vkCmdSetEvent2_it)))
                break;
        static constexpr std::array vkCmdResetEvent2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdResetEvent2",
#endif
#if defined(VK_KHR_synchronization2)
                    "vkCmdResetEvent2KHR",
#endif
        };
        for (auto vkCmdResetEvent2_it : vkCmdResetEvent2_strings)
            if ((vkCmdResetEvent2 = (PFN_vkCmdResetEvent2)global_table.vkGetDeviceProcAddr(device, vkCmdResetEvent2_it)))
                break;
        static constexpr std::array vkCmdWaitEvents2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdWaitEvents2",
#endif
#if defined(VK_KHR_synchronization2)
                    "vkCmdWaitEvents2KHR",
#endif
        };
        for (auto vkCmdWaitEvents2_it : vkCmdWaitEvents2_strings)
            if ((vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2)global_table.vkGetDeviceProcAddr(device, vkCmdWaitEvents2_it)))
                break;
        static constexpr std::array vkQueueSubmit2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkQueueSubmit2",
#endif
#if defined(VK_KHR_synchronization2)
                    "vkQueueSubmit2KHR",
#endif
        };
        for (auto vkQueueSubmit2_it : vkQueueSubmit2_strings)
            if ((vkQueueSubmit2 = (PFN_vkQueueSubmit2)global_table.vkGetDeviceProcAddr(device, vkQueueSubmit2_it)))
                break;
#endif
#if defined(VK_KHR_ray_tracing_pipeline)
        vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdTraceRaysIndirectKHR");
        vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRayTracingPipelineStackSizeKHR");
        vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)global_table.vkGetDeviceProcAddr(device, "vkGetRayTracingShaderGroupStackSizeKHR");
        vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdTraceRaysKHR");
        vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
        vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateRayTracingPipelinesKHR");
#endif
#if defined(VK_NV_copy_memory_indirect)
        vkCmdCopyMemoryIndirectNV = (PFN_vkCmdCopyMemoryIndirectNV)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMemoryIndirectNV");
        vkCmdCopyMemoryToImageIndirectNV = (PFN_vkCmdCopyMemoryToImageIndirectNV)global_table.vkGetDeviceProcAddr(device, "vkCmdCopyMemoryToImageIndirectNV");
#endif
#if defined(VK_VERSION_1_2) || defined(VK_EXT_host_query_reset)
        static constexpr std::array vkResetQueryPool_strings
        {
#if defined(VK_VERSION_1_2)
            "vkResetQueryPool",
#endif
#if defined(VK_EXT_host_query_reset)
                    "vkResetQueryPoolEXT",
#endif
        };
        for (auto vkResetQueryPool_it : vkResetQueryPool_strings)
            if ((vkResetQueryPool = (PFN_vkResetQueryPool)global_table.vkGetDeviceProcAddr(device, vkResetQueryPool_it)))
                break;
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
#if defined(VK_NV_low_latency2)
        vkGetLatencyTimingsNV = (PFN_vkGetLatencyTimingsNV)global_table.vkGetDeviceProcAddr(device, "vkGetLatencyTimingsNV");
        vkQueueNotifyOutOfBandNV = (PFN_vkQueueNotifyOutOfBandNV)global_table.vkGetDeviceProcAddr(device, "vkQueueNotifyOutOfBandNV");
        vkSetLatencyMarkerNV = (PFN_vkSetLatencyMarkerNV)global_table.vkGetDeviceProcAddr(device, "vkSetLatencyMarkerNV");
        vkSetLatencySleepModeNV = (PFN_vkSetLatencySleepModeNV)global_table.vkGetDeviceProcAddr(device, "vkSetLatencySleepModeNV");
        vkLatencySleepNV = (PFN_vkLatencySleepNV)global_table.vkGetDeviceProcAddr(device, "vkLatencySleepNV");
#endif
#if defined(VK_EXT_multi_draw)
        vkCmdDrawMultiEXT = (PFN_vkCmdDrawMultiEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMultiEXT");
        vkCmdDrawMultiIndexedEXT = (PFN_vkCmdDrawMultiIndexedEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdDrawMultiIndexedEXT");
#endif
#if defined(VK_NV_fragment_shading_rate_enums)
        vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetFragmentShadingRateEnumNV");
#endif
#if defined(VK_NV_ray_tracing)
        vkCompileDeferredNV = (PFN_vkCompileDeferredNV)global_table.vkGetDeviceProcAddr(device, "vkCompileDeferredNV");
        vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)global_table.vkGetDeviceProcAddr(device, "vkGetAccelerationStructureHandleNV");
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
#if defined(VK_VERSION_1_3) || defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
        static constexpr std::array vkCmdSetDepthCompareOp_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetDepthCompareOp",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetDepthCompareOpEXT",
#endif
        };
        for (auto vkCmdSetDepthCompareOp_it : vkCmdSetDepthCompareOp_strings)
            if ((vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp)global_table.vkGetDeviceProcAddr(device, vkCmdSetDepthCompareOp_it)))
                break;
        static constexpr std::array vkCmdSetPrimitiveTopology_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetPrimitiveTopology",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetPrimitiveTopologyEXT",
#endif
        };
        for (auto vkCmdSetPrimitiveTopology_it : vkCmdSetPrimitiveTopology_strings)
            if ((vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology)global_table.vkGetDeviceProcAddr(device, vkCmdSetPrimitiveTopology_it)))
                break;
        static constexpr std::array vkCmdSetDepthWriteEnable_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetDepthWriteEnable",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetDepthWriteEnableEXT",
#endif
        };
        for (auto vkCmdSetDepthWriteEnable_it : vkCmdSetDepthWriteEnable_strings)
            if ((vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable)global_table.vkGetDeviceProcAddr(device, vkCmdSetDepthWriteEnable_it)))
                break;
        static constexpr std::array vkCmdSetViewportWithCount_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetViewportWithCount",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetViewportWithCountEXT",
#endif
        };
        for (auto vkCmdSetViewportWithCount_it : vkCmdSetViewportWithCount_strings)
            if ((vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount)global_table.vkGetDeviceProcAddr(device, vkCmdSetViewportWithCount_it)))
                break;
        static constexpr std::array vkCmdSetCullMode_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetCullMode",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetCullModeEXT",
#endif
        };
        for (auto vkCmdSetCullMode_it : vkCmdSetCullMode_strings)
            if ((vkCmdSetCullMode = (PFN_vkCmdSetCullMode)global_table.vkGetDeviceProcAddr(device, vkCmdSetCullMode_it)))
                break;
        static constexpr std::array vkCmdSetFrontFace_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetFrontFace",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetFrontFaceEXT",
#endif
        };
        for (auto vkCmdSetFrontFace_it : vkCmdSetFrontFace_strings)
            if ((vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace)global_table.vkGetDeviceProcAddr(device, vkCmdSetFrontFace_it)))
                break;
        static constexpr std::array vkCmdSetScissorWithCount_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetScissorWithCount",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetScissorWithCountEXT",
#endif
        };
        for (auto vkCmdSetScissorWithCount_it : vkCmdSetScissorWithCount_strings)
            if ((vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount)global_table.vkGetDeviceProcAddr(device, vkCmdSetScissorWithCount_it)))
                break;
        static constexpr std::array vkCmdBindVertexBuffers2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdBindVertexBuffers2",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdBindVertexBuffers2EXT",
#endif
        };
        for (auto vkCmdBindVertexBuffers2_it : vkCmdBindVertexBuffers2_strings)
            if ((vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2)global_table.vkGetDeviceProcAddr(device, vkCmdBindVertexBuffers2_it)))
                break;
        static constexpr std::array vkCmdSetDepthTestEnable_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetDepthTestEnable",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetDepthTestEnableEXT",
#endif
        };
        for (auto vkCmdSetDepthTestEnable_it : vkCmdSetDepthTestEnable_strings)
            if ((vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable)global_table.vkGetDeviceProcAddr(device, vkCmdSetDepthTestEnable_it)))
                break;
        static constexpr std::array vkCmdSetDepthBoundsTestEnable_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetDepthBoundsTestEnable",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetDepthBoundsTestEnableEXT",
#endif
        };
        for (auto vkCmdSetDepthBoundsTestEnable_it : vkCmdSetDepthBoundsTestEnable_strings)
            if ((vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable)global_table.vkGetDeviceProcAddr(device, vkCmdSetDepthBoundsTestEnable_it)))
                break;
        static constexpr std::array vkCmdSetStencilTestEnable_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetStencilTestEnable",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetStencilTestEnableEXT",
#endif
        };
        for (auto vkCmdSetStencilTestEnable_it : vkCmdSetStencilTestEnable_strings)
            if ((vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable)global_table.vkGetDeviceProcAddr(device, vkCmdSetStencilTestEnable_it)))
                break;
        static constexpr std::array vkCmdSetStencilOp_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetStencilOp",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
                    "vkCmdSetStencilOpEXT",
#endif
        };
        for (auto vkCmdSetStencilOp_it : vkCmdSetStencilOp_strings)
            if ((vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp)global_table.vkGetDeviceProcAddr(device, vkCmdSetStencilOp_it)))
                break;
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
#if defined(VK_EXT_display_control)
        vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)global_table.vkGetDeviceProcAddr(device, "vkRegisterDeviceEventEXT");
        vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)global_table.vkGetDeviceProcAddr(device, "vkRegisterDisplayEventEXT");
        vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)global_table.vkGetDeviceProcAddr(device, "vkDisplayPowerControlEXT");
        vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainCounterEXT");
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
#if defined(VK_QNX_external_memory_screen_buffer)
        vkGetScreenBufferPropertiesQNX = (PFN_vkGetScreenBufferPropertiesQNX)global_table.vkGetDeviceProcAddr(device, "vkGetScreenBufferPropertiesQNX");
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_buffer_device_address)
        static constexpr std::array vkGetDeviceMemoryOpaqueCaptureAddress_strings
        {
#if defined(VK_VERSION_1_2)
            "vkGetDeviceMemoryOpaqueCaptureAddress",
#endif
#if defined(VK_KHR_buffer_device_address)
                    "vkGetDeviceMemoryOpaqueCaptureAddressKHR",
#endif
        };
        for (auto vkGetDeviceMemoryOpaqueCaptureAddress_it : vkGetDeviceMemoryOpaqueCaptureAddress_strings)
            if ((vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)global_table.vkGetDeviceProcAddr(device, vkGetDeviceMemoryOpaqueCaptureAddress_it)))
                break;
        static constexpr std::array vkGetBufferOpaqueCaptureAddress_strings
        {
#if defined(VK_VERSION_1_2)
            "vkGetBufferOpaqueCaptureAddress",
#endif
#if defined(VK_KHR_buffer_device_address)
                    "vkGetBufferOpaqueCaptureAddressKHR",
#endif
        };
        for (auto vkGetBufferOpaqueCaptureAddress_it : vkGetBufferOpaqueCaptureAddress_strings)
            if ((vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)global_table.vkGetDeviceProcAddr(device, vkGetBufferOpaqueCaptureAddress_it)))
                break;
#endif
#if defined(VK_NV_memory_decompression)
        vkCmdDecompressMemoryNV = (PFN_vkCmdDecompressMemoryNV)global_table.vkGetDeviceProcAddr(device, "vkCmdDecompressMemoryNV");
        vkCmdDecompressMemoryIndirectCountNV = (PFN_vkCmdDecompressMemoryIndirectCountNV)global_table.vkGetDeviceProcAddr(device, "vkCmdDecompressMemoryIndirectCountNV");
#endif
#if defined(VK_NV_external_memory_win32)
        vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryWin32HandleNV");
#endif
#if defined(VK_NV_ray_tracing) || defined(VK_KHR_ray_tracing_pipeline)
        static constexpr std::array vkGetRayTracingShaderGroupHandlesKHR_strings
        {
#if defined(VK_KHR_ray_tracing_pipeline)
            "vkGetRayTracingShaderGroupHandlesKHR",
#endif
#if defined(VK_NV_ray_tracing)
                    "vkGetRayTracingShaderGroupHandlesNV",
#endif
        };
        for (auto vkGetRayTracingShaderGroupHandlesKHR_it : vkGetRayTracingShaderGroupHandlesKHR_strings)
            if ((vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)global_table.vkGetDeviceProcAddr(device, vkGetRayTracingShaderGroupHandlesKHR_it)))
                break;
#endif
#if defined(VK_EXT_pageable_device_local_memory)
        vkSetDeviceMemoryPriorityEXT = (PFN_vkSetDeviceMemoryPriorityEXT)global_table.vkGetDeviceProcAddr(device, "vkSetDeviceMemoryPriorityEXT");
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_create_renderpass2)
        static constexpr std::array vkCmdBeginRenderPass2_strings
        {
#if defined(VK_VERSION_1_2)
            "vkCmdBeginRenderPass2",
#endif
#if defined(VK_KHR_create_renderpass2)
                    "vkCmdBeginRenderPass2KHR",
#endif
        };
        for (auto vkCmdBeginRenderPass2_it : vkCmdBeginRenderPass2_strings)
            if ((vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)global_table.vkGetDeviceProcAddr(device, vkCmdBeginRenderPass2_it)))
                break;
        static constexpr std::array vkCreateRenderPass2_strings
        {
#if defined(VK_VERSION_1_2)
            "vkCreateRenderPass2",
#endif
#if defined(VK_KHR_create_renderpass2)
                    "vkCreateRenderPass2KHR",
#endif
        };
        for (auto vkCreateRenderPass2_it : vkCreateRenderPass2_strings)
            if ((vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)global_table.vkGetDeviceProcAddr(device, vkCreateRenderPass2_it)))
                break;
        static constexpr std::array vkCmdNextSubpass2_strings
        {
#if defined(VK_VERSION_1_2)
            "vkCmdNextSubpass2",
#endif
#if defined(VK_KHR_create_renderpass2)
                    "vkCmdNextSubpass2KHR",
#endif
        };
        for (auto vkCmdNextSubpass2_it : vkCmdNextSubpass2_strings)
            if ((vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)global_table.vkGetDeviceProcAddr(device, vkCmdNextSubpass2_it)))
                break;
        static constexpr std::array vkCmdEndRenderPass2_strings
        {
#if defined(VK_VERSION_1_2)
            "vkCmdEndRenderPass2",
#endif
#if defined(VK_KHR_create_renderpass2)
                    "vkCmdEndRenderPass2KHR",
#endif
        };
        for (auto vkCmdEndRenderPass2_it : vkCmdEndRenderPass2_strings)
            if ((vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)global_table.vkGetDeviceProcAddr(device, vkCmdEndRenderPass2_it)))
                break;
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)global_table.vkGetDeviceProcAddr(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
        vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)
        static constexpr std::array vkCmdDrawIndirectCount_strings
        {
#if defined(VK_VERSION_1_2)
            "vkCmdDrawIndirectCount",
#endif
#if defined(VK_KHR_draw_indirect_count)
                    "vkCmdDrawIndirectCountKHR",
#endif
#if defined(VK_AMD_draw_indirect_count)
                    "vkCmdDrawIndirectCountAMD",
#endif
        };
        for (auto vkCmdDrawIndirectCount_it : vkCmdDrawIndirectCount_strings)
            if ((vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)global_table.vkGetDeviceProcAddr(device, vkCmdDrawIndirectCount_it)))
                break;
        static constexpr std::array vkCmdDrawIndexedIndirectCount_strings
        {
#if defined(VK_VERSION_1_2)
            "vkCmdDrawIndexedIndirectCount",
#endif
#if defined(VK_KHR_draw_indirect_count)
                    "vkCmdDrawIndexedIndirectCountKHR",
#endif
#if defined(VK_AMD_draw_indirect_count)
                    "vkCmdDrawIndexedIndirectCountAMD",
#endif
        };
        for (auto vkCmdDrawIndexedIndirectCount_it : vkCmdDrawIndexedIndirectCount_strings)
            if ((vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)global_table.vkGetDeviceProcAddr(device, vkCmdDrawIndexedIndirectCount_it)))
                break;
#endif
#if defined(VK_EXT_host_image_copy)
        vkCopyMemoryToImageEXT = (PFN_vkCopyMemoryToImageEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyMemoryToImageEXT");
        vkCopyImageToMemoryEXT = (PFN_vkCopyImageToMemoryEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyImageToMemoryEXT");
        vkCopyImageToImageEXT = (PFN_vkCopyImageToImageEXT)global_table.vkGetDeviceProcAddr(device, "vkCopyImageToImageEXT");
        vkTransitionImageLayoutEXT = (PFN_vkTransitionImageLayoutEXT)global_table.vkGetDeviceProcAddr(device, "vkTransitionImageLayoutEXT");
#endif
#if defined(VK_EXT_external_memory_host)
        vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)global_table.vkGetDeviceProcAddr(device, "vkGetMemoryHostPointerPropertiesEXT");
#endif
#if defined(VK_NV_shading_rate_image)
        vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetViewportShadingRatePaletteNV");
        vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCoarseSampleOrderNV");
        vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)global_table.vkGetDeviceProcAddr(device, "vkCmdBindShadingRateImageNV");
#endif
#if defined(VK_KHR_external_semaphore_fd)
        vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)global_table.vkGetDeviceProcAddr(device, "vkImportSemaphoreFdKHR");
        vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreFdKHR");
#endif
#if defined(VK_KHR_performance_query)
        vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)global_table.vkGetDeviceProcAddr(device, "vkReleaseProfilingLockKHR");
        vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)global_table.vkGetDeviceProcAddr(device, "vkAcquireProfilingLockKHR");
#endif
#if defined(VK_EXT_color_write_enable)
        vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetColorWriteEnableEXT");
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_device_group)
        static constexpr std::array vkGetDeviceGroupPeerMemoryFeatures_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetDeviceGroupPeerMemoryFeatures",
#endif
#if defined(VK_KHR_device_group)
                    "vkGetDeviceGroupPeerMemoryFeaturesKHR",
#endif
        };
        for (auto vkGetDeviceGroupPeerMemoryFeatures_it : vkGetDeviceGroupPeerMemoryFeatures_strings)
            if ((vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)global_table.vkGetDeviceProcAddr(device, vkGetDeviceGroupPeerMemoryFeatures_it)))
                break;
        static constexpr std::array vkCmdSetDeviceMask_strings
        {
#if defined(VK_VERSION_1_1)
            "vkCmdSetDeviceMask",
#endif
#if defined(VK_KHR_device_group)
                    "vkCmdSetDeviceMaskKHR",
#endif
        };
        for (auto vkCmdSetDeviceMask_it : vkCmdSetDeviceMask_strings)
            if ((vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)global_table.vkGetDeviceProcAddr(device, vkCmdSetDeviceMask_it)))
                break;
        static constexpr std::array vkCmdDispatchBase_strings
        {
#if defined(VK_VERSION_1_1)
            "vkCmdDispatchBase",
#endif
#if defined(VK_KHR_device_group)
                    "vkCmdDispatchBaseKHR",
#endif
        };
        for (auto vkCmdDispatchBase_it : vkCmdDispatchBase_strings)
            if ((vkCmdDispatchBase = (PFN_vkCmdDispatchBase)global_table.vkGetDeviceProcAddr(device, vkCmdDispatchBase_it)))
                break;
#endif
#if defined(VK_NV_external_memory_sci_buf)
        vkGetMemorySciBufNV = (PFN_vkGetMemorySciBufNV)global_table.vkGetDeviceProcAddr(device, "vkGetMemorySciBufNV");
#endif
#if defined(VK_EXT_full_screen_exclusive)
        vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)global_table.vkGetDeviceProcAddr(device, "vkReleaseFullScreenExclusiveModeEXT");
        vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)global_table.vkGetDeviceProcAddr(device, "vkAcquireFullScreenExclusiveModeEXT");
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_maintenance3)
        static constexpr std::array vkGetDescriptorSetLayoutSupport_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetDescriptorSetLayoutSupport",
#endif
#if defined(VK_KHR_maintenance3)
                    "vkGetDescriptorSetLayoutSupportKHR",
#endif
        };
        for (auto vkGetDescriptorSetLayoutSupport_it : vkGetDescriptorSetLayoutSupport_strings)
            if ((vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)global_table.vkGetDeviceProcAddr(device, vkGetDescriptorSetLayoutSupport_it)))
                break;
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
#if defined(VK_VERSION_1_1) || defined(VK_KHR_maintenance1)
        static constexpr std::array vkTrimCommandPool_strings
        {
#if defined(VK_VERSION_1_1)
            "vkTrimCommandPool",
#endif
#if defined(VK_KHR_maintenance1)
                    "vkTrimCommandPoolKHR",
#endif
        };
        for (auto vkTrimCommandPool_it : vkTrimCommandPool_strings)
            if ((vkTrimCommandPool = (PFN_vkTrimCommandPool)global_table.vkGetDeviceProcAddr(device, vkTrimCommandPool_it)))
                break;
#endif
#if defined(VK_KHR_dynamic_rendering_local_read)
        vkCmdSetRenderingAttachmentLocationsKHR = (PFN_vkCmdSetRenderingAttachmentLocationsKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRenderingAttachmentLocationsKHR");
        vkCmdSetRenderingInputAttachmentIndicesKHR = (PFN_vkCmdSetRenderingInputAttachmentIndicesKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetRenderingInputAttachmentIndicesKHR");
#endif
#if defined(VK_HUAWEI_invocation_mask)
        vkCmdBindInvocationMaskHUAWEI = (PFN_vkCmdBindInvocationMaskHUAWEI)global_table.vkGetDeviceProcAddr(device, "vkCmdBindInvocationMaskHUAWEI");
#endif
#if defined(VK_QCOM_tile_properties)
        vkGetDynamicRenderingTilePropertiesQCOM = (PFN_vkGetDynamicRenderingTilePropertiesQCOM)global_table.vkGetDeviceProcAddr(device, "vkGetDynamicRenderingTilePropertiesQCOM");
        vkGetFramebufferTilePropertiesQCOM = (PFN_vkGetFramebufferTilePropertiesQCOM)global_table.vkGetDeviceProcAddr(device, "vkGetFramebufferTilePropertiesQCOM");
#endif
#if defined(VK_VERSION_1_1)
        vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceQueue2");
#endif
#if defined(VK_VERSION_1_3) || defined(VK_KHR_maintenance4)
        static constexpr std::array vkGetDeviceBufferMemoryRequirements_strings
        {
#if defined(VK_VERSION_1_3)
            "vkGetDeviceBufferMemoryRequirements",
#endif
#if defined(VK_KHR_maintenance4)
                    "vkGetDeviceBufferMemoryRequirementsKHR",
#endif
        };
        for (auto vkGetDeviceBufferMemoryRequirements_it : vkGetDeviceBufferMemoryRequirements_strings)
            if ((vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements)global_table.vkGetDeviceProcAddr(device, vkGetDeviceBufferMemoryRequirements_it)))
                break;
        static constexpr std::array vkGetDeviceImageMemoryRequirements_strings
        {
#if defined(VK_VERSION_1_3)
            "vkGetDeviceImageMemoryRequirements",
#endif
#if defined(VK_KHR_maintenance4)
                    "vkGetDeviceImageMemoryRequirementsKHR",
#endif
        };
        for (auto vkGetDeviceImageMemoryRequirements_it : vkGetDeviceImageMemoryRequirements_strings)
            if ((vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements)global_table.vkGetDeviceProcAddr(device, vkGetDeviceImageMemoryRequirements_it)))
                break;
        static constexpr std::array vkGetDeviceImageSparseMemoryRequirements_strings
        {
#if defined(VK_VERSION_1_3)
            "vkGetDeviceImageSparseMemoryRequirements",
#endif
#if defined(VK_KHR_maintenance4)
                    "vkGetDeviceImageSparseMemoryRequirementsKHR",
#endif
        };
        for (auto vkGetDeviceImageSparseMemoryRequirements_it : vkGetDeviceImageSparseMemoryRequirements_strings)
            if ((vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements)global_table.vkGetDeviceProcAddr(device, vkGetDeviceImageSparseMemoryRequirements_it)))
                break;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_get_memory_requirements2)
        static constexpr std::array vkGetBufferMemoryRequirements2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetBufferMemoryRequirements2",
#endif
#if defined(VK_KHR_get_memory_requirements2)
                    "vkGetBufferMemoryRequirements2KHR",
#endif
        };
        for (auto vkGetBufferMemoryRequirements2_it : vkGetBufferMemoryRequirements2_strings)
            if ((vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)global_table.vkGetDeviceProcAddr(device, vkGetBufferMemoryRequirements2_it)))
                break;
        static constexpr std::array vkGetImageMemoryRequirements2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetImageMemoryRequirements2",
#endif
#if defined(VK_KHR_get_memory_requirements2)
                    "vkGetImageMemoryRequirements2KHR",
#endif
        };
        for (auto vkGetImageMemoryRequirements2_it : vkGetImageMemoryRequirements2_strings)
            if ((vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)global_table.vkGetDeviceProcAddr(device, vkGetImageMemoryRequirements2_it)))
                break;
        static constexpr std::array vkGetImageSparseMemoryRequirements2_strings
        {
#if defined(VK_VERSION_1_1)
            "vkGetImageSparseMemoryRequirements2",
#endif
#if defined(VK_KHR_get_memory_requirements2)
                    "vkGetImageSparseMemoryRequirements2KHR",
#endif
        };
        for (auto vkGetImageSparseMemoryRequirements2_it : vkGetImageSparseMemoryRequirements2_strings)
            if ((vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)global_table.vkGetDeviceProcAddr(device, vkGetImageSparseMemoryRequirements2_it)))
                break;
#endif
#if defined(VK_EXT_depth_bias_control)
        vkCmdSetDepthBias2EXT = (PFN_vkCmdSetDepthBias2EXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDepthBias2EXT");
#endif
#if defined(VK_NVX_image_view_handle)
        vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)global_table.vkGetDeviceProcAddr(device, "vkGetImageViewAddressNVX");
        vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)global_table.vkGetDeviceProcAddr(device, "vkGetImageViewHandleNVX");
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_sampler_ycbcr_conversion)
        static constexpr std::array vkCreateSamplerYcbcrConversion_strings
        {
#if defined(VK_VERSION_1_1)
            "vkCreateSamplerYcbcrConversion",
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion)
                    "vkCreateSamplerYcbcrConversionKHR",
#endif
        };
        for (auto vkCreateSamplerYcbcrConversion_it : vkCreateSamplerYcbcrConversion_strings)
            if ((vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)global_table.vkGetDeviceProcAddr(device, vkCreateSamplerYcbcrConversion_it)))
                break;
        static constexpr std::array vkDestroySamplerYcbcrConversion_strings
        {
#if defined(VK_VERSION_1_1)
            "vkDestroySamplerYcbcrConversion",
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion)
                    "vkDestroySamplerYcbcrConversionKHR",
#endif
        };
        for (auto vkDestroySamplerYcbcrConversion_it : vkDestroySamplerYcbcrConversion_strings)
            if ((vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)global_table.vkGetDeviceProcAddr(device, vkDestroySamplerYcbcrConversion_it)))
                break;
#endif
#if defined(VK_NV_cuda_kernel_launch)
        vkDestroyCudaModuleNV = (PFN_vkDestroyCudaModuleNV)global_table.vkGetDeviceProcAddr(device, "vkDestroyCudaModuleNV");
        vkCreateCudaFunctionNV = (PFN_vkCreateCudaFunctionNV)global_table.vkGetDeviceProcAddr(device, "vkCreateCudaFunctionNV");
        vkCreateCudaModuleNV = (PFN_vkCreateCudaModuleNV)global_table.vkGetDeviceProcAddr(device, "vkCreateCudaModuleNV");
        vkGetCudaModuleCacheNV = (PFN_vkGetCudaModuleCacheNV)global_table.vkGetDeviceProcAddr(device, "vkGetCudaModuleCacheNV");
        vkDestroyCudaFunctionNV = (PFN_vkDestroyCudaFunctionNV)global_table.vkGetDeviceProcAddr(device, "vkDestroyCudaFunctionNV");
        vkCmdCudaLaunchKernelNV = (PFN_vkCmdCudaLaunchKernelNV)global_table.vkGetDeviceProcAddr(device, "vkCmdCudaLaunchKernelNV");
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)
        static constexpr std::array vkCreateDescriptorUpdateTemplate_strings
        {
#if defined(VK_VERSION_1_1)
            "vkCreateDescriptorUpdateTemplate",
#endif
#if defined(VK_KHR_descriptor_update_template)
                    "vkCreateDescriptorUpdateTemplateKHR",
#endif
        };
        for (auto vkCreateDescriptorUpdateTemplate_it : vkCreateDescriptorUpdateTemplate_strings)
            if ((vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)global_table.vkGetDeviceProcAddr(device, vkCreateDescriptorUpdateTemplate_it)))
                break;
        static constexpr std::array vkDestroyDescriptorUpdateTemplate_strings
        {
#if defined(VK_VERSION_1_1)
            "vkDestroyDescriptorUpdateTemplate",
#endif
#if defined(VK_KHR_descriptor_update_template)
                    "vkDestroyDescriptorUpdateTemplateKHR",
#endif
        };
        for (auto vkDestroyDescriptorUpdateTemplate_it : vkDestroyDescriptorUpdateTemplate_strings)
            if ((vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)global_table.vkGetDeviceProcAddr(device, vkDestroyDescriptorUpdateTemplate_it)))
                break;
        static constexpr std::array vkUpdateDescriptorSetWithTemplate_strings
        {
#if defined(VK_VERSION_1_1)
            "vkUpdateDescriptorSetWithTemplate",
#endif
#if defined(VK_KHR_descriptor_update_template)
                    "vkUpdateDescriptorSetWithTemplateKHR",
#endif
        };
        for (auto vkUpdateDescriptorSetWithTemplate_it : vkUpdateDescriptorSetWithTemplate_strings)
            if ((vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)global_table.vkGetDeviceProcAddr(device, vkUpdateDescriptorSetWithTemplate_it)))
                break;
#endif
#if defined(VK_KHR_video_encode_queue)
        vkGetEncodedVideoSessionParametersKHR = (PFN_vkGetEncodedVideoSessionParametersKHR)global_table.vkGetDeviceProcAddr(device, "vkGetEncodedVideoSessionParametersKHR");
        vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdEncodeVideoKHR");
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_timeline_semaphore)
        static constexpr std::array vkWaitSemaphores_strings
        {
#if defined(VK_VERSION_1_2)
            "vkWaitSemaphores",
#endif
#if defined(VK_KHR_timeline_semaphore)
                    "vkWaitSemaphoresKHR",
#endif
        };
        for (auto vkWaitSemaphores_it : vkWaitSemaphores_strings)
            if ((vkWaitSemaphores = (PFN_vkWaitSemaphores)global_table.vkGetDeviceProcAddr(device, vkWaitSemaphores_it)))
                break;
        static constexpr std::array vkGetSemaphoreCounterValue_strings
        {
#if defined(VK_VERSION_1_2)
            "vkGetSemaphoreCounterValue",
#endif
#if defined(VK_KHR_timeline_semaphore)
                    "vkGetSemaphoreCounterValueKHR",
#endif
        };
        for (auto vkGetSemaphoreCounterValue_it : vkGetSemaphoreCounterValue_strings)
            if ((vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)global_table.vkGetDeviceProcAddr(device, vkGetSemaphoreCounterValue_it)))
                break;
        static constexpr std::array vkSignalSemaphore_strings
        {
#if defined(VK_VERSION_1_2)
            "vkSignalSemaphore",
#endif
#if defined(VK_KHR_timeline_semaphore)
                    "vkSignalSemaphoreKHR",
#endif
        };
        for (auto vkSignalSemaphore_it : vkSignalSemaphore_strings)
            if ((vkSignalSemaphore = (PFN_vkSignalSemaphore)global_table.vkGetDeviceProcAddr(device, vkSignalSemaphore_it)))
                break;
#endif
#if defined(VK_VERSION_1_2) || defined(VK_EXT_buffer_device_address) || defined(VK_KHR_buffer_device_address)
        static constexpr std::array vkGetBufferDeviceAddress_strings
        {
#if defined(VK_VERSION_1_2)
            "vkGetBufferDeviceAddress",
#endif
#if defined(VK_KHR_buffer_device_address)
                    "vkGetBufferDeviceAddressKHR",
#endif
#if defined(VK_EXT_buffer_device_address)
                    "vkGetBufferDeviceAddressEXT",
#endif
        };
        for (auto vkGetBufferDeviceAddress_it : vkGetBufferDeviceAddress_strings)
            if ((vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)global_table.vkGetDeviceProcAddr(device, vkGetBufferDeviceAddress_it)))
                break;
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
#if defined(VK_VERSION_1_3) || defined(VK_EXT_private_data)
        static constexpr std::array vkCreatePrivateDataSlot_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCreatePrivateDataSlot",
#endif
#if defined(VK_EXT_private_data)
                    "vkCreatePrivateDataSlotEXT",
#endif
        };
        for (auto vkCreatePrivateDataSlot_it : vkCreatePrivateDataSlot_strings)
            if ((vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot)global_table.vkGetDeviceProcAddr(device, vkCreatePrivateDataSlot_it)))
                break;
        static constexpr std::array vkDestroyPrivateDataSlot_strings
        {
#if defined(VK_VERSION_1_3)
            "vkDestroyPrivateDataSlot",
#endif
#if defined(VK_EXT_private_data)
                    "vkDestroyPrivateDataSlotEXT",
#endif
        };
        for (auto vkDestroyPrivateDataSlot_it : vkDestroyPrivateDataSlot_strings)
            if ((vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot)global_table.vkGetDeviceProcAddr(device, vkDestroyPrivateDataSlot_it)))
                break;
        static constexpr std::array vkSetPrivateData_strings
        {
#if defined(VK_VERSION_1_3)
            "vkSetPrivateData",
#endif
#if defined(VK_EXT_private_data)
                    "vkSetPrivateDataEXT",
#endif
        };
        for (auto vkSetPrivateData_it : vkSetPrivateData_strings)
            if ((vkSetPrivateData = (PFN_vkSetPrivateData)global_table.vkGetDeviceProcAddr(device, vkSetPrivateData_it)))
                break;
        static constexpr std::array vkGetPrivateData_strings
        {
#if defined(VK_VERSION_1_3)
            "vkGetPrivateData",
#endif
#if defined(VK_EXT_private_data)
                    "vkGetPrivateDataEXT",
#endif
        };
        for (auto vkGetPrivateData_it : vkGetPrivateData_strings)
            if ((vkGetPrivateData = (PFN_vkGetPrivateData)global_table.vkGetDeviceProcAddr(device, vkGetPrivateData_it)))
                break;
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
#if defined(VK_VERSION_1_3) || defined(VK_KHR_copy_commands2)
        static constexpr std::array vkCmdCopyBuffer2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdCopyBuffer2",
#endif
#if defined(VK_KHR_copy_commands2)
                    "vkCmdCopyBuffer2KHR",
#endif
        };
        for (auto vkCmdCopyBuffer2_it : vkCmdCopyBuffer2_strings)
            if ((vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2)global_table.vkGetDeviceProcAddr(device, vkCmdCopyBuffer2_it)))
                break;
        static constexpr std::array vkCmdCopyImage2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdCopyImage2",
#endif
#if defined(VK_KHR_copy_commands2)
                    "vkCmdCopyImage2KHR",
#endif
        };
        for (auto vkCmdCopyImage2_it : vkCmdCopyImage2_strings)
            if ((vkCmdCopyImage2 = (PFN_vkCmdCopyImage2)global_table.vkGetDeviceProcAddr(device, vkCmdCopyImage2_it)))
                break;
        static constexpr std::array vkCmdCopyBufferToImage2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdCopyBufferToImage2",
#endif
#if defined(VK_KHR_copy_commands2)
                    "vkCmdCopyBufferToImage2KHR",
#endif
        };
        for (auto vkCmdCopyBufferToImage2_it : vkCmdCopyBufferToImage2_strings)
            if ((vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2)global_table.vkGetDeviceProcAddr(device, vkCmdCopyBufferToImage2_it)))
                break;
        static constexpr std::array vkCmdCopyImageToBuffer2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdCopyImageToBuffer2",
#endif
#if defined(VK_KHR_copy_commands2)
                    "vkCmdCopyImageToBuffer2KHR",
#endif
        };
        for (auto vkCmdCopyImageToBuffer2_it : vkCmdCopyImageToBuffer2_strings)
            if ((vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2)global_table.vkGetDeviceProcAddr(device, vkCmdCopyImageToBuffer2_it)))
                break;
        static constexpr std::array vkCmdBlitImage2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdBlitImage2",
#endif
#if defined(VK_KHR_copy_commands2)
                    "vkCmdBlitImage2KHR",
#endif
        };
        for (auto vkCmdBlitImage2_it : vkCmdBlitImage2_strings)
            if ((vkCmdBlitImage2 = (PFN_vkCmdBlitImage2)global_table.vkGetDeviceProcAddr(device, vkCmdBlitImage2_it)))
                break;
        static constexpr std::array vkCmdResolveImage2_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdResolveImage2",
#endif
#if defined(VK_KHR_copy_commands2)
                    "vkCmdResolveImage2KHR",
#endif
        };
        for (auto vkCmdResolveImage2_it : vkCmdResolveImage2_strings)
            if ((vkCmdResolveImage2 = (PFN_vkCmdResolveImage2)global_table.vkGetDeviceProcAddr(device, vkCmdResolveImage2_it)))
                break;
#endif
#if defined(VK_KHR_swapchain)
        vkQueuePresentKHR = (PFN_vkQueuePresentKHR)global_table.vkGetDeviceProcAddr(device, "vkQueuePresentKHR");
        vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateSwapchainKHR");
        vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)global_table.vkGetDeviceProcAddr(device, "vkDestroySwapchainKHR");
        vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainImagesKHR");
        vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)global_table.vkGetDeviceProcAddr(device, "vkAcquireNextImageKHR");
#endif
#if defined(VK_VERSION_1_3) || defined(VK_KHR_dynamic_rendering)
        static constexpr std::array vkCmdBeginRendering_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdBeginRendering",
#endif
#if defined(VK_KHR_dynamic_rendering)
                    "vkCmdBeginRenderingKHR",
#endif
        };
        for (auto vkCmdBeginRendering_it : vkCmdBeginRendering_strings)
            if ((vkCmdBeginRendering = (PFN_vkCmdBeginRendering)global_table.vkGetDeviceProcAddr(device, vkCmdBeginRendering_it)))
                break;
        static constexpr std::array vkCmdEndRendering_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdEndRendering",
#endif
#if defined(VK_KHR_dynamic_rendering)
                    "vkCmdEndRenderingKHR",
#endif
        };
        for (auto vkCmdEndRendering_it : vkCmdEndRendering_strings)
            if ((vkCmdEndRendering = (PFN_vkCmdEndRendering)global_table.vkGetDeviceProcAddr(device, vkCmdEndRendering_it)))
                break;
#endif
#if defined(VK_KHR_ray_tracing_maintenance1)
        vkCmdTraceRaysIndirect2KHR = (PFN_vkCmdTraceRaysIndirect2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdTraceRaysIndirect2KHR");
#endif
#if defined(VK_VERSION_1_3) || defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
        static constexpr std::array vkCmdSetRasterizerDiscardEnable_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetRasterizerDiscardEnable",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
                    "vkCmdSetRasterizerDiscardEnableEXT",
#endif
        };
        for (auto vkCmdSetRasterizerDiscardEnable_it : vkCmdSetRasterizerDiscardEnable_strings)
            if ((vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable)global_table.vkGetDeviceProcAddr(device, vkCmdSetRasterizerDiscardEnable_it)))
                break;
        static constexpr std::array vkCmdSetDepthBiasEnable_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetDepthBiasEnable",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
                    "vkCmdSetDepthBiasEnableEXT",
#endif
        };
        for (auto vkCmdSetDepthBiasEnable_it : vkCmdSetDepthBiasEnable_strings)
            if ((vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable)global_table.vkGetDeviceProcAddr(device, vkCmdSetDepthBiasEnable_it)))
                break;
        static constexpr std::array vkCmdSetPrimitiveRestartEnable_strings
        {
#if defined(VK_VERSION_1_3)
            "vkCmdSetPrimitiveRestartEnable",
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
                    "vkCmdSetPrimitiveRestartEnableEXT",
#endif
        };
        for (auto vkCmdSetPrimitiveRestartEnable_it : vkCmdSetPrimitiveRestartEnable_strings)
            if ((vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable)global_table.vkGetDeviceProcAddr(device, vkCmdSetPrimitiveRestartEnable_it)))
                break;
#endif
#if defined(VK_KHR_fragment_shading_rate)
        vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdSetFragmentShadingRateKHR");
#endif
#if defined(VKSC_VERSION_1_0)
        vkGetCommandPoolMemoryConsumption = (PFN_vkGetCommandPoolMemoryConsumption)global_table.vkGetDeviceProcAddr(device, "vkGetCommandPoolMemoryConsumption");
        vkGetFaultData = (PFN_vkGetFaultData)global_table.vkGetDeviceProcAddr(device, "vkGetFaultData");
#endif
#if defined(VK_KHR_maintenance6)
        vkCmdPushDescriptorSetWithTemplate2KHR = (PFN_vkCmdPushDescriptorSetWithTemplate2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSetWithTemplate2KHR");
        vkCmdBindDescriptorSets2KHR = (PFN_vkCmdBindDescriptorSets2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBindDescriptorSets2KHR");
        vkCmdPushDescriptorSet2KHR = (PFN_vkCmdPushDescriptorSet2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSet2KHR");
        vkCmdPushConstants2KHR = (PFN_vkCmdPushConstants2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdPushConstants2KHR");
        vkCmdSetDescriptorBufferOffsets2EXT = (PFN_vkCmdSetDescriptorBufferOffsets2EXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDescriptorBufferOffsets2EXT");
        vkCmdBindDescriptorBufferEmbeddedSamplers2EXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT)global_table.vkGetDeviceProcAddr(device, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
#endif
#if defined(VK_KHR_maintenance5)
        vkGetDeviceImageSubresourceLayoutKHR = (PFN_vkGetDeviceImageSubresourceLayoutKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceImageSubresourceLayoutKHR");
        vkCmdBindIndexBuffer2KHR = (PFN_vkCmdBindIndexBuffer2KHR)global_table.vkGetDeviceProcAddr(device, "vkCmdBindIndexBuffer2KHR");
        vkGetRenderingAreaGranularityKHR = (PFN_vkGetRenderingAreaGranularityKHR)global_table.vkGetDeviceProcAddr(device, "vkGetRenderingAreaGranularityKHR");
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group)
        vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
        vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
        vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)global_table.vkGetDeviceProcAddr(device, "vkAcquireNextImage2KHR");
#endif
#if defined(VK_KHR_display_swapchain)
        vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)global_table.vkGetDeviceProcAddr(device, "vkCreateSharedSwapchainsKHR");
#endif
#if defined(VK_VALVE_descriptor_set_host_mapping)
        vkGetDescriptorSetHostMappingVALVE = (PFN_vkGetDescriptorSetHostMappingVALVE)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetHostMappingVALVE");
        vkGetDescriptorSetLayoutHostMappingInfoVALVE = (PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE)global_table.vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
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
#if defined(VK_EXT_shader_object) || defined(VK_EXT_vertex_input_dynamic_state)
        vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetVertexInputEXT");
#endif
#if defined(VK_KHR_shared_presentable_image)
        vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)global_table.vkGetDeviceProcAddr(device, "vkGetSwapchainStatusKHR");
#endif
#if defined(VK_KHR_line_rasterization) || defined(VK_EXT_line_rasterization)
        static constexpr std::array vkCmdSetLineStippleKHR_strings
        {
#if defined(VK_KHR_line_rasterization)
            "vkCmdSetLineStippleKHR",
#endif
#if defined(VK_EXT_line_rasterization)
                    "vkCmdSetLineStippleEXT",
#endif
        };
        for (auto vkCmdSetLineStippleKHR_it : vkCmdSetLineStippleKHR_strings)
            if ((vkCmdSetLineStippleKHR = (PFN_vkCmdSetLineStippleKHR)global_table.vkGetDeviceProcAddr(device, vkCmdSetLineStippleKHR_it)))
                break;
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
        vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetPatchControlPointsEXT");
        vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetLogicOpEXT");
#endif
#if defined(VK_KHR_synchronization2)
        vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)global_table.vkGetDeviceProcAddr(device, "vkCmdWriteBufferMarker2AMD");
        vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)global_table.vkGetDeviceProcAddr(device, "vkGetQueueCheckpointData2NV");
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
#if defined(VK_KHR_push_descriptor) || defined(VK_KHR_push_descriptor) || defined(VK_KHR_descriptor_update_template)
        vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#if defined(VK_NV_device_diagnostic_checkpoints)
        vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)global_table.vkGetDeviceProcAddr(device, "vkGetQueueCheckpointDataNV");
        vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetCheckpointNV");
#endif
#if defined(VK_EXT_discard_rectangles)
        vkCmdSetDiscardRectangleModeEXT = (PFN_vkCmdSetDiscardRectangleModeEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDiscardRectangleModeEXT");
        vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDiscardRectangleEXT");
        vkCmdSetDiscardRectangleEnableEXT = (PFN_vkCmdSetDiscardRectangleEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetDiscardRectangleEnableEXT");
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
#if defined(VK_EXT_calibrated_timestamps) || defined(VK_KHR_calibrated_timestamps)
        static constexpr std::array vkGetCalibratedTimestampsKHR_strings
        {
#if defined(VK_KHR_calibrated_timestamps)
            "vkGetCalibratedTimestampsKHR",
#endif
#if defined(VK_EXT_calibrated_timestamps)
                    "vkGetCalibratedTimestampsEXT",
#endif
        };
        for (auto vkGetCalibratedTimestampsKHR_it : vkGetCalibratedTimestampsKHR_strings)
            if ((vkGetCalibratedTimestampsKHR = (PFN_vkGetCalibratedTimestampsKHR)global_table.vkGetDeviceProcAddr(device, vkGetCalibratedTimestampsKHR_it)))
                break;
#endif
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
        vkCmdSetAttachmentFeedbackLoopEnableEXT = (PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT)global_table.vkGetDeviceProcAddr(device, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
#endif
#if defined(VK_NV_scissor_exclusive)
        vkCmdSetExclusiveScissorEnableNV = (PFN_vkCmdSetExclusiveScissorEnableNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetExclusiveScissorEnableNV");
        vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)global_table.vkGetDeviceProcAddr(device, "vkCmdSetExclusiveScissorNV");
#endif
#if defined(VK_EXT_host_image_copy) || defined(VK_EXT_image_compression_control) || defined(VK_KHR_maintenance5)
        static constexpr std::array vkGetImageSubresourceLayout2KHR_strings
        {
#if defined(VK_KHR_maintenance5)
            "vkGetImageSubresourceLayout2KHR",
#endif
#if defined(VK_EXT_host_image_copy) || defined(VK_EXT_image_compression_control)
                    "vkGetImageSubresourceLayout2EXT",
#endif
        };
        for (auto vkGetImageSubresourceLayout2KHR_it : vkGetImageSubresourceLayout2KHR_strings)
            if ((vkGetImageSubresourceLayout2KHR = (PFN_vkGetImageSubresourceLayout2KHR)global_table.vkGetDeviceProcAddr(device, vkGetImageSubresourceLayout2KHR_it)))
                break;
#endif
#if defined(VK_EXT_device_fault)
        vkGetDeviceFaultInfoEXT = (PFN_vkGetDeviceFaultInfoEXT)global_table.vkGetDeviceProcAddr(device, "vkGetDeviceFaultInfoEXT");
#endif
#if defined(VK_KHR_object_refresh)
        vkCmdRefreshObjectsKHR = (PFN_vkCmdRefreshObjectsKHR)global_table.vkGetDeviceProcAddr(device, "vkCmdRefreshObjectsKHR");
#endif
#if defined(VK_FUCHSIA_external_semaphore)
        vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkGetSemaphoreZirconHandleFUCHSIA");
        vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)global_table.vkGetDeviceProcAddr(device, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif
#if defined(VK_NV_external_sci_sync2)
        vkCreateSemaphoreSciSyncPoolNV = (PFN_vkCreateSemaphoreSciSyncPoolNV)global_table.vkGetDeviceProcAddr(device, "vkCreateSemaphoreSciSyncPoolNV");
        vkDestroySemaphoreSciSyncPoolNV = (PFN_vkDestroySemaphoreSciSyncPoolNV)global_table.vkGetDeviceProcAddr(device, "vkDestroySemaphoreSciSyncPoolNV");
#endif
    }

public:
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
#if defined(VK_VERSION_1_1) || defined(VK_KHR_bind_memory2)
    PFN_vkBindBufferMemory2 vkBindBufferMemory2;
    PFN_vkBindImageMemory2 vkBindImageMemory2;
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
#if defined(VK_FUCHSIA_buffer_collection)
    PFN_vkGetBufferCollectionPropertiesFUCHSIA vkGetBufferCollectionPropertiesFUCHSIA;
    PFN_vkDestroyBufferCollectionFUCHSIA vkDestroyBufferCollectionFUCHSIA;
    PFN_vkCreateBufferCollectionFUCHSIA vkCreateBufferCollectionFUCHSIA;
    PFN_vkSetBufferCollectionImageConstraintsFUCHSIA vkSetBufferCollectionImageConstraintsFUCHSIA;
    PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA vkSetBufferCollectionBufferConstraintsFUCHSIA;
#endif
#if defined(VK_NV_external_sci_sync) || defined(VK_NV_external_sci_sync2)
    PFN_vkImportFenceSciSyncObjNV vkImportFenceSciSyncObjNV;
    PFN_vkImportFenceSciSyncFenceNV vkImportFenceSciSyncFenceNV;
    PFN_vkGetFenceSciSyncFenceNV vkGetFenceSciSyncFenceNV;
    PFN_vkGetFenceSciSyncObjNV vkGetFenceSciSyncObjNV;
#endif
#if defined(VK_EXT_opacity_micromap)
    PFN_vkCreateMicromapEXT vkCreateMicromapEXT;
    PFN_vkCopyMemoryToMicromapEXT vkCopyMemoryToMicromapEXT;
    PFN_vkBuildMicromapsEXT vkBuildMicromapsEXT;
    PFN_vkCmdCopyMicromapEXT vkCmdCopyMicromapEXT;
    PFN_vkCopyMicromapToMemoryEXT vkCopyMicromapToMemoryEXT;
    PFN_vkGetMicromapBuildSizesEXT vkGetMicromapBuildSizesEXT;
    PFN_vkWriteMicromapsPropertiesEXT vkWriteMicromapsPropertiesEXT;
    PFN_vkDestroyMicromapEXT vkDestroyMicromapEXT;
    PFN_vkCmdWriteMicromapsPropertiesEXT vkCmdWriteMicromapsPropertiesEXT;
    PFN_vkCmdBuildMicromapsEXT vkCmdBuildMicromapsEXT;
    PFN_vkCopyMicromapEXT vkCopyMicromapEXT;
    PFN_vkCmdCopyMicromapToMemoryEXT vkCmdCopyMicromapToMemoryEXT;
    PFN_vkCmdCopyMemoryToMicromapEXT vkCmdCopyMemoryToMicromapEXT;
    PFN_vkGetDeviceMicromapCompatibilityEXT vkGetDeviceMicromapCompatibilityEXT;
#endif
#if defined(VK_KHR_map_memory2)
    PFN_vkUnmapMemory2KHR vkUnmapMemory2KHR;
    PFN_vkMapMemory2KHR vkMapMemory2KHR;
#endif
#if defined(VK_HUAWEI_cluster_culling_shader)
    PFN_vkCmdDrawClusterHUAWEI vkCmdDrawClusterHUAWEI;
    PFN_vkCmdDrawClusterIndirectHUAWEI vkCmdDrawClusterIndirectHUAWEI;
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
#if defined(VK_KHR_external_fence_win32)
    PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR;
    PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR;
#endif
#if defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)
    PFN_vkCmdWriteTimestamp2 vkCmdWriteTimestamp2;
    PFN_vkCmdPipelineBarrier2 vkCmdPipelineBarrier2;
    PFN_vkCmdSetEvent2 vkCmdSetEvent2;
    PFN_vkCmdResetEvent2 vkCmdResetEvent2;
    PFN_vkCmdWaitEvents2 vkCmdWaitEvents2;
    PFN_vkQueueSubmit2 vkQueueSubmit2;
#endif
#if defined(VK_KHR_ray_tracing_pipeline)
    PFN_vkCmdTraceRaysIndirectKHR vkCmdTraceRaysIndirectKHR;
    PFN_vkCmdSetRayTracingPipelineStackSizeKHR vkCmdSetRayTracingPipelineStackSizeKHR;
    PFN_vkGetRayTracingShaderGroupStackSizeKHR vkGetRayTracingShaderGroupStackSizeKHR;
    PFN_vkCmdTraceRaysKHR vkCmdTraceRaysKHR;
    PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
    PFN_vkCreateRayTracingPipelinesKHR vkCreateRayTracingPipelinesKHR;
#endif
#if defined(VK_NV_copy_memory_indirect)
    PFN_vkCmdCopyMemoryIndirectNV vkCmdCopyMemoryIndirectNV;
    PFN_vkCmdCopyMemoryToImageIndirectNV vkCmdCopyMemoryToImageIndirectNV;
#endif
#if defined(VK_VERSION_1_2) || defined(VK_EXT_host_query_reset)
    PFN_vkResetQueryPool vkResetQueryPool;
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
#if defined(VK_NV_low_latency2)
    PFN_vkGetLatencyTimingsNV vkGetLatencyTimingsNV;
    PFN_vkQueueNotifyOutOfBandNV vkQueueNotifyOutOfBandNV;
    PFN_vkSetLatencyMarkerNV vkSetLatencyMarkerNV;
    PFN_vkSetLatencySleepModeNV vkSetLatencySleepModeNV;
    PFN_vkLatencySleepNV vkLatencySleepNV;
#endif
#if defined(VK_EXT_multi_draw)
    PFN_vkCmdDrawMultiEXT vkCmdDrawMultiEXT;
    PFN_vkCmdDrawMultiIndexedEXT vkCmdDrawMultiIndexedEXT;
#endif
#if defined(VK_NV_fragment_shading_rate_enums)
    PFN_vkCmdSetFragmentShadingRateEnumNV vkCmdSetFragmentShadingRateEnumNV;
#endif
#if defined(VK_NV_ray_tracing)
    PFN_vkCompileDeferredNV vkCompileDeferredNV;
    PFN_vkGetAccelerationStructureHandleNV vkGetAccelerationStructureHandleNV;
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
#if defined(VK_VERSION_1_3) || defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state)
    PFN_vkCmdSetDepthCompareOp vkCmdSetDepthCompareOp;
    PFN_vkCmdSetPrimitiveTopology vkCmdSetPrimitiveTopology;
    PFN_vkCmdSetDepthWriteEnable vkCmdSetDepthWriteEnable;
    PFN_vkCmdSetViewportWithCount vkCmdSetViewportWithCount;
    PFN_vkCmdSetCullMode vkCmdSetCullMode;
    PFN_vkCmdSetFrontFace vkCmdSetFrontFace;
    PFN_vkCmdSetScissorWithCount vkCmdSetScissorWithCount;
    PFN_vkCmdBindVertexBuffers2 vkCmdBindVertexBuffers2;
    PFN_vkCmdSetDepthTestEnable vkCmdSetDepthTestEnable;
    PFN_vkCmdSetDepthBoundsTestEnable vkCmdSetDepthBoundsTestEnable;
    PFN_vkCmdSetStencilTestEnable vkCmdSetStencilTestEnable;
    PFN_vkCmdSetStencilOp vkCmdSetStencilOp;
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
#if defined(VK_EXT_display_control)
    PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
    PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
    PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
    PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;
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
#if defined(VK_QNX_external_memory_screen_buffer)
    PFN_vkGetScreenBufferPropertiesQNX vkGetScreenBufferPropertiesQNX;
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_buffer_device_address)
    PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress;
    PFN_vkGetBufferOpaqueCaptureAddress vkGetBufferOpaqueCaptureAddress;
#endif
#if defined(VK_NV_memory_decompression)
    PFN_vkCmdDecompressMemoryNV vkCmdDecompressMemoryNV;
    PFN_vkCmdDecompressMemoryIndirectCountNV vkCmdDecompressMemoryIndirectCountNV;
#endif
#if defined(VK_NV_external_memory_win32)
    PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV;
#endif
#if defined(VK_NV_ray_tracing) || defined(VK_KHR_ray_tracing_pipeline)
    PFN_vkGetRayTracingShaderGroupHandlesKHR vkGetRayTracingShaderGroupHandlesKHR;
#endif
#if defined(VK_EXT_pageable_device_local_memory)
    PFN_vkSetDeviceMemoryPriorityEXT vkSetDeviceMemoryPriorityEXT;
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_create_renderpass2)
    PFN_vkCmdBeginRenderPass2 vkCmdBeginRenderPass2;
    PFN_vkCreateRenderPass2 vkCreateRenderPass2;
    PFN_vkCmdNextSubpass2 vkCmdNextSubpass2;
    PFN_vkCmdEndRenderPass2 vkCmdEndRenderPass2;
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID vkGetAndroidHardwareBufferPropertiesANDROID;
    PFN_vkGetMemoryAndroidHardwareBufferANDROID vkGetMemoryAndroidHardwareBufferANDROID;
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)
    PFN_vkCmdDrawIndirectCount vkCmdDrawIndirectCount;
    PFN_vkCmdDrawIndexedIndirectCount vkCmdDrawIndexedIndirectCount;
#endif
#if defined(VK_EXT_host_image_copy)
    PFN_vkCopyMemoryToImageEXT vkCopyMemoryToImageEXT;
    PFN_vkCopyImageToMemoryEXT vkCopyImageToMemoryEXT;
    PFN_vkCopyImageToImageEXT vkCopyImageToImageEXT;
    PFN_vkTransitionImageLayoutEXT vkTransitionImageLayoutEXT;
#endif
#if defined(VK_EXT_external_memory_host)
    PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;
#endif
#if defined(VK_NV_shading_rate_image)
    PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV;
    PFN_vkCmdSetCoarseSampleOrderNV vkCmdSetCoarseSampleOrderNV;
    PFN_vkCmdBindShadingRateImageNV vkCmdBindShadingRateImageNV;
#endif
#if defined(VK_KHR_external_semaphore_fd)
    PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
    PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;
#endif
#if defined(VK_KHR_performance_query)
    PFN_vkReleaseProfilingLockKHR vkReleaseProfilingLockKHR;
    PFN_vkAcquireProfilingLockKHR vkAcquireProfilingLockKHR;
#endif
#if defined(VK_EXT_color_write_enable)
    PFN_vkCmdSetColorWriteEnableEXT vkCmdSetColorWriteEnableEXT;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_device_group)
    PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
    PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
    PFN_vkCmdDispatchBase vkCmdDispatchBase;
#endif
#if defined(VK_NV_external_memory_sci_buf)
    PFN_vkGetMemorySciBufNV vkGetMemorySciBufNV;
#endif
#if defined(VK_EXT_full_screen_exclusive)
    PFN_vkReleaseFullScreenExclusiveModeEXT vkReleaseFullScreenExclusiveModeEXT;
    PFN_vkAcquireFullScreenExclusiveModeEXT vkAcquireFullScreenExclusiveModeEXT;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_maintenance3)
    PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;
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
#if defined(VK_VERSION_1_1) || defined(VK_KHR_maintenance1)
    PFN_vkTrimCommandPool vkTrimCommandPool;
#endif
#if defined(VK_KHR_dynamic_rendering_local_read)
    PFN_vkCmdSetRenderingAttachmentLocationsKHR vkCmdSetRenderingAttachmentLocationsKHR;
    PFN_vkCmdSetRenderingInputAttachmentIndicesKHR vkCmdSetRenderingInputAttachmentIndicesKHR;
#endif
#if defined(VK_HUAWEI_invocation_mask)
    PFN_vkCmdBindInvocationMaskHUAWEI vkCmdBindInvocationMaskHUAWEI;
#endif
#if defined(VK_QCOM_tile_properties)
    PFN_vkGetDynamicRenderingTilePropertiesQCOM vkGetDynamicRenderingTilePropertiesQCOM;
    PFN_vkGetFramebufferTilePropertiesQCOM vkGetFramebufferTilePropertiesQCOM;
#endif
#if defined(VK_VERSION_1_1)
    PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
#endif
#if defined(VK_VERSION_1_3) || defined(VK_KHR_maintenance4)
    PFN_vkGetDeviceBufferMemoryRequirements vkGetDeviceBufferMemoryRequirements;
    PFN_vkGetDeviceImageMemoryRequirements vkGetDeviceImageMemoryRequirements;
    PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_get_memory_requirements2)
    PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
    PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
    PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
#endif
#if defined(VK_EXT_depth_bias_control)
    PFN_vkCmdSetDepthBias2EXT vkCmdSetDepthBias2EXT;
#endif
#if defined(VK_NVX_image_view_handle)
    PFN_vkGetImageViewAddressNVX vkGetImageViewAddressNVX;
    PFN_vkGetImageViewHandleNVX vkGetImageViewHandleNVX;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_sampler_ycbcr_conversion)
    PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
    PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
#endif
#if defined(VK_NV_cuda_kernel_launch)
    PFN_vkDestroyCudaModuleNV vkDestroyCudaModuleNV;
    PFN_vkCreateCudaFunctionNV vkCreateCudaFunctionNV;
    PFN_vkCreateCudaModuleNV vkCreateCudaModuleNV;
    PFN_vkGetCudaModuleCacheNV vkGetCudaModuleCacheNV;
    PFN_vkDestroyCudaFunctionNV vkDestroyCudaFunctionNV;
    PFN_vkCmdCudaLaunchKernelNV vkCmdCudaLaunchKernelNV;
#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)
    PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
    PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
    PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
#endif
#if defined(VK_KHR_video_encode_queue)
    PFN_vkGetEncodedVideoSessionParametersKHR vkGetEncodedVideoSessionParametersKHR;
    PFN_vkCmdEncodeVideoKHR vkCmdEncodeVideoKHR;
#endif
#if defined(VK_VERSION_1_2) || defined(VK_KHR_timeline_semaphore)
    PFN_vkWaitSemaphores vkWaitSemaphores;
    PFN_vkGetSemaphoreCounterValue vkGetSemaphoreCounterValue;
    PFN_vkSignalSemaphore vkSignalSemaphore;
#endif
#if defined(VK_VERSION_1_2) || defined(VK_EXT_buffer_device_address) || defined(VK_KHR_buffer_device_address)
    PFN_vkGetBufferDeviceAddress vkGetBufferDeviceAddress;
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
#if defined(VK_VERSION_1_3) || defined(VK_EXT_private_data)
    PFN_vkCreatePrivateDataSlot vkCreatePrivateDataSlot;
    PFN_vkDestroyPrivateDataSlot vkDestroyPrivateDataSlot;
    PFN_vkSetPrivateData vkSetPrivateData;
    PFN_vkGetPrivateData vkGetPrivateData;
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
#if defined(VK_VERSION_1_3) || defined(VK_KHR_copy_commands2)
    PFN_vkCmdCopyBuffer2 vkCmdCopyBuffer2;
    PFN_vkCmdCopyImage2 vkCmdCopyImage2;
    PFN_vkCmdCopyBufferToImage2 vkCmdCopyBufferToImage2;
    PFN_vkCmdCopyImageToBuffer2 vkCmdCopyImageToBuffer2;
    PFN_vkCmdBlitImage2 vkCmdBlitImage2;
    PFN_vkCmdResolveImage2 vkCmdResolveImage2;
#endif
#if defined(VK_KHR_swapchain)
    PFN_vkQueuePresentKHR vkQueuePresentKHR;
    PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
    PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
    PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
    PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
#endif
#if defined(VK_VERSION_1_3) || defined(VK_KHR_dynamic_rendering)
    PFN_vkCmdBeginRendering vkCmdBeginRendering;
    PFN_vkCmdEndRendering vkCmdEndRendering;
#endif
#if defined(VK_KHR_ray_tracing_maintenance1)
    PFN_vkCmdTraceRaysIndirect2KHR vkCmdTraceRaysIndirect2KHR;
#endif
#if defined(VK_VERSION_1_3) || defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
    PFN_vkCmdSetRasterizerDiscardEnable vkCmdSetRasterizerDiscardEnable;
    PFN_vkCmdSetDepthBiasEnable vkCmdSetDepthBiasEnable;
    PFN_vkCmdSetPrimitiveRestartEnable vkCmdSetPrimitiveRestartEnable;
#endif
#if defined(VK_KHR_fragment_shading_rate)
    PFN_vkCmdSetFragmentShadingRateKHR vkCmdSetFragmentShadingRateKHR;
#endif
#if defined(VKSC_VERSION_1_0)
    PFN_vkGetCommandPoolMemoryConsumption vkGetCommandPoolMemoryConsumption;
    PFN_vkGetFaultData vkGetFaultData;
#endif
#if defined(VK_KHR_maintenance6)
    PFN_vkCmdPushDescriptorSetWithTemplate2KHR vkCmdPushDescriptorSetWithTemplate2KHR;
    PFN_vkCmdBindDescriptorSets2KHR vkCmdBindDescriptorSets2KHR;
    PFN_vkCmdPushDescriptorSet2KHR vkCmdPushDescriptorSet2KHR;
    PFN_vkCmdPushConstants2KHR vkCmdPushConstants2KHR;
    PFN_vkCmdSetDescriptorBufferOffsets2EXT vkCmdSetDescriptorBufferOffsets2EXT;
    PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT vkCmdBindDescriptorBufferEmbeddedSamplers2EXT;
#endif
#if defined(VK_KHR_maintenance5)
    PFN_vkGetDeviceImageSubresourceLayoutKHR vkGetDeviceImageSubresourceLayoutKHR;
    PFN_vkCmdBindIndexBuffer2KHR vkCmdBindIndexBuffer2KHR;
    PFN_vkGetRenderingAreaGranularityKHR vkGetRenderingAreaGranularityKHR;
#endif
#if defined(VK_KHR_swapchain) || defined(VK_KHR_device_group)
    PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
    PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
    PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
#endif
#if defined(VK_KHR_display_swapchain)
    PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
#endif
#if defined(VK_VALVE_descriptor_set_host_mapping)
    PFN_vkGetDescriptorSetHostMappingVALVE vkGetDescriptorSetHostMappingVALVE;
    PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE vkGetDescriptorSetLayoutHostMappingInfoVALVE;
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
#if defined(VK_EXT_shader_object) || defined(VK_EXT_vertex_input_dynamic_state)
    PFN_vkCmdSetVertexInputEXT vkCmdSetVertexInputEXT;
#endif
#if defined(VK_KHR_shared_presentable_image)
    PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;
#endif
#if defined(VK_KHR_line_rasterization) || defined(VK_EXT_line_rasterization)
    PFN_vkCmdSetLineStippleKHR vkCmdSetLineStippleKHR;
#endif
#if defined(VK_EXT_shader_object) || defined(VK_EXT_extended_dynamic_state2)
    PFN_vkCmdSetPatchControlPointsEXT vkCmdSetPatchControlPointsEXT;
    PFN_vkCmdSetLogicOpEXT vkCmdSetLogicOpEXT;
#endif
#if defined(VK_KHR_synchronization2)
    PFN_vkCmdWriteBufferMarker2AMD vkCmdWriteBufferMarker2AMD;
    PFN_vkGetQueueCheckpointData2NV vkGetQueueCheckpointData2NV;
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
#if defined(VK_KHR_push_descriptor) || defined(VK_KHR_push_descriptor) || defined(VK_KHR_descriptor_update_template)
    PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;
#endif
#if defined(VK_NV_device_diagnostic_checkpoints)
    PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV;
    PFN_vkCmdSetCheckpointNV vkCmdSetCheckpointNV;
#endif
#if defined(VK_EXT_discard_rectangles)
    PFN_vkCmdSetDiscardRectangleModeEXT vkCmdSetDiscardRectangleModeEXT;
    PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;
    PFN_vkCmdSetDiscardRectangleEnableEXT vkCmdSetDiscardRectangleEnableEXT;
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
#if defined(VK_EXT_calibrated_timestamps) || defined(VK_KHR_calibrated_timestamps)
    PFN_vkGetCalibratedTimestampsKHR vkGetCalibratedTimestampsKHR;
#endif
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
    PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT vkCmdSetAttachmentFeedbackLoopEnableEXT;
#endif
#if defined(VK_NV_scissor_exclusive)
    PFN_vkCmdSetExclusiveScissorEnableNV vkCmdSetExclusiveScissorEnableNV;
    PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV;
#endif
#if defined(VK_EXT_host_image_copy) || defined(VK_EXT_image_compression_control) || defined(VK_KHR_maintenance5)
    PFN_vkGetImageSubresourceLayout2KHR vkGetImageSubresourceLayout2KHR;
#endif
#if defined(VK_EXT_device_fault)
    PFN_vkGetDeviceFaultInfoEXT vkGetDeviceFaultInfoEXT;
#endif
#if defined(VK_KHR_object_refresh)
    PFN_vkCmdRefreshObjectsKHR vkCmdRefreshObjectsKHR;
#endif
#if defined(VK_FUCHSIA_external_semaphore)
    PFN_vkGetSemaphoreZirconHandleFUCHSIA vkGetSemaphoreZirconHandleFUCHSIA;
    PFN_vkImportSemaphoreZirconHandleFUCHSIA vkImportSemaphoreZirconHandleFUCHSIA;
#endif
#if defined(VK_NV_external_sci_sync2)
    PFN_vkCreateSemaphoreSciSyncPoolNV vkCreateSemaphoreSciSyncPoolNV;
    PFN_vkDestroySemaphoreSciSyncPoolNV vkDestroySemaphoreSciSyncPoolNV;
#endif
};

} // namespace wis
