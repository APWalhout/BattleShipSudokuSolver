#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <iostream>

//This class stores and manipulates data from an encoded string to construct and display a game board
class Board
{
private:
	std::string code;

	unsigned int dimension;
	unsigned int maxShipSize;

public:
	//Assigns values for later algorithms and holds a copy of the encoded string to pass around
	Board(std::string);

	//Prints a constructed puzzle board to console
	void printBoard();
};
#endif