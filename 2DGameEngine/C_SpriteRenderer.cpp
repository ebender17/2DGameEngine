#include "C_SpriteRenderer.h"

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
