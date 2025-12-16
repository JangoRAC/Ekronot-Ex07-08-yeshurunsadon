#include "Piece.h"

Piece::Piece(const Position& pos, bool isWhite)
{
	this->_position = pos;
	this->_isWhite = isWhite;
}

Piece::~Piece()
{
}

const Position Piece::getPosition() const
{
	return this->_position;
}

void Piece::setPosition(const Position& pos)
{
	this->_position = pos;
}

const bool Piece::isWhite() const
{
	return this->_isWhite;
}

