#include "Object.h"

Object::Object()
{
	transform = AddComponent<C_Transform>();
}

//Loop through our components in reverse order as the component vector
//can be changed in our update or draw calls with components adding/removing
//other components.
//If we looped from start to end, removing a component will cause our index
//to point to what it thinks is the last component but is a memory address 
//space it no longer owns.
void Object::Awake()
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Awake();
	}
}

void Object::Start()
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Start();
	}
}

void Object::Update(float deltaTime)
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Update(deltaTime);
	}
}

void Object::LateUpdate(float deltaTime)
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->LateUpdate(deltaTime);
	}
}

void Object::Draw(Window& window)
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Draw(window);
	}
}
