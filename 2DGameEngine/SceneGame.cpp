#include "SceneGame.h"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator)
	: workingDir(workingDir), textureAllocator(textureAllocator)
{
}

void SceneGame::OnCreate()
{
    player = std::make_shared<Object>();


    auto sprite = player->AddComponent<C_SpriteRenderer>();
    
    if (sprite)
    {
        sprite->SetTextureAllocator(&textureAllocator);
        sprite->Load(workingDir.Get() + "EmilyPokemonSprite.png");
        
    }
    else
    {
        std::cout << "Sprite Renderer component not added" << std::endl;
    }
        

    auto movement = player->AddComponent<C_InputHandler>();

    if (movement)
        movement->SetInput(&input);
    else
        std::cout << "Input Handler component not added" << std::endl;

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
    player->Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime)
{
    player->LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    player->Draw(window);
}
