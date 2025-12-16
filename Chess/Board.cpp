#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include <iostream>
Board::Board()
{
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			Position pos(row, col);
			_squares[row][col] = Square(pos);
		}
	}
	boardRepresentation = "";//to do work on the board reprsentation string for a visual representation of the board
	//setting the rooks
	Rook* blackRook1 = new Rook(Position(0, 0), false);
	Rook* blackRook2 = new Rook(Position(0, 7), false);
	Rook* whiteRook1 = new Rook(Position(7, 0), true);
	Rook* whiteRook2 = new Rook(Position(7, 7), true);

	_squares[0][0].setPiece(blackRook1);
	_squares[0][7].setPiece(blackRook2);
	_squares[7][0].setPiece(whiteRook1);
	_squares[7][7].setPiece(whiteRook2);
}

Board::~Board()
{
	// delete any pieces left on the board to avoid leaks
	for (int r = 0; r < 8; ++r)
	{
		for (int c = 0; c < 8; ++c)
		{
			Piece* p = _squares[r][c].getPiece();
			if (p != nullptr)
			{
				delete p;
				_squares[r][c].setPiece(nullptr);
			}
		}
	}
}

Square& Board::getSquare(const Position& pos)
{
	return _squares[pos.getRow()][pos.getCol()];

}
//implemented both const and non-const versions becuse i had errors otherwise
const Square& Board::getSquare(const Position& pos) const
{
	return _squares[pos.getRow()][pos.getCol()];
}

std::string Board::getBoardRepresentation() const
{
	return boardRepresentation;
}

bool Board::isPositionValid(const Position& pos) const
{
	int row = pos.getRow();
	int col = pos.getCol();
	return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

bool Board::isPathClear(const Position& start, const Position& end) const
{
	int startRow = start.getRow();
	int startCol = start.getCol();
	int endRow = end.getRow();
	int endCol = end.getCol();
	int rowStep = 0;
	//checking the direction the piece goes in the row
	if(endRow > startRow)
	{
		rowStep = 1;
	}
	else if(endRow < startRow)
	{
		rowStep = -1;
	}
	int colStep = 0;
	//checking the direction the piece goes in the colom
	if (endCol > startCol)
	{
		colStep = 1;
	}
	else if (endCol < startCol)
	{
		colStep = -1;
	}
	int currentRow = startRow + rowStep;
	int currentCol = startCol + colStep;
	while (currentRow != endRow || currentCol != endCol)
	{//checking if one of the squares in the way is ocupied
		if (_squares[currentRow][currentCol].IsOccupied())
		{
			return false;
		}
		currentRow += rowStep;
		currentCol += colStep;
	}
	return true;
}

bool Board::isSquareEmpty(const Position& pos) const
{
	return !_squares[pos.getRow()][pos.getCol()].IsOccupied();
}

int main()//wrote this main function to test the can move function on the rook (whold be deleted later)
{
	Board board;

	Position dest1(0, 5); // same row should be allowed 
	Position dest2(3, 0); // same column should be allowed
	Position dest3(1, 1); // diagonal should be false 
	Position dest4(0, 8); // intersects with piece with the same color shold be false
	std::cout << "0,0 to 0,5" << std::endl;
	if (board.getSquare(Position(0, 0)).getPiece()->canMove(dest1, board))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	std::cout << "0,0 to 3,0" << std::endl;
	if (board.getSquare(Position(0, 0)).getPiece()->canMove(dest2, board))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	std::cout << "0,0 to 1,1" << std::endl;
	if (board.getSquare(Position(0, 0)).getPiece()->canMove(dest3, board))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	std::cout << "0,0 to 0,8" << std::endl;
	if (board.getSquare(Position(0, 0)).getPiece()->canMove(dest4, board))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	return 0;
}