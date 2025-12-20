#pragma once
#include "Piece.h"

class Pon : public Piece
{
private:
	bool pieceInDiagonal;
public:
	Pon(const Position& _pos, bool _isWhite);
	~Pon();
	virtual bool canMove(const Position& dest) const override;
	virtual Piece* copy() const override;
	void setPieceInDiagonal(bool pieceInDiagonal);
	bool canPonAttack(const Position& dest);//for detecting chess
};