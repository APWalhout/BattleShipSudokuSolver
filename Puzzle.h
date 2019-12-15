#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>

//This class stores and manipulates data from an encoded line to construct and display a game board
class Puzzle
{
private:
	char* code;

	unsigned int dimension;
	unsigned int maxShipSize;

public:
	Puzzle(std::string);

	//Garbage collection, call it after finishing using a Puzzle object
	void deleteMem();
	//Prints a constructed puzzle board to console
	void printBoard();
};
#endif
