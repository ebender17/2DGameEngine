#pragma once

#include "Window.h"

/// <summary>
/// Parent class of all our scenes. This is an abstract class
/// that will not be instantiated.
/// </summary>
class Scene
{
public: 
	//Called when scene initially created. Called once. 
	virtual void OnCreate() = 0; 

	//Called when scene is destroyed. Called at most once 
	//(if a scene is not removed from the game, this will never be called).
	virtual void OnDestroy() = 0;

	//Called whenever a scene is transition into. 
	//Can be called many times in a typical game cycle. 
	virtual void OnActivate() {};

	//Called whenever a transition out of a scene occurs. 
	//Can be called many times in a typical game cycle. 
	virtual void OnDeactivate() {};

	//The below functions can be overriden as necessary in our scenes. 
	virtual void ProcessInput() {};
	virtual void Update(float deltaTime) {};
	virtual void LateUpdate(float deltaTime) {};
	virtual void Draw(Window& window) {};

};

