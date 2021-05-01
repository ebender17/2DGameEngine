#pragma once

#include <vector>

#include "Window.h"
#include "Component.h"
#include "C_Transform.h"

/// <summary>
/// Class for all objects in the game. All objects have a transform component.
/// </summary>
class Object
{
public:
	Object();

	//Awake is called when object is created. Use to ensure
	//required components are present.
	void Awake();

	//Start is called after Awake method. 
	//Use to initialize variables.
	void Start();

	void Update(float deltaTime);
	void LateUpdate(float deltaTime);
	void Draw(Window& window);

	template <typename T> 
	std::shared_ptr<T> AddComponent()
	{
		//This ensures that we only try to add a class that derives
		//from Component. This is tested at compile time.
		static_assert(std::is_base_of<Component, T>::value, 
			"T must derive from Component");

		//Check that we don't already have a component of this type
		for (auto& existingComponent : components)
		{
			// Currently we prevent adding the same component twice. 
			// This may be something we will change in future.
			if (std::dynamic_pointer_cast<T>(existingComponent))
			{
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
	
		}

		// The object does not have this component so we create it and 
			// add it to our list.
		std::shared_ptr<T> newComponent = std::make_shared<T>(this);
		components.push_back(newComponent);

		return newComponent;
	}

	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		static_assert(std::is_base_of<Component, T>::value,"T must derive from Component");

		// Check to see if we have the component below.
		for (auto& exisitingComponent : components)
		{
			if (std::dynamic_pointer_cast<T>(exisitingComponent))
			{
				return std::dynamic_pointer_cast<T>(exisitingComponent);
			}
		}

		return nullptr;
	}

public: 
	std::shared_ptr<C_Transform> transform;

private:
	std::vector<std::shared_ptr<Component>> components;

};

