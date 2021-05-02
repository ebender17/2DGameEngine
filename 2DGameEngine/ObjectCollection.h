#pragma once

#include <memory>
#include <vector>

#include "Object.h"

/// <summary>
/// Responsible for maintaining, updating and drawing objects in a scene. 
/// This saves us from having to manually maintain all objects in a scene.
/// </summary>
class ObjectCollection
{
public: 
	void Add(std::shared_ptr<Object> object);

	void Update(float deltaTime); 
	void LateUpdate(float deltaTime);
	void Draw(Window& window);

	//Responsible for moving new objects added in a frame to the main object collection.
	void ProcessNewObjects();
	void ProcessRemovals();

private:
	std::vector<std::shared_ptr<Object>> objects;
	std::vector<std::shared_ptr<Object>> newObjects;
};

