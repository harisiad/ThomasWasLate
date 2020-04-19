#include "Engine.h"

void Engine::draw()
{
	// Clear out the last frame
	m_Window.clear(Color::White);

	// Update the shader parameters
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());

	if (!m_SplitScreen)
	{
		// Switch to background view
		m_Window.setView(m_BGMainView);
		// Draw the background
		//m_Window.draw(m_BackgroundSprite);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		// Switch to m_MainView
		m_Window.setView(m_MainView);

		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		// Draw Bob
		m_Window.draw(m_Bob.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

	}
	else
	{
		// Split-screen view is active

		//First draw Thomas' side of the screen

		// Switch to background view
		m_Window.setView(m_BGLeftView);
		// Draw the background
		//m_Window.draw(m_BackgroundSprite);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		// Switch to m_LeftView
		m_Window.setView(m_LeftView);

		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		m_Window.draw(m_Bob.getSprite());
		m_Window.draw(m_Thomas.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

		// Now draw Bob's side of the screen

		// Switch to background view
		m_Window.setView(m_BGRightView);
		// Draw the background
		//m_Window.draw(m_BackgroundSprite);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		// Switch to m_RightView
		m_Window.setView(m_RightView);

		// Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
	}

	// Draw the HUD
	// Switch to m_HudView
	m_Window.setView(m_HudView);
	m_Window.draw(m_HUD.getLevel());
	m_Window.draw(m_HUD.getTime());
	if (!m_Playing)
	{
		m_Window.draw(m_HUD.getMessage());
	}

	// Show everything we have just drawn
	m_Window.display();
}
