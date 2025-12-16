#pragma once
#include "Position.h"
#include <string>
class Board;//for using the board in this class for the can move function
class Piece
{
protected:
	Position _position;
	bool _isWhite;
	std::string _type;
public:
	Piece(const Position& pos, bool isWhite);
	~Piece();
	const Position getPosition() const;
	void setPosition(const Position& pos);
	const bool isWhite() const;
	std::string getType() const;
	virtual bool canMove(const Position& dest, const Board& board) const = 0;
};