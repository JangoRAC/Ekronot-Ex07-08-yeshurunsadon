#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();

	const bool getIsWhiteTurn() const;
	int makeTurn(Position src, Position dst);
	Board getBoard() const;
	Position* getPositionFromMessage(const std::string msg);

private:
	bool _isWhiteTurn;
	Board _board;
};