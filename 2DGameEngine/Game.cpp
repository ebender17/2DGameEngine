#include "Game.h"
Game::Game()
	: window("2D Game Engine")
{
	deltaTime = clock.restart().asSeconds();

	emilyTexture.loadFromFile(workingDir.Get() + "EmilyPokemonSprite.png"); 
	emilySprite.setTexture(emilyTexture);
}

void Game::Update() 
{
	window.Update();

	const sf::Vector2f& spritePos = emilySprite.getPosition(); 
	const int pixelsToMovePerSec = 100;
	const float frameMovement = pixelsToMovePerSec * deltaTime;
	emilySprite.setPosition(spritePos.x + frameMovement, spritePos.y);
}

void Game::LateUpdate()
{

}

void Game::Draw()
{
	window.BeginDraw();

	window.Draw(emilySprite);

	window.EndDraw();
}

bool Game::IsRunning() const
{
	return window.IsOpen();
}

void Game::CalculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

