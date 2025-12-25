#pragma once

class Position
{
public:
	Position();
	Position(int row, int col);
	~Position();
	const int getRow() const;
	const int getCol() const;
	
	bool operator==(const Position& other) const;
	
private:
	int _row;
	int _col;
};