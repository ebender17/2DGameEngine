#pragma once
#include "Window.h"
#include "WorkingDirectory.h"

class Game
{
public: 
	Game();
	void Update();
	void LateUpdate();
	void Draw();
	bool IsRunning() const;

	void CalculateDeltaTime(); 

private:
	Window window;

	WorkingDirectory workingDir;

	sf::Clock clock;
	float deltaTime;


	sf::Texture emilyTexture;
	sf::Sprite emilySprite;
};

