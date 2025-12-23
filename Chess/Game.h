#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();

	const bool getIsWhiteTurn() const;
	void makeTurn(Position src, Position dst);
	Board getBoard() const;

private:
	bool _isWhiteTurn;
	Board _board;
};