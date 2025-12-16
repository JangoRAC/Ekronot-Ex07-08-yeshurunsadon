#include "Position.h"

Position::Position()
{
	this->_col = 0;
	this->_row = 0;
}

Position::Position(int row, int col)
{
	this->_col = col;
	this->_row = row;
}

Position::~Position()
{

}

const int Position::getRow() const
{
	return this->_col;
}

const int Position::getCol() const
{
	return this->_col;
}
