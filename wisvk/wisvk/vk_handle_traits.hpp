#pragma once
#ifndef WISVK_MODULE_DECL
#include <type_traits>
#include <vulkan/vulkan.h>
#define WISVK_EXPORT
#else
#define WISVK_EXPORT export
#endif // WISVK_MODULE_DECL

WISVK_EXPORT
namespace wis {
class empty_type
{
};

template<typename T>
using function_pointer_t = std::conditional_t<std::is_function_v<std::remove_pointer_t<T>>, std::remove_pointer_t<T>*, std::nullptr_t>;

template<typename HandleType>
class handle_traits
{
public:
    using parent = empty_type;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = std::nullptr_t;

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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroySwapchainKHR;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyBufferView;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyInstance;
#else
        return nullptr;
#endif
    }
};

template<>
class handle_traits<VkQueue>
{
public:
    using parent = VkDevice;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = std::nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
#ifndef WISVK_NO_DEFAULT_DELETER
        return nullptr;
#else
        return nullptr;
#endif
    }
};

template<>
class handle_traits<VkPhysicalDevice>
{
public:
    using parent = VkInstance;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = std::nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
#ifndef WISVK_NO_DEFAULT_DELETER
        return nullptr;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyBuffer;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroySemaphore;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyDevice;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyCommandPool;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkFreeCommandBuffers;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyRenderPass;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkFreeMemory;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyImage;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyImageView;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyShaderModule;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyPipeline;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyPipelineLayout;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroySampler;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkFreeDescriptorSets;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyDescriptorPool;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyDescriptorSetLayout;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyFence;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyEvent;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyQueryPool;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyFramebuffer;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyPipelineCache;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyCuModuleNVX;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyCuFunctionNVX;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyCudaFunctionNV;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyCudaModuleNV;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyDebugReportCallbackEXT;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroySamplerYcbcrConversion;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyIndirectCommandsLayoutNV;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkReleasePerformanceConfigurationINTEL;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyMicromapEXT;
#else
        return nullptr;
#endif
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
    using deleter_pfn = std::nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
#ifndef WISVK_NO_DEFAULT_DELETER
        return nullptr;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkReleaseDisplayEXT;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyDebugUtilsMessengerEXT;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyShaderEXT;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyDescriptorUpdateTemplate;
#else
        return nullptr;
#endif
    }
};

#endif
#if defined(VK_KHR_pipeline_binary)
template<>
class handle_traits<VkPipelineBinaryKHR>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyPipelineBinaryKHR)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyPipelineBinaryKHR;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyValidationCacheEXT;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyVideoSessionParametersKHR;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyVideoSessionKHR;
#else
        return nullptr;
#endif
    }
};

#endif
#if defined(VK_EXT_device_generated_commands)
template<>
class handle_traits<VkIndirectCommandsLayoutEXT>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyIndirectCommandsLayoutEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyIndirectCommandsLayoutEXT;
#else
        return nullptr;
#endif
    }
};

template<>
class handle_traits<VkIndirectExecutionSetEXT>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkDestroyIndirectExecutionSetEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyIndirectExecutionSetEXT;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyDeferredOperationKHR;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyAccelerationStructureKHR;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyAccelerationStructureNV;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyBufferCollectionFUCHSIA;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyPrivateDataSlot;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroyOpticalFlowSessionNV;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroySurfaceKHR;
#else
        return nullptr;
#endif
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
#ifndef WISVK_NO_DEFAULT_DELETER
        return vkDestroySemaphoreSciSyncPoolNV;
#else
        return nullptr;
#endif
    }
};

#endif

} // namespace wis
