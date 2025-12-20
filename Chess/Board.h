#pragma once
#include "Square.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h";
#include "Knight.h"
#include "Pon.h"
#include <iostream>
#include <string>

class Piece;

class Board
{
protected:
	Square _squares[8][8];
	std::string _boardRepresentation;

public:
	Board();
	~Board();
	Board(const Board& other);

	Square& getSquare(const Position& pos);
	const Square& getSquare(const Position& pos) const;//implemented both const and non-const versions becuse i had errors otherwise
	std::string getBoardRepresentation() const;

	void updateBoard();

	bool isPositionValid(const Position& pos) const;
	bool isPathClear(const Position& start, const Position& end) const;
	bool isSquareEmpty(const Position& pos) const;
	bool canMove(const Position& src, const Position& dst) const;
	void move(const Position& src, const Position& dst);
	bool canSquereBeAttacked(const Position& pos, bool attackerIsWhite) const;
	bool isKingInCheck(bool isWhiteKing) const;
	bool wouldMoveExposeKing(const Position& src, const Position& dst) const;
	bool canPonMove(const Position& src, const Position& dst) const;
	bool isTherePieceInDiagonal(const Position& pos) const;
	
};