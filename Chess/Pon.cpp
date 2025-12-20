#include "Pon.h"

Pon::Pon(const Position& pos, bool isWhite) : Piece(pos, isWhite)
{
	isWhite ? this->_type = "P" : this->_type = "p";
	pieceInDiagonal = false;
}

Pon::~Pon()
{
}

bool Pon::canMove(const Position& dest) const
{
	int direction = 0;
	int startRow = 0;
	int rowDiff = dest.getRow() - this->_position.getRow();
	int colDiff = abs(this->_position.getCol() - dest.getCol());
	if (this->_isWhite)
	{
		direction = 1;
	}
	else
	{
		direction = -1;
	}
	if (this->_isWhite)
	{
		startRow = 1;
	}
	else
	{
		startRow = 6;
	}
	if (rowDiff == direction && colDiff == 0)
	{
		return true;
	}
	if (this->_position.getRow() == startRow && rowDiff == direction * 2 && colDiff == 0)
	{
		return true;
	}
	if (pieceInDiagonal && colDiff == 1 && rowDiff == direction)
	{
		return true;
	}
	return false;

}

Piece* Pon::copy() const
{
	return new Pon(this->_position, this->_isWhite);
}

void Pon::setPieceInDiagonal(bool pieceInDiagonal)
{
	this->pieceInDiagonal = pieceInDiagonal;
}

bool Pon::canPonAttack(const Position& dest)
{
	int direction = 0;
	if (this->_isWhite)
	{
		direction = 1;
	}
	else
	{
		direction = -1;
	}
	return dest.getRow() == this->_position.getRow() + direction && abs(dest.getCol() - this->_position.getCol()) == 1;
}



