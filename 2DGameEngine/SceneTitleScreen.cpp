#include "SceneTitleScreen.h"

SceneTitleScreen::SceneTitleScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneStateMachine, Window& window)
	: sceneStateMachine(sceneStateMachine), workingDir(workingDir), 
	window(window), switchToState(0), currentSeconds(0.0f), showForSeconds(3.0f)
{
}

void SceneTitleScreen::OnCreate()
{
	titleTexture.loadFromFile(workingDir.Get() + "EmilyBenderTitleScreen.png");
	titleSprite.setTexture(titleTexture);

	sf::FloatRect spriteSize = titleSprite.getLocalBounds(); 

	//set the origin of the sprite to the centre of the image
	titleSprite.setOrigin(spriteSize.width * 0.5f,
		spriteSize.height * 0.5f);
	titleSprite.setScale(1.0f, 1.0f);

	sf::Vector2u windowCenter = window.GetCenter();

	//Positions sprite in the center of the screen 
	titleSprite.setPosition(windowCenter.x, windowCenter.y);
}

void SceneTitleScreen::OnDestroy()
{
}

void SceneTitleScreen::OnActivate()
{
	currentSeconds = 0.0f;
}

void SceneTitleScreen::SetSwitchToScene(unsigned int id)
{
	switchToState = id;
}

void SceneTitleScreen::Update(float deltaTime)
{
	currentSeconds += deltaTime;

	if (currentSeconds >= showForSeconds)
		sceneStateMachine.SwitchTo(switchToState);
}


void SceneTitleScreen::Draw(Window& window)
{
	window.Draw(titleSprite);
}
