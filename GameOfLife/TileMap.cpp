#include "TileMap.h"



void TileMap::load(sf::Vector2f tileSize, matrix cells, int width, int height)
{
	bools.resize(boost::extents[width][height]);
	for (int i = 0; i < cells.shape()[0]; ++i)
	{
		for (int j = 0; j < cells.shape()[1]; ++j)
		{
			bools[j][i] = cells[i][j].isActive();
		}
	}
	//cells.resize(boost::extents[width][height]);
	theWorld.setPrimitiveType(sf::Quads);
	theWorld.resize(width * height * 4);
	sf::Image image;
	image.create(tileSize.x *2, tileSize.y, sf::Color::Black);
	for (int i = tileSize.x; i < tileSize.x *2; ++i)
	{
		for (int j = 0; j < tileSize.y; ++j)
		{
			image.setPixel(i, j, sf::Color::White);
		}
	}
	texture.loadFromImage(image);

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j)
		{
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &theWorld[(i*height + j ) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			if (!bools[i][j])
			{
				quad[0].texCoords = sf::Vector2f(0, 0);
				quad[1].texCoords = sf::Vector2f(tileSize.x - 1, 0);
				quad[2].texCoords = sf::Vector2f(tileSize.x - 1, tileSize.y - 1);
				quad[3].texCoords = sf::Vector2f(0, tileSize.y - 1);
			}
			else {
				quad[0].texCoords = sf::Vector2f(tileSize.x, 0);
				quad[1].texCoords = sf::Vector2f(2* tileSize.x, 0);
				quad[2].texCoords = sf::Vector2f(2* tileSize.x, tileSize.y - 1);
				quad[3].texCoords = sf::Vector2f(tileSize.x, tileSize.y - 1);
			}

		}
	}

}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &texture;
	target.draw(theWorld, states);
}

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}
