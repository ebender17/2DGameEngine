#pragma once

#include "Component.h"
#include "Input.h"

class C_InputHandler : public Component
{
public: 
	C_InputHandler(Object* owner);

	void SetInput(Input* input);
	void SetMovementSpeed(int moveSpeed);

	void Update(float deltaTime) override;

private:
	//TODO: Remove and place in another seperate component handling player movement
	int moveSpeed;
	Input* input;
};

