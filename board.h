#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "cell.h"

class board
{
protected:
	unsigned int width;
	unsigned int height;
	std::vector<std::vector<cell>> cells;
public:

	board();
	board(const board&);
	board& operator=(const board&);

	void setWidth(const unsigned int&);
	void setHeight(const unsigned int&);
	void setBoardSize(const unsigned int&, const unsigned int&);

	unsigned int getWidth();
	unsigned int getHeight();
	std::vector<std::vector<cell>> getCells();
	
	friend class engine;
};
#endif
