#include <wisvk/vk_loader.hpp>
#include <wisvk/vk_managed_handles.hpp>

wis::VkGlobalTable vk_global_table;

int main()
{
    wis::LibToken lib_token;
    vk_global_table.Init(lib_token);

    uint32_t version = 0;
    VkResult res = vk_global_table.vkEnumerateInstanceVersion(&version);

    printf("Vulkan version is %d.%d.%d", VK_VERSION_MAJOR(version), VK_VERSION_MINOR(version), VK_VERSION_PATCH(version));

    VkInstanceCreateInfo instance_create_info{
    .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    .pNext = nullptr,
    .flags = 0,
    .pApplicationInfo = nullptr,
    .enabledLayerCount = 0,
    };

    wis::shared_handle<VkInstance> instance;
    vk_global_table.vkCreateInstance(&instance_create_info, nullptr, instance.put_unsafe(vk_global_table.vkDestroyInstance));

    return 0;
}