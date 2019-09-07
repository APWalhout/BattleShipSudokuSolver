#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
//need to make a struct that you pass the string into and it constructs a puzzle with needed attributes.
//arrays for row and column codes
//dimensions
//number and size of ships
//place existing ships and water where they belong in a multi-dim array
class Puzzle
{
public:
	Puzzle(std::string);
	//Puzzle(char[]);

	//char code[];'
	char* code;
	unsigned int dimension;
	//unsigned int row[];
	//unsigned int column[];
	unsigned int maxShipSize;
	//std::string numberOfShips;
	//unsigned int board[][];

	void deleteMem();
	void printBoard();
};
#endif
