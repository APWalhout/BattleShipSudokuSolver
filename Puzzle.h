#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>

//This class stores and manipulates data from an encoded string to construct and display a game board
class Puzzle
{
private:
	std::string code;

	unsigned int dimension;
	unsigned int maxShipSize;

public:
	//Assigns values for later algorithms and holds a copy of the encoded string to pass around
	Puzzle(std::string);

	//Prints a constructed puzzle board to console
	void printBoard();
};
#endif
