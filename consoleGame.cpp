#include <iostream>
#include <string>
#include <windows.h>
#include "consoleGame.h"

consoleGame::consoleGame() :cellStyle('o') {}

consoleGame::consoleGame(const char& cellStyleToBeSet) : cellStyle(cellStyleToBeSet) {}

consoleGame::consoleGame(const consoleGame& objectToBeCopiedFrom) {
	*this = objectToBeCopiedFrom;
}

consoleGame& consoleGame::operator=(const consoleGame& objectToBeCopiedFrom) {
	if (this != &objectToBeCopiedFrom) {
		engine::operator=(objectToBeCopiedFrom);
		cellStyle = objectToBeCopiedFrom.cellStyle;
		return *this;
	}
	else {
		return *this;
	}
}

void consoleGame::setCellStyle(const char& cellStyleToBeSet) {
	cellStyle = cellStyleToBeSet;
}

char consoleGame::getCellStyle() {
	return cellStyle;
}

void consoleGame::init(const std::string& fileName) {
	engine::init(fileName);
}

void consoleGame::start() {
	displayInfo();
	while (getInput() != 13) {
		continue;
	}
	engine::start();
}

void consoleGame::displayInfo() {
	std::cout << "Press Enter to start" << std::endl;
}

char consoleGame::getInput() {

	HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE inHandle = GetStdHandle(STD_INPUT_HANDLE);

	INPUT_RECORD inReadBuffer[1];
	DWORD cNumRead;

	while (ReadConsoleInput(inHandle, inReadBuffer, 1, &cNumRead)) {
		if (inReadBuffer[0].EventType == KEY_EVENT) {
			if (inReadBuffer[0].Event.KeyEvent.bKeyDown) {
				char bufferCharacter = inReadBuffer[0].Event.KeyEvent.uChar.AsciiChar;

				if (bufferCharacter != 0) {
					return bufferCharacter;
				}
			}
		}
	}
}

void consoleGame::setCursorPosition() {
	COORD topLeft = { 0, 0 };
	HANDLE OutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(OutHandle, topLeft);
}

void consoleGame::display() {

	setCursorPosition();
	std::vector<std::vector<cell>> cellsFromBoard = cellsBoard.getCells();

	for (int i = 0; i < cellsBoard.getHeight(); i++) {
		for (int j = 0; j < cellsBoard.getWidth(); j++) {
			if (cellsFromBoard[i][j].checkIfAlive()) {
				std::cout << cellStyle << " ";
			}
			else {
				std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
	Sleep(200);
}

void consoleGame::failHandler(const std::string& errorType) {
	displayFailMessage(errorType);
}

void consoleGame::displayFailMessage(const std::string& errorType) {
	std::cout << "error: " + errorType<<std::endl;
}