#include "Square.h"

Square::Square()
{
	this->_position = Position(0,0);
	this->_piece = nullptr;
}

Square::Square(const Position& pos)
{
	this->_position = pos;
	this->_piece = nullptr;
}

Square::~Square()
{
	this->_piece = nullptr;
}

Piece* Square::getPiece() const
{
	return this->_piece;
}

Position Square::getPosition() const
{
	return this->_position;
}

bool Square::IsOccupied() const
{
	return this->_piece;
}

void Square::setPiece(Piece* piece)
{
	this->_piece = piece;
}

