#pragma once

#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"

class SceneGame : public Scene
{
public: 
	SceneGame(WorkingDirectory& workingDir);

    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update(float deltaTime) override;
    void Draw(Window& window) override;

private:
    sf::Texture emilyTexture;
    sf::Sprite emilySprite;

    WorkingDirectory& workingDir;
    Input input;
};

