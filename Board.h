#pragma once
#include <iostream>//std::cout
#include <vector>//std::vector
#include <string>//std::stoi std::string
#include <sstream>//std::stringstream

//This class stores and manipulates data from an encoded string to construct and display a game board
class Board
{
private:
	//variables
	unsigned int dimension;

	std::vector<int> shipVector;
	std::vector<int> rowVector;
	std::vector<int> colVector;
	std::vector<int> dataVector;
	std::vector<std::vector<int>> gameBoard;
	
	//helper methods
	std::vector<int> splitToIntByComma(std::string);
	std::vector<std::vector<int>> packageBoard();

public:
	Board(std::string, std::string, std::string, std::string, std::string);

	std::string printBoard(std::vector<std::vector<int>>);
	std::vector<std::vector<int>> getBoard();
};
