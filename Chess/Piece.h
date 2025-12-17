#pragma once
#include "Position.h"
#include <string>

class Board;

class Piece
{
public:
	Piece(const Position& pos, bool isWhite);
	~Piece();
	const Position getPosition() const;
	const bool isWhite() const;
	std::string getType() const;
	virtual bool canMove(const Position& dst) const = 0;
	void move(const Position& dst);

protected:
	Position _position;
	bool _isWhite;
	std::string _type;
};