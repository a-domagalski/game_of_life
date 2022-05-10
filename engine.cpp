#include <fstream>
#include <string>
#include "engine.h"

engine::engine() {
	cellsBoard.cells[4][4].setState(true);
	cellsBoard.cells[5][4].setState(true);
	cellsBoard.cells[6][4].setState(true);
}

engine::engine(const engine& objectToBeCopiedFrom) {
	*this = objectToBeCopiedFrom;
}

engine& engine::operator=(const engine& objectToBeCopiedFrom) {

	if (this != &objectToBeCopiedFrom) {
		cellsBoard = objectToBeCopiedFrom.cellsBoard;
	}
	else {
		return *this;
	}
}

engine::engine(const unsigned int& boardWidthToBeSetFrom, const unsigned int& boardHeightToBeSetFrom) {
	cellsBoard.setBoardSize(boardWidthToBeSetFrom, boardHeightToBeSetFrom);
}

board engine::getCellsBoard() {
	return cellsBoard;
}

void engine::setBoardSize(const unsigned int& heightToBeSet, const unsigned int& widthToBeSet) {
	cellsBoard.setBoardSize(heightToBeSet, widthToBeSet);
}

void engine::init(const std::string& fileName) {

	std::fstream initFile(fileName, std::ios::in);

	std::string statePlaceHolder;
	std::string dimPlaceHolder;

	if (initFile.good()) {
		std::getline(initFile, dimPlaceHolder, 'x');
		unsigned int height = std::stoi(dimPlaceHolder);

		std::getline(initFile, dimPlaceHolder);
		unsigned int width = std::stoi(dimPlaceHolder);

		cellsBoard.setBoardSize(height, width);

		for (unsigned int i = 0; i < height; i++) {
			for (unsigned int j = 0; j < width; j++) {

				if (initFile.eof()) {
					cellsBoard.cells[i][j].setState(false);
				}

				initFile >> statePlaceHolder;
				if (statePlaceHolder == "1") {
					cellsBoard.cells[i][j].setState(true);
				}
				else if (statePlaceHolder == "0") {
					cellsBoard.cells[i][j].setState(false);
				}
				/*
				* if incorrect state - set false:
				*/
				else {
					cellsBoard.cells[i][j].setState(false);
				}
			}
		}
	}
	if (initFile.fail()) {
		if (!initFile.eof()) {
			failHandler("file access");
		}
	}
	initFile.close();
}

void engine::start() {

	while (true) {
		display();
		updateCells();
	}
}

void engine::updateCells() {
	cellsBoard.cells = analize();
}

short engine::countCellNeighbours(const int& i, const int& j) {

	short aliveNeighboursCounter = 0;

	int neighboursCoords[8][2]{
			{i,j - 1},
			{i,j + 1},
			{i + 1,j },
			{i + 1,j - 1},
			{i + 1,j + 1},
			{i - 1,j},
			{i - 1,j - 1},
			{i - 1,j + 1}
	};
	for (unsigned int k = 0; k < 8; k++) {
	
		if (neighboursCoords[k][0]<0 || neighboursCoords[k][0]>cellsBoard.height - 1 ||
			neighboursCoords[k][1]<0 || neighboursCoords[k][1]>cellsBoard.width - 1) {
			continue;
		}
		if (cellsBoard.cells[neighboursCoords[k][0]][neighboursCoords[k][1]].checkIfAlive()) {
			aliveNeighboursCounter++;
		}
	}
	return aliveNeighboursCounter;

}

bool engine::evaluateCellState(const int& i, const int& j) {

	short aliveNeighboursNumber = countCellNeighbours(i, j);

	if (aliveNeighboursNumber < 2 || aliveNeighboursNumber > 3) {
		return false;
	}
	else if (aliveNeighboursNumber == 3) {
		return true;
	}
	else if (cellsBoard.cells[i][j].checkIfAlive()) {
		return true;
	}
}

std::vector <std::vector<cell>> engine::analize() {

	int boardWidth = cellsBoard.width;
	int boardHeight = cellsBoard.height;

	std::vector <std::vector<cell>> newCellsStates;
	newCellsStates.resize(cellsBoard.cells.size());

	for (int i = 0; i < newCellsStates.size(); i++) {
		newCellsStates[i].resize(cellsBoard.cells[i].size());
	}

	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			newCellsStates[i][j].setState(evaluateCellState(i, j));
		}
	}
	return newCellsStates;
}