#pragma once

#include "Component.h"

class C_SpriteRenderer : public Component
{
public: 
	C_SpriteRenderer(Object* owner); 

	//Loads sprite from file
	void Load(const std::string& filePath); 

	//We override the draw method so we can draw our sprite.
	void Draw(Window& window) override;

private:
	sf::Texture texture;
	sf::Sprite sprite;
};

