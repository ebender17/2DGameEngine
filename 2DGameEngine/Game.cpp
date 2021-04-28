#include "Game.h"
Game::Game()
	: window("2D Game Engine")
{
	emilyTexture.loadFromFile(workingDir.Get() + "EmilyPokemonSprite.png"); 
	emilySprite.setTexture(emilyTexture);
}

void Game::Update() 
{
	window.Update();
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

