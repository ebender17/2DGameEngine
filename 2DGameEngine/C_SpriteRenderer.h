#pragma once

#include "Component.h"
#include "ResourceAllocator.h"

class C_SpriteRenderer : public Component
{
public: 
	C_SpriteRenderer(Object* owner); 

	void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

	//Loads sprite from already existing resource
	void Load(int id);
	//Loads sprite from file and adds texture to resource allocator
	void Load(const std::string& filePath); 

	//We override the draw method so we can draw our sprite.
	void Draw(Window& window) override;

	//Sprite's position will be updated based on object's transform position.
	void LateUpdate(float deltaTime) override;

private:
	ResourceAllocator < sf::Texture>* allocator;
	sf::Sprite sprite;
};

