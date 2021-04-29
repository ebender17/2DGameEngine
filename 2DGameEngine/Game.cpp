#include "Game.h"
Game::Game()
	: window("2D Game Engine")
{
	deltaTime = clock.restart().asSeconds();

	std::shared_ptr<SceneTitleScreen> titleScreen =
		std::make_shared<SceneTitleScreen>(workingDir,
			sceneStateMachine,
			window); 

	std::shared_ptr<SceneGame> gameScene =
		std::make_shared<SceneGame>(workingDir);

	unsigned int titleScreenID = sceneStateMachine.Add(titleScreen); 
	unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

	titleScreen->SetSwitchToScene(gameSceneID); 

	sceneStateMachine.SwitchTo(titleScreenID);

	deltaTime = clock.restart().asSeconds();

}

void Game::Update()
{
	window.Update();

	sceneStateMachine.Update(deltaTime);

}

void Game::LateUpdate()
{
	sceneStateMachine.LateUpdate(deltaTime);

}

void Game::Draw()
{
	window.BeginDraw();

	sceneStateMachine.Draw(window);

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
	sceneStateMachine.ProcessInput();
}

