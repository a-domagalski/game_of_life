#ifndef CONSOLEGAME_H
#define CONSOLEGAME_H

#include "engine.h"

class consoleGame : public engine
{
protected:
	char cellStyle;

	void displayInfo();
	void displayFailMessage(const std::string&);
	void failHandler(const std::string&);
public:

	consoleGame();
	consoleGame(const char&);
	consoleGame(const consoleGame&);
	consoleGame& operator=(const consoleGame&);

	void setCellStyle(const char&);
	char getCellStyle();
	void start();
	void init(const std::string&);
	
	char getInput();
	void setCursorPosition();
	void display();
};
#endif
