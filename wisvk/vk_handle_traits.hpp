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
class handle_traits<VkSwapchainKHR>
{
public:
    using parent = VkDevice;
    using deleter_parent = VkDevice;
    using deleter_pool = empty_type;
    using deleter_pfn = function_pointer_t<decltype(vkReleaseFullScreenExclusiveModeEXT)>;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return vkReleaseFullScreenExclusiveModeEXT;
    }
};

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

}
