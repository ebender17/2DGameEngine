#include "Window.h"

Window::Window(const std::string& windowName)
	: window(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar)
{
	//TODO: Give player option of turning vsync on or off
	window.setVerticalSyncEnabled(true); //sync frame rate of the game to refresh rate of monitor
}

void Window::Update()
{
	sf::Event event;
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

/// <summary>
/// Clears the screen to a uniform color. Without this call you will see all 
/// previously drawn frames. 
/// </summary>
void Window::BeginDraw()
{
	window.clear(sf::Color::White);
}

void Window::Draw(const sf::Drawable& drawable)
{
	window.draw(drawable);
}

/// <summary>
/// Displau all foredrawn items requested in Draw();
/// </summary>
void Window::EndDraw()
{
	window.display();
}

bool Window::IsOpen() const
{
	return window.isOpen();
}
