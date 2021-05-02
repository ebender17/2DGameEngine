#pragma once

#include <map>
#include <memory>
#include <string>

/// <summary>
/// Generic resource allocator. Can instantiate different resource managers that are responsible
/// for allocating different resources.
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class ResourceAllocator
{
public: 
	int Add(const std::string& filePath)
	{
		auto it = resources.find(filePath);

		//Resource has already been added, return resource
		if (it != resources.end())
		{
			return it->second.first;
		}

		std::shared_ptr<T> resource = std::make_shared<T>();
		//Make sure the new resource has the loadFromFile method implemented
		if (!resource->loadFromFile(filePath))
		{
			return -1;
		}

		resources.insert(
			std::make_pair(filePath, std::make_pair(currentId, resource)));

		return currentId++;

	}

	void Remove(int id)
	{
		for (auto it = resources.begin(); it != resources.end(); ++it)
		{
			if (it->second.first == id)
			{
				resources.erase(it->first);
			}
		}
	}

	std::shared_ptr<T> Get(int id)
	{
		for (auto it = resources.begin(); it != resources.end(); ++it)
		{
			if (it->second.first == id)
			{
				return it->second.second;
			}
		}

		return nullptr;
	}

	bool Has(int id)
	{
		return (Get(id) != nullptr);
	}

private: 
	int currentId;

	std::map<std::string, std::pair<int, std::shared_ptr<T>>>resources;
};

