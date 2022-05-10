#include "cell.h"

cell::cell() :
	alive(false){}

cell::cell(const cell& cellToBeCopied){
	*this = cellToBeCopied;
}

cell& cell::operator=(const cell& objectToBeCopiedFrom) {
	if (this != &objectToBeCopiedFrom) {
		alive = objectToBeCopiedFrom.alive;
	}
	else {
		return *this;
	}
}

void cell::setState(const bool& CellStateToBeSet) {
	alive = CellStateToBeSet;
}

bool cell::checkIfAlive() {
	if (alive) {
		return true;
	}
	else {
		return false;
	}
}