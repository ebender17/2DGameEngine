#pragma once

#include <SFML/Graphics.hpp>
#include "Bitmask.h"

class Input
{
public: 
	enum class Key
	{
		None = 0, 
		Left = 1, 
		Right = 2, 
		Up = 3, 
		Down = 4, 
		Esc = 5
	};

public:
	//Returns true if the key is pressed.
	bool IsKeyPressed(Key keycode);
	//Returns true if the key was just pressed.
	bool IsKeyDown(Key keycode);
	//Returns true if the key was just released.
	bool IsKeyUp(Key keycode);

	/// <summary>
	/// Responsible for polling the keys and determining which keys 
	/// have been pressed that frame.
	/// </summary>
	void Update();

private:
	Bitmask thisFrameKeys; 
	Bitmask lastFrameKeys;
};

