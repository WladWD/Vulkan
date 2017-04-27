#include <iostream>
#include <vector>
#include <vulkan\vulkan.h>
using namespace std;

vector < VkPhysicalDevice > m_physicalDevices;
vector < VkQueueFamilyProperties > m_queueFamilyPrperties;

int main() 
{
	VkInstance mInstance;

	VkResult result = VK_SUCCESS;
	VkApplicationInfo appInfo = {};
	VkInstanceCreateInfo instanceCreateInfo = {};

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "VulakanApp";
	appInfo.applicationVersion = 1;
	appInfo.engineVersion = 1;
	appInfo.pEngineName = "VulkanEngine";
	appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);

	instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pApplicationInfo = &appInfo;

	result = vkCreateInstance(&instanceCreateInfo, nullptr, &mInstance);
	if (result == VK_SUCCESS) 
	{
		uint32_t physicalDeviceCount = 0;
		result = vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, nullptr);
		

		if (result == VK_SUCCESS)
		{
			m_physicalDevices.resize(physicalDeviceCount);
			vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, m_physicalDevices.data());

			for (const auto &mDevice : m_physicalDevices)
			{
				VkPhysicalDeviceProperties mDeviceProperties;
				VkPhysicalDeviceFeatures mDeviceFeatures;
				VkPhysicalDeviceMemoryProperties mDeviceMemoryProperties;
				

				vkGetPhysicalDeviceProperties(mDevice, &mDeviceProperties);
				vkGetPhysicalDeviceFeatures(mDevice, &mDeviceFeatures);
				vkGetPhysicalDeviceMemoryProperties(mDevice, &mDeviceMemoryProperties);
				
				uint32_t mPhysicalQueueFamilyPropertyCount;
				vkGetPhysicalDeviceQueueFamilyProperties(mDevice, &mPhysicalQueueFamilyPropertyCount, nullptr);
				m_queueFamilyPrperties.resize(mPhysicalQueueFamilyPropertyCount);
				vkGetPhysicalDeviceQueueFamilyProperties(mDevice, &mPhysicalQueueFamilyPropertyCount, m_queueFamilyPrperties.data());

				int x = 0;
			}
		}
	}

	return 0;
}