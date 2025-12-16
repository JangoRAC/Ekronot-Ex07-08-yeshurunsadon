#pragma once
#include "Position.h"
class Piece
{
protected:
	Position _position;
	bool _isWhite;
public:
	Piece(const Position& pos, bool isWhite);
	virtual ~Piece();
	const Position getPosition() const;
	void setPosition(const Position& pos);
	const bool isWhite() const;
	
};