#include "SceneGame.h"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator)
	: workingDir(workingDir), textureAllocator(textureAllocator)
{
}

void SceneGame::OnCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();

    //Add player components
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

    //Add player to object collection
    objects.Add(player);

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
    objects.ProcessRemovals();
    //Process new objects at the beginning of each frame.
    objects.ProcessNewObjects();

    objects.Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime)
{
    objects.LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    objects.Draw(window);
}
