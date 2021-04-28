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

private:
	Window window;

	WorkingDirectory workingDir;

	sf::Texture emilyTexture;
	sf::Sprite emilySprite;
};

