#pragma once

#include <iostream>
#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"
#include "Object.h"
#include "C_SpriteRenderer.h"

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
    WorkingDirectory& workingDir;
    Input input;

    std::shared_ptr<Object> player;
};

