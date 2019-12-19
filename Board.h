#pragma once
#include <iostream>
#include <vector>

//This class stores and manipulates data from an encoded string to construct and display a game board
class Board
{
private:
	std::string code;
	std::vector<unsigned int> shipVector;
	
	unsigned int stringLength;
	unsigned int dimension;
	unsigned int maxShipSize;

public:
	//Assigns values for later algorithms and holds a copy of the encoded string to pass around
	Board(std::string);
	Board(const unsigned int, std::string, std::string, std::string, std::string);

	//Prints a constructed puzzle board to console
	bool printBoard();
	std::string printBoardString();
};
