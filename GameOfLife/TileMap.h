#pragma once
#include "Cell.h"
#include <SFML/Graphics.hpp>

typedef boost::multi_array<bool, 2> boolMatrix;

class TileMap : public sf::Drawable, 
	public sf::Transformable
{
	sf::VertexArray theWorld;
	sf::Texture texture;
	boolMatrix bools;
public:
	void load(sf::Vector2f, matrix&, int, int);
	TileMap();
	~TileMap();
private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

};

