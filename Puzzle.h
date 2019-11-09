#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>

//this class stores and manipulates data from a encoded line to produce a visualization of a game board
class Puzzle
{
private:
	char* code;

	unsigned int dimension;
	unsigned int maxShipSize;

public:
	//constructor that assembles the necessary data for printing alg
	Puzzle(std::string);

	//manual garbage collection of new data from contstructor
	void deleteMem();
	//displays a board visualization in linear time
	void printBoard();
};
#endif
