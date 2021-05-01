#include "C_SpriteRenderer.h"
#include "Object.h"

C_SpriteRenderer::C_SpriteRenderer(Object* owner) : Component(owner) {}

void C_SpriteRenderer::Load(const std::string& filePath)
{
	texture.loadFromFile(filePath);
	sprite.setTexture(texture); 
}

void C_SpriteRenderer::Draw(Window& window)
{
	window.Draw(sprite);
}

void C_SpriteRenderer::LateUpdate(float deltaTime)
{
	//TODO: Only update pos when it has changed rather than every frame
	sprite.setPosition(owner->transform->GetPosition());
}
