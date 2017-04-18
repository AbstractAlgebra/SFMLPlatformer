#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
	Game game;
	while (true)
	{
		game.update();
		game.render();
	}
}