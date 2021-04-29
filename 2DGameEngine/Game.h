#pragma once
#include "Window.h"
#include "WorkingDirectory.h"
#include "Input.h"
#include "SceneStateMachine.h"
#include "SceneTitleScreen.h"
#include "SceneGame.h"

class Game
{
public: 
	Game();
	void Update();
	void LateUpdate();
	void Draw();
	bool IsRunning() const;

	void CalculateDeltaTime(); 

	void CaptureInput();

private:
	Window window;

	WorkingDirectory workingDir;

	sf::Clock clock;
	float deltaTime;

	SceneStateMachine sceneStateMachine;

};

