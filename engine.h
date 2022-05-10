#ifndef ENGINE_H
#define ENGINE_H

#include "board.h"

class engine
{
protected:
	board cellsBoard;

	virtual void failHandler(const std::string&) {};
public:

	engine();
	engine(const engine&);
	engine(const unsigned int&, const unsigned int&);
	engine& operator=(const engine&);
	virtual ~engine(){}

	board getCellsBoard();

	virtual void setBoardSize(const unsigned int&, const unsigned int&);
	virtual void init(const std::string&);
	virtual void start();
	virtual char getInput() = 0;
	virtual void display() = 0;
	void updateCells();
	std::vector <std::vector<cell>> analize();

private:
	short countCellNeighbours(const int&, const int&);
	bool evaluateCellState(const int&, const int&);
};
#endif
