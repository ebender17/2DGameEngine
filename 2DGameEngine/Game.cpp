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
	const int moveSpeed = 100;

	int xMove = 0;
	if (input.IsKeyPressed(Input::Key::Left))
		xMove = -moveSpeed;
	else if (input.IsKeyPressed(Input::Key::Right))
		xMove = moveSpeed;

	int yMove = 0;
	if (input.IsKeyPressed(Input::Key::Up))
	{
		yMove = -moveSpeed;
	}
	else if (input.IsKeyPressed(Input::Key::Down))
	{
		yMove = moveSpeed;
	}

	float xFrameMove = xMove * deltaTime; 
	float yFrameMove = yMove * deltaTime;

	emilySprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
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

void Game::CaptureInput()
{
	input.Update();
}

