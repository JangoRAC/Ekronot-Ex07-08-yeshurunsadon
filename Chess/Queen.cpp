#include "Queen.h"

Queen::Queen(const Position& pos, bool isWhite) : Piece(pos, isWhite)
{
	isWhite ? this->_type = "Q" : this->_type = "q";
}

Queen::~Queen()
{
}

bool Queen::canMove(const Position& dest) const
{
	bool moveStraight = this->getPosition().getRow() == dest.getRow() || this->getPosition().getCol() == dest.getCol();
	bool moveDaiagnal = abs(dest.getRow() - this->_position.getRow()) == abs(dest.getCol() - this->_position.getCol());
	return moveStraight || moveDaiagnal;
}

Piece* Queen::copy() const
{
	return new Queen(this->_position, this->_isWhite);
}

