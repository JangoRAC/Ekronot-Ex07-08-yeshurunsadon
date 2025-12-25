#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(const Position& pos, bool isWhite);
	~Knight();
	virtual bool canMove(const Position& dest) const override;
	virtual Piece* copy() const override;

};