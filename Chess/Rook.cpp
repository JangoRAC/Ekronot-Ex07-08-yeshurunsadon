#include "Rook.h"

Rook::Rook(const Position& pos, bool isWhite) : Piece(pos, isWhite)
{
	isWhite ? this->_type = "R" : this->_type = "r";
}

Rook::~Rook()
{
}

bool Rook::canMove(const Position& dest) const
{
	Position currentPos = this->getPosition();
	// Rook can move only in straight lines (same row or same column)
	if (currentPos.getRow() != dest.getRow() && currentPos.getCol() != dest.getCol())
	{
		return false;
	}
	return true;
}

