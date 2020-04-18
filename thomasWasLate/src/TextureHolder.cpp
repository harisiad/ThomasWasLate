#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	// Get a reference to m_Textures using m_s_Instance
	auto& m = m_s_Instance->m_Texture;
	// auto is the equivalent of map<string, Texture>

	// Create an iterator to hold a key-value pair (kvp)
	// and search for the required kvp
	// using the passed in file name
	auto keyValuePair = m.find(filename);
	// auto is equivalent of map<string, Texture>::iterator

	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
		auto& texture = m[filename];

		texture.loadFromFile(filename);

		return texture;
	}
}
