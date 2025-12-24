#include "Board.h"

Board::Board()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			this->_squares[row][col] = Square(Position(row, col));
		}
	}
	this->_boardRepresentation = "";
	//placin pieces on the board
	Rook* blackRook1 = new Rook(Position(7, 0), false);
	Rook* blackRook2 = new Rook(Position(7, 7), false);
	Rook* whiteRook1 = new Rook(Position(0, 0), true);
	Rook* whiteRook2 = new Rook(Position(0, 7), true);

	this->_squares[7][0].setPiece(blackRook1);
	this->_squares[7][7].setPiece(blackRook2);
	this->_squares[0][0].setPiece(whiteRook1);
	this->_squares[0][7].setPiece(whiteRook2);

	King* blackKing = new King(Position(7, 3), false);
	King* whiteKing = new King(Position(0, 3), true);
	this->_squares[7][3].setPiece(blackKing);
	this->_squares[0][3].setPiece(whiteKing);


	Bishop* whiteBishop1 = new Bishop(Position(0, 2), true);
	Bishop* whiteBishop2 = new Bishop(Position(0, 2), true);
	Bishop* blackBishop1 = new Bishop(Position(7, 2), false);
	Bishop* blackBishop2 = new Bishop(Position(7, 2), false);
	this->_squares[0][2].setPiece(whiteBishop1);
	this->_squares[0][5].setPiece(whiteBishop2);
	this->_squares[7][2].setPiece(blackBishop1);
	this->_squares[7][5].setPiece(blackBishop2);

	Queen* whiteQueen = new Queen(Position(0,4), true);
	Queen* blackQueen = new Queen(Position(7, 4), false);
	this->_squares[0][4].setPiece(whiteQueen);
	this->_squares[7][4].setPiece(blackQueen);

	Knight* whiteKnight1 = new Knight(Position(0, 1), true);
	Knight* whiteKnight2 = new Knight(Position(0, 6), true);
	Knight* blackKnight1 = new Knight(Position(7, 1), false);
	Knight* blackKnight2 = new Knight(Position(7, 6), false);
	this->_squares[0][1].setPiece(whiteKnight1);
	this->_squares[0][6].setPiece(whiteKnight2);
	this->_squares[7][1].setPiece(blackKnight1);
	this->_squares[7][6].setPiece(blackKnight2);
	
	Pon* whitePon1 = new Pon(Position(1, 0), true);
	Pon* whitePon2 = new Pon(Position(1, 1), true);
	Pon* whitePon3 = new Pon(Position(1, 2), true);
	Pon* whitePon4 = new Pon(Position(1, 3), true);
	Pon* whitePon5 = new Pon(Position(1, 4), true);
	Pon* whitePon6 = new Pon(Position(1, 5), true);
	Pon* whitePon7 = new Pon(Position(1, 6), true);
	Pon* whitePon8 = new Pon(Position(1, 7), true);
	this->_squares[1][0].setPiece(whitePon1);
	this->_squares[1][1].setPiece(whitePon2);
	this->_squares[1][2].setPiece(whitePon3);
	this->_squares[1][3].setPiece(whitePon4);
	this->_squares[1][4].setPiece(whitePon5);
	this->_squares[1][5].setPiece(whitePon6);
	this->_squares[1][6].setPiece(whitePon7);
	this->_squares[1][7].setPiece(whitePon8);

	Pon* blackPon1 = new Pon(Position(6, 0), false);
	Pon* blackPon2 = new Pon(Position(6, 1), false);
	Pon* blackPon3 = new Pon(Position(6, 2), false);
	Pon* blackPon4 = new Pon(Position(6, 3), false);
	Pon* blackPon5 = new Pon(Position(6, 4), false);
	Pon* blackPon6 = new Pon(Position(6, 5), false);
	Pon* blackPon7 = new Pon(Position(6, 6), false);
	Pon* blackPon8 = new Pon(Position(6, 7), false);
	this->_squares[6][0].setPiece(blackPon1);
	this->_squares[6][1].setPiece(blackPon2);
	this->_squares[6][2].setPiece(blackPon3);
	this->_squares[6][3].setPiece(blackPon4);
	this->_squares[6][4].setPiece(blackPon5);
	this->_squares[6][5].setPiece(blackPon6);
	this->_squares[6][6].setPiece(blackPon7);
	this->_squares[6][7].setPiece(blackPon8);

	this->updateBoard();

	
}





Board::~Board()
{
	// delete any pieces left on the board to avoid leaks
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
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



Board::Board(const Board& other)
{
	Piece* otherPiece = nullptr;
	// Copy squares
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			this->_squares[row][col] = Square(Position(row, col));
		}
	}
	this->_boardRepresentation = other._boardRepresentation;//copy board representatio
	//copy picecs
	for(int row = 0; row < 8; row++)
	{
		for(int col = 0; col < 8; col++)
		{
			otherPiece = other._squares[row][col].getPiece();
			if(otherPiece)
			{
				this->_squares[row][col].setPiece(otherPiece->copy());
			}
			else
			{
				this->_squares[row][col].setPiece(nullptr);
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

bool Board::canMove(const Position& src, const Position& dst) const
{

	Piece* srcPiece = this->getSquare(src).getPiece();
	Piece* dstPiece = this->getSquare(dst).getPiece();
	if(!isPositionValid(src) || !isPositionValid(dst))
	{
		return false;
	}
	if (src == dst)
	{
		return false;
	}
	if(!srcPiece)
	{
		return false; // No piece at source
	}
	if (srcPiece->getType() == "P" || srcPiece->getType() == "p")
	{
		return canPonMove(src, dst);//specificly for the pon logic
	}
	// Check if the path is clear
	if (!this->isPathClear(src, dst) && srcPiece->getType() != "N" && srcPiece->getType() != "n")
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

void Board::move(const Position& src, const Position& dst)
{
	Piece* srcPiece = this->getSquare(src).getPiece();
	if (this->canMove(src, dst) && !this->wouldMoveExposeKing(src, dst))
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

bool Board::canSquereBeAttacked(const Position& pos, bool attackerIsWhite) const
{
	Piece* piece = nullptr;
	// Iterate through all squares on the board
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			piece = _squares[row][col].getPiece();
			// Check if there is a piece of the attacking color
			if (piece && piece->isWhite() == attackerIsWhite)
			{

				// Check if this piece can move to the target position
				if (this->canMove(piece->getPosition(), pos) && piece->getType() != "P" && piece->getType() != "p")
				{					
					return true; // The square can be attacked
				}
				if (piece->getType() == "P" || piece->getType() == "p")
				{
					Pon* pon = (Pon*)(piece);
					if (pon->canPonAttack(pos))
					{
						return true;
					}
				}
			}
		}
	}
	return false; // No attacking pieces can reach the square
}



bool Board::wouldMoveExposeKing(const Position& src, const Position& dst) const
{
	Board tempBoard(*this); // Create a copy of the current board
	Piece* movingPiece = tempBoard.getSquare(src).getPiece();
	if (!movingPiece)
	{
		return false; // No piece to move
	}
	bool isWhiteKing = movingPiece->isWhite();
	// Simulate the move on the temporary board
	if (tempBoard.canMove(src, dst))
	{
		movingPiece->move(dst); // Update the piece's position
		tempBoard.getSquare(dst).setPiece(movingPiece);
		tempBoard.getSquare(src).setPiece(nullptr);
		// Check if the king of the moving piece's color is in check after the move
		if (tempBoard.isKingInCheck(isWhiteKing))
		{
			
			std::cout << "Move would expose king to check!" << std::endl;
		}

		return tempBoard.isKingInCheck(isWhiteKing);
	}
	else
	{
		return false; // Invalid move, so it doesn't expose the king
	}
	
}

bool Board::canPonMove(const Position& src, const Position& dst) const
{
	Piece* srcPiece = this->getSquare(src).getPiece();
	Piece* dstPiece = this->getSquare(dst).getPiece();
	Pon* pon = (Pon*)(srcPiece);//converting the base piece to a pon specificly
	if (!isPositionValid(src) || !isPositionValid(dst))
	{
		return false;
	}
	if (!srcPiece)
	{
		return false; // No piece at source
	}
	if (dstPiece)
	{
		if (srcPiece->isWhite() == dstPiece->isWhite())
		{
			return false;
		}
	}
	// Check if the path is clear
	if (!this->isPathClear(src, dst))
	{
		return false;
	}
	if (src.getCol() == dst.getCol() && !this->isSquareEmpty(dst))
	{//if there is a piece at the destination squere the pon cant move even if it is an enemy piece
		return false;
	}
	if (isTherePieceInDiagonal(src))
	{		
		pon->setPieceInDiagonal(true);
	}
	else
	{
		pon->setPieceInDiagonal(false);
	}
	return pon->canMove(dst);
	


}

bool Board::isTherePieceInDiagonal(const Position& pos) const
{
	int row = pos.getRow();
	int col = pos.getCol();
	return this->_squares[row + 1][col + 1].IsOccupied() || this->_squares[row - 1][col + 1].IsOccupied() || this->_squares[row + 1][col - 1].IsOccupied() || this->_squares[row - 1][col - 1].IsOccupied();
}

bool Board::isKingInCheck(bool isWhiteKing) const
{
	Position kingPos;
	bool foundKing = false;
	// Find the king's position
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			Piece* piece = _squares[row][col].getPiece();
			if (piece && (piece->getType() == "K" || piece->getType() == "k") && piece->isWhite() == isWhiteKing)
			{
				kingPos = Position(piece->getPosition());// King found
				foundKing = true;
				break;
			}
		}
		if (foundKing) 
		{
			break; // King found, exit the loop
		}
	}
	if (!foundKing)
	{
		return false; // King not found on the board
	}
	// Check if the king's position can be attacked by any opponent piece
	return this->canSquereBeAttacked(kingPos, !isWhiteKing);
}

//int main()
//{
//	Board board = Board();
//
//	board.move(Position(1, 0), Position(2, 0));
//	std::cout << board.getBoardRepresentation() << std::endl;
//	return 0;
//}