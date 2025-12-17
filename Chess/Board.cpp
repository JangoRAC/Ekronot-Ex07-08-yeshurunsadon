#include "Board.h"

Board::Board()
{
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			this->_squares[row][col] = Square(Position(row, col));
		}
	}
	this->_boardRepresentation = "";
	Rook* blackRook1 = new Rook(Position(0, 0), false);
	Rook* blackRook2 = new Rook(Position(0, 7), false);
	Rook* whiteRook1 = new Rook(Position(7, 0), true);
	Rook* whiteRook2 = new Rook(Position(7, 7), true);

	this->_squares[0][0].setPiece(blackRook1);
	this->_squares[0][7].setPiece(blackRook2);
	this->_squares[7][0].setPiece(whiteRook1);
	this->_squares[7][7].setPiece(whiteRook2);

	this->updateBoard();
}

Board::~Board()
{
	// delete any pieces left on the board to avoid leaks
	for (int r = 0; r < 8; ++r)
	{
		for (int c = 0; c < 8; ++c)
		{
			Piece* p = _squares[r][c].getPiece();
			if (p)
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
	return _boardRepresentation;
}

void Board::updateBoard()
{
	this->_boardRepresentation = "";

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			Piece* piece = this->_squares[i][j].getPiece();
			!piece ? this->_boardRepresentation += '#' : this->_boardRepresentation += this->_squares[i][j].getPiece()->getType();
		}
		if (i < 7)
		{//adding new line except for the last row becuse i had issuses otherwise
			this->_boardRepresentation += '\n';
		}
		
	}
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
	if(!isPositionValid(src) || !isPositionValid(dst))
	{
		return false;
	}
	if(!srcPiece)
	{
		return false; // No piece at source
	}
	// Check if the path is clear
	if (!this->isPathClear(src, dst))
	{
		return false;
	}
	// Check if the destination square is either empty or occupied by an opponent's piece
	if (!this->isSquareEmpty(dst) && !this->isSquareEmpty(src))
	{
		if (dstPiece->isWhite() == srcPiece->isWhite())
		{
			return false; // Can't capture own piece
		}
	}
	if (srcPiece)
	{
		return srcPiece->canMove(dst);
	}
	return false;
}

void Board::move(Position src, Position dst)
{
	Piece* srcPiece = this->getSquare(src).getPiece();
	if (this->canMove(src, dst))
	{
		srcPiece->move(dst);//update the piece position
		// Move the piece on the board
		this->_squares[dst.getRow()][dst.getCol()].setPiece(srcPiece);
		this->_squares[src.getRow()][src.getCol()].setPiece(nullptr);
		this->updateBoard();
	}

}

bool Board::isSquareEmpty(const Position& pos) const
{
	return !_squares[pos.getRow()][pos.getCol()].IsOccupied();
}

int main()//wrote this main function to test the can move function on the rook (whold be deleted later)
{
	Board board;
	Position src1(0, 0);
	Position src2(7, 0);
	Position src3(0, 7);
	Position src4(7, 7);

	Position pos1(7, 0); // same row should be allowed 
	Position pos2(7, 7); // same column should be allowed
	Position pos3(0, 5); // diagonal should be false 
	Position pos4(6, 6); // intersects with piece with the same color shold be false
	Position pos5(7, 5);

	std::cout << board.getBoardRepresentation() << std::endl;

	std::cout << "0,0 to 0,7" << std::endl;
	board.move(src1, pos1); //false - cant eat a piece same color as yours

	std::cout << board.getBoardRepresentation() << std::endl;

	std::cout << "0,0 to 7,0" << std::endl;
	board.move(src2, pos2); //true - can eat a piece different color from yours

	std::cout << board.getBoardRepresentation() << std::endl;
	
	std::cout << "0,7 to 0,5" << std::endl;
	board.move(src3, pos3); //true - same row

	std::cout << board.getBoardRepresentation() << std::endl;
	
	std::cout << "7,7 to 6,6" << std::endl;
	board.move(src4, pos4); //false - cant move diagonaly

	std::cout << board.getBoardRepresentation() << std::endl;

	std::cout << "7,7 to 7,5" << std::endl;
	board.move(src4, pos5); //true - same row
	std::cout << board.getBoardRepresentation() << std::endl;

	std::cout << "7,5 to 0,5" << std::endl;
	board.move(pos5, pos3); //false - cant eat a piece same color as yours

	return 0;
}