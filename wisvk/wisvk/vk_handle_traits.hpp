#pragma once
#include <type_traits>
#include <vulkan/vulkan.h>

namespace wis {
class empty_type
{
};

template<typename T>
using function_pointer_t = std::conditional_t<std::is_function_v<std::remove_pointer_t<T>>, std::remove_pointer_t<T>*, nullptr_t>;

template<typename HandleType>
class handle_traits
{
public:
    using parent = empty_type;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return nullptr;
    }
};
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_descriptor_update_template)
using VkDescriptorUpdateTemplate = VkDescriptorUpdateTemplateKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_1))
#if defined(VK_KHR_sampler_ycbcr_conversion)
using VkSamplerYcbcrConversion = VkSamplerYcbcrConversionKHR;
#endif
#endif
#if !(defined(VK_VERSION_1_3))
#if defined(VK_EXT_private_data)
using VkPrivateDataSlot = VkPrivateDataSlotEXT;
#endif
#endif

#if defined(VK_KHR_swapchain)
template<>
class handle_traits<VkSwapchainKHR>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroySwapchainKHR)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroySwapchainKHR;
    }
};

#endif
#if defined(VK_VERSION_1_0)
template<>
class handle_traits<VkBufferView>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyBufferView)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyBufferView;
    }
};

template<>
class handle_traits<VkInstance>
{
public:
    using parent = empty_type;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyInstance)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyInstance;
    }
};

template<>
class handle_traits<VkQueue>
{
public:
    using parent = VkDevice;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return nullptr;
    }
};

template<>
class handle_traits<VkPhysicalDevice>
{
public:
    using parent = VkInstance;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return nullptr;
    }
};

template<>
class handle_traits<VkBuffer>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyBuffer)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyBuffer;
    }
};

template<>
class handle_traits<VkSemaphore>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroySemaphore)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroySemaphore;
    }
};

template<>
class handle_traits<VkDevice>
{
public:
    using parent = VkPhysicalDevice;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyDevice)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyDevice;
    }
};

template<>
class handle_traits<VkCommandPool>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyCommandPool)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyCommandPool;
    }
};

template<>
class handle_traits<VkCommandBuffer>
{
public:
    using parent = VkCommandPool;
    using deleter_parent = VkDevice;
    using deleter_pool = VkCommandPool;
    using deleter_pfn = function_pointer_t<decltype(vkFreeCommandBuffers)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkFreeCommandBuffers;
    }
};

template<>
class handle_traits<VkRenderPass>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyRenderPass)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyRenderPass;
    }
};

template<>
class handle_traits<VkDeviceMemory>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkFreeMemory)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkFreeMemory;
    }
};

template<>
class handle_traits<VkImage>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyImage)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyImage;
    }
};

template<>
class handle_traits<VkImageView>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyImageView)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyImageView;
    }
};

template<>
class handle_traits<VkShaderModule>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyShaderModule)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyShaderModule;
    }
};

template<>
class handle_traits<VkPipeline>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyPipeline)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyPipeline;
    }
};

template<>
class handle_traits<VkPipelineLayout>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyPipelineLayout)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyPipelineLayout;
    }
};

template<>
class handle_traits<VkSampler>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroySampler)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroySampler;
    }
};

template<>
class handle_traits<VkDescriptorSet>
{
public:
    using parent = VkDescriptorPool;
    using deleter_parent = VkDevice;
    using deleter_pool = VkDescriptorPool;
    using deleter_pfn = function_pointer_t<decltype(vkFreeDescriptorSets)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkFreeDescriptorSets;
    }
};

template<>
class handle_traits<VkDescriptorPool>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyDescriptorPool)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyDescriptorPool;
    }
};

template<>
class handle_traits<VkDescriptorSetLayout>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyDescriptorSetLayout)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyDescriptorSetLayout;
    }
};

template<>
class handle_traits<VkFence>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyFence)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyFence;
    }
};

template<>
class handle_traits<VkEvent>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyEvent)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyEvent;
    }
};

template<>
class handle_traits<VkQueryPool>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyQueryPool)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyQueryPool;
    }
};

template<>
class handle_traits<VkFramebuffer>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyFramebuffer)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyFramebuffer;
    }
};

template<>
class handle_traits<VkPipelineCache>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyPipelineCache)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyPipelineCache;
    }
};

#endif
#if defined(VK_NVX_binary_import)
template<>
class handle_traits<VkCuModuleNVX>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyCuModuleNVX)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyCuModuleNVX;
    }
};

template<>
class handle_traits<VkCuFunctionNVX>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyCuFunctionNVX)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyCuFunctionNVX;
    }
};

#endif
#if defined(VK_NV_cuda_kernel_launch)
template<>
class handle_traits<VkCudaFunctionNV>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyCudaFunctionNV)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyCudaFunctionNV;
    }
};

template<>
class handle_traits<VkCudaModuleNV>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyCudaModuleNV)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyCudaModuleNV;
    }
};

#endif
#if defined(VK_EXT_debug_report)
template<>
class handle_traits<VkDebugReportCallbackEXT>
{
public:
    using parent = VkInstance;
    using deleter_parent = VkInstance;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyDebugReportCallbackEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyDebugReportCallbackEXT;
    }
};

#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_sampler_ycbcr_conversion)
template<>
class handle_traits<VkSamplerYcbcrConversion>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroySamplerYcbcrConversion)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroySamplerYcbcrConversion;
    }
};

#endif
#if defined(VK_NV_device_generated_commands)
template<>
class handle_traits<VkIndirectCommandsLayoutNV>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyIndirectCommandsLayoutNV)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyIndirectCommandsLayoutNV;
    }
};

#endif
#if defined(VK_INTEL_performance_query)
template<>
class handle_traits<VkPerformanceConfigurationINTEL>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkReleasePerformanceConfigurationINTEL)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkReleasePerformanceConfigurationINTEL;
    }
};

#endif
#if defined(VK_EXT_opacity_micromap)
template<>
class handle_traits<VkMicromapEXT>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyMicromapEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyMicromapEXT;
    }
};

#endif
#if defined(VK_KHR_display)
template<>
class handle_traits<VkDisplayModeKHR>
{
public:
    using parent = VkDisplayKHR;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return nullptr;
    }
};

template<>
class handle_traits<VkDisplayKHR>
{
public:
    using parent = VkPhysicalDevice;
    using deleter_parent = VkPhysicalDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkReleaseDisplayEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkReleaseDisplayEXT;
    }
};

#endif
#if defined(VK_EXT_debug_utils)
template<>
class handle_traits<VkDebugUtilsMessengerEXT>
{
public:
    using parent = VkInstance;
    using deleter_parent = VkInstance;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyDebugUtilsMessengerEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyDebugUtilsMessengerEXT;
    }
};

#endif
#if defined(VK_EXT_shader_object)
template<>
class handle_traits<VkShaderEXT>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyShaderEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyShaderEXT;
    }
};

#endif
#if defined(VK_EXT_validation_cache)
template<>
class handle_traits<VkValidationCacheEXT>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyValidationCacheEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyValidationCacheEXT;
    }
};

#endif
#if defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)
template<>
class handle_traits<VkDescriptorUpdateTemplate>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyDescriptorUpdateTemplate)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyDescriptorUpdateTemplate;
    }
};

#endif
#if defined(VK_KHR_deferred_host_operations)
template<>
class handle_traits<VkDeferredOperationKHR>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyDeferredOperationKHR)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyDeferredOperationKHR;
    }
};

#endif
#if defined(VK_KHR_acceleration_structure)
template<>
class handle_traits<VkAccelerationStructureKHR>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyAccelerationStructureKHR)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyAccelerationStructureKHR;
    }
};

#endif
#if defined(VK_NV_ray_tracing)
template<>
class handle_traits<VkAccelerationStructureNV>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyAccelerationStructureNV)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyAccelerationStructureNV;
    }
};

#endif
#if defined(VK_FUCHSIA_buffer_collection)
template<>
class handle_traits<VkBufferCollectionFUCHSIA>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyBufferCollectionFUCHSIA)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyBufferCollectionFUCHSIA;
    }
};

#endif
#if defined(VK_VERSION_1_3) || defined(VK_EXT_private_data)
template<>
class handle_traits<VkPrivateDataSlot>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyPrivateDataSlot)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyPrivateDataSlot;
    }
};

#endif
#if defined(VK_KHR_video_queue)
template<>
class handle_traits<VkVideoSessionParametersKHR>
{
public:
    using parent = VkVideoSessionKHR;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyVideoSessionParametersKHR)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyVideoSessionParametersKHR;
    }
};

template<>
class handle_traits<VkVideoSessionKHR>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyVideoSessionKHR)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyVideoSessionKHR;
    }
};

#endif
#if defined(VK_NV_optical_flow)
template<>
class handle_traits<VkOpticalFlowSessionNV>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyOpticalFlowSessionNV)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroyOpticalFlowSessionNV;
    }
};

#endif
#if defined(VK_KHR_surface)
template<>
class handle_traits<VkSurfaceKHR>
{
public:
    using parent = VkInstance;
    using deleter_parent = VkInstance;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroySurfaceKHR)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroySurfaceKHR;
    }
};

#endif
#if defined(VK_NV_external_sci_sync2)
template<>
class handle_traits<VkSemaphoreSciSyncPoolNV>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroySemaphoreSciSyncPoolNV)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkDestroySemaphoreSciSyncPoolNV;
    }
};

#endif

} // namespace wis
