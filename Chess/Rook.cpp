#include "Rook.h"
#include "Board.h"
Rook::Rook(const Position& pos, bool isWhite) : Piece(pos, isWhite)
{
	_type = "Rook";
}

Rook::~Rook()
{
}

bool Rook::canMove(const Position& dest, const Board& board) const
{
	Position currentPos = this->getPosition();
	// Rook can move only in straight lines (same row or same column)
	if (currentPos.getRow() != dest.getRow() && currentPos.getCol() != dest.getCol())
	{
		return false;
	}
	// Check if the path is clear
	if (!board.isPathClear(currentPos, dest))
	{
		return false;
	}
	// Check if the destination square is either empty or occupied by an opponent's piece
	if (!board.isSquareEmpty(dest))
	{
		Piece* destPiece = board.getSquare(dest).getPiece();
		if (destPiece->isWhite() == this->isWhite())
		{
			return false; // Can't capture own piece
		}
	}
	return true;
}