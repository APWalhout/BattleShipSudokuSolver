#include "Board.h"

Board::Board(std::string dimensionString, std::string shipList, std::string rowHints, std::string colHints, std::string dataString)
{
	//need to detect errors before constructor
	dimension = std::stoi(dimensionString);
	shipVector = splitToIntByComma(shipList);
	rowVector = splitToIntByComma(rowHints);
	colVector = splitToIntByComma(colHints);
	dataVector = splitToIntByComma(dataString);
	gameBoard = packageBoard();
}

std::string Board::printBoard(std::vector<std::vector<int>> boardVector)
{
	std::string boardString = "";
	std::stringstream intToString;
	
	for (int dataIndex = 0; dataIndex < dataVector.size(); ++dataIndex)
	{
		if (boardVector[(dataIndex / dimension)][dataIndex % dimension] == -1)
		{
			intToString << " ";
		}
		else
			intToString << boardVector[(dataIndex / dimension)][dataIndex % dimension];
		//gonna have to test this, do strings += ints work as expected????????????????????????????????????????????????????
		boardString += "[";
		boardString += intToString.str();
		boardString += "] ";

		intToString.str(std::string());

		if ((dataIndex % dimension) == (dimension - 1))
		{
			intToString << boardVector[(dataIndex / dimension)][dimension];
			boardString += intToString.str();
			boardString += "\n";
			intToString.str(std::string());
		}
	}
	//then just ends with a new line push for the row numbers
	for (int rowIndex = 0; rowIndex < dimension; ++rowIndex)
	{
		intToString << boardVector[dimension][rowIndex];
		boardString += " ";
		boardString += intToString.str();
		boardString += "  ";
		intToString.str(std::string());
	}
	return boardString;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TIME TO IMPLEMENT PRINT WITH SEPARATED DATA!!!!!!!!!!!!!!!!!!!!!!
std::vector<std::vector<int>> Board::packageBoard()
{
	//!!!!!!!!!!!! NEED ERROR DETECTION IN CASE DIMENSION IS NOT A NUMBER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//MAYBE DETECT IN CONSTRUCTOR, NO, DO DETECT IN CONSTRUCTOR CAUSE IT CAN SCREW UP THE STOI METHODS

	//initialize a 2d array using dimension +1
	std::vector<std::vector<int>> boardVector(dimension + 1, std::vector<int>(dimension + 1, 0));// the ,0 was added to populate the 2d array with 0 and possibly fix the reference error as referencing an empy array might have caused the issue

	//int (*gameBoard)[dimension] = new int[dimension][dimension];//T (*ptr)[M] = new T[N][M];
	//insert the row and column vectors
	//row inserts in the last row over n columns
	//col inserts in the last column over n rows
	for (int edgeIndex = 0; edgeIndex < dimension; ++edgeIndex)
	{
		boardVector[dimension][edgeIndex] = rowVector[edgeIndex];
		boardVector[edgeIndex][dimension] = colVector[edgeIndex];
	}
	
	//fill the dimension x dimension area with data
	//this is where i might be able to hash
	//i know it's going to be squaer so i can use modular for the colun
	for (int dataIndex = 0; dataIndex < dataVector.size(); ++dataIndex)
	{
		//wait, dimension is going to be the square root of the data length, what do i need sqrt for?
		boardVector[(dataIndex / dimension)][dataIndex % dimension] = dataVector[dataIndex];
	}

	return boardVector;
}

/*
 * Accepts a string and packages it into an int vector with substrings split on ','
 * returnVector is the packaged integer conversion of the given string
 * splitStream is the stream object that has helper methods for the operation
 * subStr holds the sub-string of the given string split on ','
 * Helper method for constructor.
 */
std::vector<int> Board::splitToIntByComma(std::string toSplit)
{
	std::vector<int> returnVector;
	std::stringstream splitStream(toSplit);

	while (splitStream.good())
	{
		std::string subStr;
		std::getline(splitStream, subStr, ',');
		if (subStr == " ")
		{
			returnVector.push_back(-1);
		}
		else
			returnVector.push_back(std::stoi(subStr));
	}
	return returnVector;
}

std::vector<std::vector<int>> Board::getBoard()
{
	return gameBoard;
}