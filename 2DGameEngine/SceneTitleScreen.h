#pragma once

#include <SFML/Graphics.hpp>

#include "SceneStateMachine.h"
#include "WorkingDirectory.h"
#include "C_InputHandler.h"
#include "ResourceAllocator.h"

class SceneTitleScreen : public Scene
{
public:
	SceneTitleScreen(WorkingDirectory& workingDir,
		SceneStateMachine& sceneStateMachine, Window& window, 
		ResourceAllocator<sf::Texture>& textureAllocator);

	void OnCreate() override;
	void OnDestroy() override;

	void OnActivate() override;

	void SetSwitchToScene(unsigned int id);

	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	sf::Sprite titleSprite;

	WorkingDirectory& workingDir;
	SceneStateMachine& sceneStateMachine;
	Window& window;
	ResourceAllocator<sf::Texture>& textureAllocator;

	//We want to show this scene for a set amount of time
	float showForSeconds;

	//How long the scene has currently been visible.
	float currentSeconds;

	//The state we want to transition to when this scenes time ends.
	unsigned int switchToState;
};

