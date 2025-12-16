#pragma once
#include "Square.h"
#include <string>

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
	bool isSquareEmpty(const Position& pos) const;
};