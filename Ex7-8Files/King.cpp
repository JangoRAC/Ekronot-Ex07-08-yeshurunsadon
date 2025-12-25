#include "King.h"

King::King(const Position& pos, bool isWhite) : Piece(pos, isWhite)
{
	isWhite ? this->_type = "K" : this->_type = "k";
}

King::~King()
{
}

bool King::canMove(const Position& dst) const
{
	Position currentPos = this->getPosition();
	int rowDiff = abs(currentPos.getRow() - dst.getRow());
	int colDiff = abs(currentPos.getCol() - dst.getCol());
	// King can move only one square in any direction
	if (rowDiff <= 1 && colDiff <= 1 && (rowDiff + colDiff) > 0)
	{
		return true;
	}
	return false;
}

Piece* King::copy() const
{
	return new King(this->_position, this->_isWhite);
}