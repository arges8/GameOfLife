#include "TileMap.h"
#include <thread>



void TileMap::load(sf::Vector2f tileSize, matrix& cells, int width, int height)
{
	const size_t nthreads = 4;
	std::vector<std::thread> threads(nthreads);
	if (cells.shape()[0] < height || cells.shape()[1] < width) {
		int moveRow = height % cells.shape()[0] == 0 ? ((height / cells.shape()[0]) - 1) : ((cells.shape()[0]) / 2);
		int moveCol = width % cells.shape()[1] == 0 ? ((width / cells.shape()[1]) - 1) : ((cells.shape()[0]) / 2);
		bools.resize(boost::extents[height][width]);
		for (int i = 0; i < cells.shape()[0]; ++i)
		{
			for (int j = 0; j < cells.shape()[1]; ++j)
			{
				bools[i + moveRow][j + moveCol] = cells[i][j].isActive();
			}
		}
		cells.resize(boost::extents[height][width]);
		for (int i = 0; i < cells.shape()[0]; ++i)
		{
			for (int j = 0; j < cells.shape()[1]; ++j)
			{
				cells[i][j].setActive(bools[i][j]);
			}
		}
	}

	theWorld.setPrimitiveType(sf::Quads);
	theWorld.resize(width * height * 4);
	sf::Image image;
	image.create(tileSize.x * 2, tileSize.y, sf::Color::Black);
	for (int i = tileSize.x; i < tileSize.x * 2; ++i)
	{
		for (int j = 0; j < tileSize.y; ++j)
		{
			image.setPixel(i, j, sf::Color::White);
		}
	}
	texture.loadFromImage(image);
	for (int t = 0; t < nthreads; ++t) {
		threads[t] = std::thread(std::bind([&](const int bi, const int ei, const int t) {
			for (int i = bi; i < ei; ++i) {
				for (int j = 0; j < height; ++j)
				{
					// get a pointer to the current tile's quad
					sf::Vertex* quad = &theWorld[(i * height + j) * 4];

					// define its 4 corners
					quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
					quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
					quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
					quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

					if (!cells[j][i].isActive())
					{
						quad[0].texCoords = sf::Vector2f(0, 0);
						quad[1].texCoords = sf::Vector2f(tileSize.x - 1, 0);
						quad[2].texCoords = sf::Vector2f(tileSize.x - 1, tileSize.y - 1);
						quad[3].texCoords = sf::Vector2f(0, tileSize.y - 1);
					}
					else {
						quad[0].texCoords = sf::Vector2f(tileSize.x, 0);
						quad[1].texCoords = sf::Vector2f(2 * tileSize.x, 0);
						quad[2].texCoords = sf::Vector2f(2 * tileSize.x, tileSize.y - 1);
						quad[3].texCoords = sf::Vector2f(tileSize.x, tileSize.y - 1);
					}

				}
			}
			}, t * width / nthreads, (t + 1) * width / nthreads, t
				));
	}
	std::for_each(threads.begin(), threads.end(), [](std::thread& x) {x.join(); });
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
