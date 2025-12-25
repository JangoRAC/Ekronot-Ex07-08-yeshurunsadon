#pragma once
#include "Piece.h"

class King : public Piece
{
	public:
	King(const Position& pos, bool isWhite);
	~King();
	virtual bool canMove(const Position& dst) const override;
	virtual Piece* copy() const override;
};