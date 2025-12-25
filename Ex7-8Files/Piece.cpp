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

const bool Piece::isWhite() const
{
	return this->_isWhite;
}

std::string Piece::getType() const
{
	return this->_type;
}

void Piece::move(const Position& dst)
{
	this->_position = dst;
}