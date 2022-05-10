#include "board.h"

board::board() :
	width(10),
	height(10) {

	cells.resize(height);
	for (int i = 0; i < height; i++) {
		cells[i].resize(width);
	}
}

board::board(const board& boardToBeKopied) {
	*this = boardToBeKopied;
}

board& board::operator=(const board& objectToBeCopiedFrom) {
	if (this != &objectToBeCopiedFrom) {
		width = objectToBeCopiedFrom.width;
		height = objectToBeCopiedFrom.height;
		cells = objectToBeCopiedFrom.cells;
	}
	else {
		return *this;
	}
}

void board::setWidth(const unsigned int& boardWidthToBeSetFrom) {
	width = boardWidthToBeSetFrom;
	cells.resize(height);
	for (int i = 0; i < height; i++) {
		cells[i].resize(width);
	}
}

void board::setHeight(const unsigned int& boardHeightToBeSetFrom) {
	height = boardHeightToBeSetFrom;
	cells.resize(height);
	for (int i = 0; i < height; i++) {
		cells[i].resize(width);
	}
}

void board::setBoardSize(const unsigned int& boardHeightToBeSetFrom, const unsigned int& boardWidthToBeSetFrom) {
	setWidth(boardWidthToBeSetFrom);
	setHeight(boardHeightToBeSetFrom);
	cells.resize(height);
	for (int i = 0; i < height; i++) {
		cells[i].resize(width);
	}
}

unsigned int board::getWidth() {
	return width;
}

unsigned int board::getHeight() {
	return height;
}

std::vector<std::vector<cell>> board::getCells() {
	return cells;
}