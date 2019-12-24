#pragma once
#include <iostream>//std::cout
#include <vector>//std::vector
#include <string>//std::stoi std::string
#include <sstream>//std::stringstream

//This class stores and manipulates data from an encoded string to construct and display a game board
class Board
{
private:
	
	unsigned int dimension;

	std::vector<int> shipVector;
	std::vector<int> rowVector;
	std::vector<int> colVector;
	std::vector<int> dataVector;
	std::vector<std::vector<int>> gameBoard;

	std::vector<int> splitToIntByComma(std::string);
	std::vector<std::vector<int>> packageBoard();

public:
	//Assigns values for later algorithms and holds a copy of the encoded string to pass around
	Board(std::string, std::string, std::string, std::string, std::string);

	//Prints a constructed puzzle board to console
	std::string printBoard(std::vector<std::vector<int>>);
	std::vector<std::vector<int>> getBoard();
};
