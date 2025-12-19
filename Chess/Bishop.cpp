#include "Bishop.h"

Bishop::Bishop(const Position& pos, bool isWhite) : Piece(pos, isWhite)
{
	isWhite ? this->_type = "B" : this->_type = "b";
}

Bishop::~Bishop()
{

}

bool Bishop::canMove(const Position& dest) const
{
	return abs(dest.getRow() - this->_position.getRow()) == abs(dest.getCol() - this->_position.getCol());
}

Piece* Bishop::copy() const
{
	return new Bishop(this->_position, this->_isWhite);
}

