#include "SceneTitleScreen.h"

SceneTitleScreen::SceneTitleScreen(WorkingDirectory& workingDir, 
	SceneStateMachine& sceneStateMachine, Window& window, 
	ResourceAllocator<sf::Texture>& textureAllocator)
	: sceneStateMachine(sceneStateMachine), workingDir(workingDir), 
	window(window), switchToState(0), currentSeconds(0.0f), showForSeconds(3.0f), 
	textureAllocator(textureAllocator)
{
}

void SceneTitleScreen::OnCreate()
{
	//Assumng that this is the first time using logo so add to texture allocator
	int textureID = textureAllocator.Add(workingDir.Get() + "EmilyBenderTitleScreen.png");
	
	if (textureID >= 0)
	{
		std::shared_ptr<sf::Texture> texture = textureAllocator.Get(textureID);
		titleSprite.setTexture(*texture);

		sf::FloatRect spriteSize = titleSprite.getLocalBounds();

		//set the origin of the sprite to the centre of the image
		titleSprite.setOrigin(spriteSize.width * 0.5f,
			spriteSize.height * 0.5f);
		titleSprite.setScale(1.0f, 1.0f);

		sf::Vector2u windowCenter = window.GetCenter();

		//Positions sprite in the center of the screen 
		titleSprite.setPosition(windowCenter.x, windowCenter.y);
	}
	
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
