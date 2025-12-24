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

int Game::makeTurn(Position src, Position dst)
{//check if the move is valid and the moved player is in the correct color
	int code = 0;
	Piece* dstPiece = this->_board.getSquare(dst).getPiece();
	Piece* srcPiece = this->_board.getSquare(dst).getPiece();
	if (this->_board.canMove(src, dst) && !this->_board.wouldMoveExposeKing(src, dst) && this->_board.getSquare(src).getPiece()->isWhite() == this->_isWhiteTurn)
	{
		this->_board.move(src, dst);
		if(this->_board.isKingInCheck(!this->_isWhiteTurn))
		{
			code = 1;
		}
		this->_isWhiteTurn = !this->_isWhiteTurn;
	}
	else if (!this->_board.getSquare(src).getPiece() || 
	this->_board.getSquare(src).getPiece()->isWhite() != this->_isWhiteTurn)
	{
		code = 2;
	}
	else if(dstPiece && dstPiece->isWhite() == srcPiece->isWhite())
	{
		code = 3;
	}
	else if (this->_board.wouldMoveExposeKing(src, dst))
	{
		code = 4;
	}
	else if (!this->_board.isPositionValid(src) || !this->_board.isPositionValid(dst))
	{
		code = 5;
	}
	else if (!srcPiece->canMove(dst))
	{
		code = 6;
	}
	else if (src == dst)
	{
		code = 7;
	}
	return code;
}

Board Game::getBoard() const
{
	return this->_board;
}

Position* Game::getPositionFromMessage(const std::string msg)
{
	Position positions[2] = { Position(msg[0] - 'a' + '0', msg[1] - '0'), Position(msg[2] - 'a' + '0', msg[3] - '0') };

	return positions;
}

//int main()
//{
//	Game game = Game();
//
//	std::cout << "6, 0 to 5, 0" << std::endl;
//	game.makeTurn(Position(6, 0), Position(5, 0));//should not move
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "1, 0 to 2, 0" << std::endl;
//	game.makeTurn(Position(1, 0), Position(2, 0));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "2, 0 to 3, 0" << std::endl;
//	game.makeTurn(Position(2, 0), Position(3, 0));//shold not move
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "6, 0 to 5, 0" << std::endl;
//	game.makeTurn(Position(6, 0), Position(5, 0));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "0, 0 to 4, 0" << std::endl;
//	game.makeTurn(Position(0, 0), Position(4, 0));//shoul not move
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "0, 0 to 1, 0" << std::endl;
//	game.makeTurn(Position(0, 0), Position(1, 0));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "0, 6 to 2, 5" << std::endl;
//	game.makeTurn(Position(0, 6), Position(2, 5));//shold not move
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//	
//	std::cout << "7, 6 to 5, 5" << std::endl;
//	game.makeTurn(Position(7, 6), Position(5, 5));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "0, 6 to 2, 5" << std::endl;
//	game.makeTurn(Position(0, 6), Position(2, 5));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "6, 1 to 4, 1" << std::endl;
//	game.makeTurn(Position(6, 1), Position(4, 1));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "2, 0 to 3, 0" << std::endl;
//	game.makeTurn(Position(2, 0), Position(3, 0));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//	std::cout << "4, 1 to 3, 0" << std::endl;
//	game.makeTurn(Position(4, 1), Position(3, 0));
//	std::cout << game.getBoard().getBoardRepresentation() << std::endl;
//
//
//	return 0;
//}