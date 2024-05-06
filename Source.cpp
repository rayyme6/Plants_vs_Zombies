#include <SFML/Graphics.hpp>
#include <ctime>
#include "Peashooter.h"
#include "Plant_Factory.h"
using namespace sf;

struct coordinats {
	int x;
	int y;
};



//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("Images/backwindow.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("Images/grid.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(200, 80);

	window.draw(s_map);
}
Peashooter pee;
const int MAX_PEASHOOTERS = 100; // Maximum number of peashooters
coordinats peashooterPositions[MAX_PEASHOOTERS]; // Store positions of placed peashooters
int numPeashooters = 0; // Track the number of placed peashooters

int main()
{
	Plant_Factory plantFactory; // plant factory
	pee.setImage();
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];
	Plant* plants[ROWS][COLS]; // plants array

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	Clock timeMoney;



	Clock clock;

	sf::FloatRect clickArea(0, 0, 1200, 700);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				int row = (event.mouseButton.y - 80) / 108; // Calculate the row
				int col = (event.mouseButton.x - 200) / 108; // Calculate the column
				
				// Make sure the clicked position is inside the grid
				if (row >= 0 && row < ROWS && col >= 0 && col < COLS && FIELD_GAME_STATUS[row][col]) {
					// Spawn the sprite at the clicked position
					plants[row][col] = plantFactory.newPeashooter();
					plants[row][col]->setImage();
					plants[row][col]->spawn(col * 80 + 250, row * 100 + 80);

					// Store the position of the placed peashooter
					peashooterPositions[numPeashooters].x = event.mouseButton.x;
					peashooterPositions[numPeashooters].y = event.mouseButton.y;
					numPeashooters++;

					// Ensure we don't exceed the maximum number of peashooters
					if (numPeashooters >= MAX_PEASHOOTERS) {
						return 1;
					}

					// Update the grid status
					FIELD_GAME_STATUS[row][col] = false;
				}
			}
		}

		//Create a background
		createBack(window);
		createMap(window);

		//for (int i = 0; i < numPeashooters; ++i) {
		//	pee.spawnPeashooter(peashooterPositions[i].x, peashooterPositions[i].y);
		//	pee.drawPeashooter(window);
		//}
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				if (FIELD_GAME_STATUS[i][j]) continue;
				window.draw(plants[i][j]->getImage());
			}
		}

		window.display();
	}
	return 0;
}