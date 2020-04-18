#ifndef __TEXTURE_HOLDER_H__
#define __TEXTURE_HOLDER_H__

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
private:
	// A map container from STL,
	// that holds related pairs of String | Texture
	std::map<std::string, sf::Texture> m_Texture;
	
	// A pointer of the same type as the class itself
	// the on and only instance
	static TextureHolder* m_s_Instance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};

#endif
