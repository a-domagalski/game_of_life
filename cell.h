#ifndef CELL_H
#define CELL_H

class cell
{
private:
	bool alive;
public:

	cell();
	cell(const cell&);
	cell& operator=(const cell&);

	void setState(const bool&);
	bool checkIfAlive();
};
#endif
