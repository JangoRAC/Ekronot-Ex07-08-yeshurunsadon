#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const Position& pos, bool isWhite);
	~Bishop();
	virtual bool canMove(const Position& dest) const override;
	virtual Piece* copy() const override;
};