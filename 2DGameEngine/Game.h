#pragma once
#include "Window.h"
#include "WorkingDirectory.h"
#include "Input.h"

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

	Input input;


	sf::Texture emilyTexture;
	sf::Sprite emilySprite;
};

