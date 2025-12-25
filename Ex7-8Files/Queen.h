#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(const Position& pos, bool isWhite);
	~Queen();
	virtual bool canMove(const Position& dest) const override;
	virtual Piece* copy() const override;

};