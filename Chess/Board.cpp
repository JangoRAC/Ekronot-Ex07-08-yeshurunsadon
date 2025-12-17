#include "Board.h"

Board::Board()
{
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			_squares[row][col] = Square(Position(row, col));
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
	int colStep = 0;
	int currentRow = 0;
	int currentCol = 0;

	//checking the direction the piece goes in the row
	endRow > startRow ? rowStep = 1 : (endRow < startRow ? rowStep = -1 : rowStep = 0);

	//checking the direction the piece goes in the colom
	endCol > startCol ? colStep = 1 : (endCol < startCol ? colStep = -1 : colStep = 0);

	currentRow = startRow + rowStep;
	currentCol = startCol + colStep;
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

bool Board::canMove(Position& src, Position& dst)
{
	Piece* srcPiece = this->getSquare(src).getPiece();
	Piece* dstPiece = this->getSquare(dst).getPiece();

	// Check if the path is clear
	if (!this->isPathClear(src, dst))
	{
		return false;
	}
	// Check if the destination square is either empty or occupied by an opponent's piece
	if (!this->isSquareEmpty(dst))
	{
		std::cout << "not clear" << std::endl;
		if (dstPiece->isWhite() == srcPiece->isWhite())
		{
			return false; // Can't capture own piece
		}
	}
	else
	{
		return srcPiece->canMove(dst);
	}
	
}

void Board::move(Position& src, Position& dst)
{
	Piece* srcPiece = this->getSquare(src).getPiece();
	if (this->canMove(src, dst))
	{
		srcPiece->move(dst);
	}
}

bool Board::isSquareEmpty(const Position& pos) const
{
	return !_squares[pos.getRow()][pos.getCol()].IsOccupied();
}

int main()//wrote this main function to test the can move function on the rook (whold be deleted later)
{
	Board board;
	Position src(0, 0);
	Position dest1(0, 5); // same row should be allowed 
	Position dest2(3, 0); // same column should be allowed
	Position dest3(1, 1); // diagonal should be false 
	Position dest4(0, 8); // intersects with piece with the same color shold be false
	std::cout << "0,0 to 0,5" << std::endl;
	if (board.canMove(src, dest1))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	std::cout << "0,0 to 3,0" << std::endl;
	if (board.canMove(src, dest2))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	std::cout << "0,0 to 1,1" << std::endl;
	if (board.canMove(src, dest1))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	std::cout << "0,0 to 0,8" << std::endl;
	if (board.canMove(src, dest1))
	{
		std::cout << "can move" << std::endl;
	}
	else
	{
		std::cout << "cant move" << std::endl;
	}
	return 0;
}