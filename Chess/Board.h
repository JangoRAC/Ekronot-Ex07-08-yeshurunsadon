#pragma once
#include "Square.h"
#include "Rook.h"
#include <iostream>
#include <string>

class Piece;

class Board
{
protected:
	Square _squares[8][8];
	std::string boardRepresentation;

public:
	Board();
	~Board();
	Square& getSquare(const Position& pos);
	const Square& getSquare(const Position& pos) const;//implemented both const and non-const versions becuse i had errors otherwise
	std::string getBoardRepresentation() const;
	bool isPositionValid(const Position& pos) const;
	bool isPathClear(const Position& start, const Position& end) const;
	bool canMove(Position& src, Position& dst);
	void move(Position& src, Position& dst);
	bool isSquareEmpty(const Position& pos) const;
};