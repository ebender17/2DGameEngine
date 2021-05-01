#include "C_InputHandler.h"
#include "Object.h"

C_InputHandler::C_InputHandler(Object* owner)
	: Component(owner), moveSpeed(100)
{
}

void C_InputHandler::SetInput(Input* input)
{
	this->input = input;
}

void C_InputHandler::SetMovementSpeed(int moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void C_InputHandler::Update(float deltaTime)
{
    if (input == nullptr)
    {
        return;
    }

    int xMove = 0;
    if (input->IsKeyPressed(Input::Key::Left))
    {
        xMove = -moveSpeed;
    }
    else if (input->IsKeyPressed(Input::Key::Right))
    {
        xMove = moveSpeed;
    }

    int yMove = 0;
    if (input->IsKeyPressed(Input::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if (input->IsKeyPressed(Input::Key::Down))
    {
        yMove = moveSpeed;
    }

    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;

    owner->transform->AddPosition(xFrameMove, yFrameMove);
}
