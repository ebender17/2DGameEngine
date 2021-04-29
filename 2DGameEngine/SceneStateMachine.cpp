#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine() : scenes(0), currScene(0)
{
}

void SceneStateMachine::ProcessInput()
{
	if (currScene)
		currScene->ProcessInput();
}

void SceneStateMachine::Update(float deltaTime)
{
	if (currScene)
		currScene->Update(deltaTime);
}

void SceneStateMachine::LateUpdate(float deltaTime)
{
	if (currScene)
		currScene->LateUpdate(deltaTime);
}

void SceneStateMachine::Draw(Window& window)
{
	if (currScene)
		currScene->Draw(window);
}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene)
{
	auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));

	insertedSceneID++;

	inserted.first->second->OnCreate();

	return insertedSceneID - 1;
}

void SceneStateMachine::SwitchTo(unsigned int id)
{
	auto sceneSwitchTo = scenes.find(id); 
	if (sceneSwitchTo != scenes.end())
	{
		if (currScene)
		{
			//If we have a current scene, we call its OnDeactivate method.
			currScene->OnDeactivate();
		}

		//Setting the current scene ensures that it is updated and drawn.
		currScene = sceneSwitchTo->second;

		currScene->OnActivate();


	}
}

void SceneStateMachine::Remove(unsigned int id)
{
	auto sceneRemove = scenes.find(id); 
	if (sceneRemove != scenes.end())
	{
		if (currScene == sceneRemove->second)
		{
			//If the scene we are removing is the curren scene, 
			//we also want to set that to a null pointer so the
			//scene is no longer updated.
			currScene = nullptr;
		}

		//We make sure to call the OnDestroy method of the scene
		//we are removing.
		sceneRemove->second->OnDestroy();

		scenes.erase(sceneRemove);
	}
}
