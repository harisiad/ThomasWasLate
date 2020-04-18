#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}

			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}
		}
	}
	
	// Handle input specific to Thomas
	if (m_Thomas.handleInput())
	{
		// Jump sound
	}
	// Handle input specific to Bob
	if (m_Bob.handleInput())
	{
		// Jump sound
	}

}