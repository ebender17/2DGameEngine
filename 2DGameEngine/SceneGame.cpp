#include "SceneGame.h"

SceneGame::SceneGame(WorkingDirectory& workingDir)
	: workingDir(workingDir)
{
}

void SceneGame::OnCreate()
{
    player = std::make_shared<Object>();


    auto sprite = player->AddComponent<C_SpriteRenderer>();
    
    if (sprite)
        sprite->Load(workingDir.Get() + "EmilyPokemonSprite.png");
    else
        std::cout << "Sprite Renderer component not added" << std::endl;
}

void SceneGame::OnDestroy()
{
}

void SceneGame::ProcessInput()
{
	input.Update();
}

void SceneGame::Update(float deltaTime)
{
    
}

void SceneGame::Draw(Window& window)
{
    player->Draw(window);
}
