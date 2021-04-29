#pragma once

#include <SFML/Graphics.hpp>

#include "SceneStateMachine.h"
#include "WorkingDirectory.h"

class SceneTitleScreen : public Scene
{
public:
	SceneTitleScreen(WorkingDirectory& workingDir,
		SceneStateMachine& sceneStateMachine, Window& window);

	void OnCreate() override;
	void OnDestroy() override;

	void OnActivate() override;

	void SetSwitchToScene(unsigned int id);

	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	sf::Texture titleTexture;
	sf::Sprite titleSprite;

	WorkingDirectory& workingDir;
	SceneStateMachine& sceneStateMachine;
	Window& window;

	//We want to show this scene for a set amount of time
	float showForSeconds;

	//How long the scene has currently been visible.
	float currentSeconds;

	//The state we want to transition to when this scenes time ends.
	unsigned int switchToState;
};

