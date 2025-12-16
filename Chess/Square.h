#pragma once
#include "Position.h"
#include "Piece.h"
class Square
{
public:
	Square();
	Square(const Position& pos);
	~Square();
	Piece* getPiece() const;
	Position getPosition() const;
	bool IsOccupied() const;
	void setPiece(Piece* piece);

private:
	Position _position;
	Piece* _piece;
};