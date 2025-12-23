#include "Game.h"

Game::Game()
{
	this->_isWhiteTurn = true;
	//leave it commented because it works without this line for some reason
	//this->_board = Board();
}

Game::~Game()
{

}

const bool Game::getIsWhiteTurn() const
{
	return this->_isWhiteTurn;
}

void Game::makeTurn(Position src, Position dst)
{
	if (this->_board.canMove(src, dst) && 
		!this->_board.wouldMoveExposeKing(src, dst))
	{
		this->_board.move(src, dst);
		this->_isWhiteTurn = !this->_isWhiteTurn;
	}
}

Board Game::getBoard() const
{
	return this->_board;
}

int main()
{
	Game game = Game();
	game.makeTurn(Position(1, 0), Position(2, 0));
	std::cout << game.getBoard().getBoardRepresentation() << std::endl;

	return 0;
}