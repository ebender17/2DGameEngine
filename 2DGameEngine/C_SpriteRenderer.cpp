#include "C_SpriteRenderer.h"
#include "Object.h"

C_SpriteRenderer::C_SpriteRenderer(Object* owner) : Component(owner) {}

void C_SpriteRenderer::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
	this->allocator = allocator;
}

void C_SpriteRenderer::Load(int id)
{
	if (id >= 0)
	{
		std::shared_ptr<sf::Texture> texture = allocator->Get(id);
		sprite.setTexture(*texture);
	}
}

void C_SpriteRenderer::Load(const std::string& filePath)
{
	if (allocator)
	{
		int textureID = allocator->Add(filePath);

		if (textureID >= 0)
		{
			std::shared_ptr<sf::Texture> texture = allocator->Get(textureID);
			sprite.setTexture(*texture);
		}
	}
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
