#include "Knight.h"

Knight::Knight(const Position& pos, bool isWhite) : Piece(pos, isWhite)
{
	isWhite ? this->_type = "N" : this->_type = "n";
}

Knight::~Knight()
{

}

bool Knight::canMove(const Position& dest) const
{
	int rowDiff = abs(this->_position.getRow() - dest.getRow());
	int colDiff = abs(this->_position.getCol() - dest.getCol());
	return (rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1);
}

Piece* Knight::copy() const
{
	return new Knight(this->_position, this->_isWhite);
}


