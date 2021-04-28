#include "Game.h"
Game::Game()
	: window("2D Game Engine")
{

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

	window.EndDraw();
}

bool Game::IsRunning() const
{
	return window.IsOpen();
}

