#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const Position& pos, bool isWhite);
	~Rook();
	virtual bool canMove(const Position& dest) const override;
	virtual Piece* copy() const override;
};