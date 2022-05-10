#include <iostream>
#include "consoleGame.h"

int main()
{
	engine* gameEngine;
	gameEngine = new consoleGame('o');
	gameEngine->init("initInput40x100.txt");
	gameEngine->start();
}