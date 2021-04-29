#pragma once

#include "Window.h"

class Object;

/// <summary>
/// Base class of components.
/// </summary>
class Component
{
public: 
	Component(Object* owner) : owner(owner) {}

	virtual void Awake() {};
	virtual void Start() {};
	
	virtual void Update(float deltaTime) {};
	virtual void LateUpdate(float deltaTime) {};
	virtual void Draw(Window& window) {};

protected:
	Object* owner;
};
