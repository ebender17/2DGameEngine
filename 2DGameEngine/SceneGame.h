#pragma once

#include <iostream>
#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"
#include "Object.h"
#include "C_SpriteRenderer.h"
#include "C_InputHandler.h"
#include "ResourceAllocator.h"
#include "ObjectCollection.h"

class SceneGame : public Scene
{
public: 
    SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator);

    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update(float deltaTime) override;
    void LateUpdate(float deltaTime) override;
    void Draw(Window& window) override;

private:
    WorkingDirectory& workingDir;
    Input input;
    ResourceAllocator<sf::Texture>& textureAllocator;
    ObjectCollection objects;

};

