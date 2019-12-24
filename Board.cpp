#include "Board.h"
/*
 * Assigns object's attribute values with helper methods and concludes by "building" the board from given parameters
 */
Board::Board(std::string dimensionString, std::string shipList, std::string rowHints, std::string colHints, std::string dataString)
{
	dimension = std::stoi(dimensionString);
	shipVector = splitToIntByComma(shipList);
	rowVector = splitToIntByComma(rowHints);
	colVector = splitToIntByComma(colHints);
	dataVector = splitToIntByComma(dataString);

	gameBoard = packageBoard();
}

/*
 * Returns a formatted string version of the game board for visualization and testing
 * boardString is built up and returned
 * intToString is used to convert integer values to appropriate string characters
 * Helper method for constructor that accesses the 2d board in linear time
 */
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

/*
 * Constructs the actual game board object using parameters passed to the constructor.
 * boardVector is the game board returned to the constructor.
 * Helper method for constructor that populates the 2d vector in linear time.
 */
std::vector<std::vector<int>> Board::packageBoard()
{
	std::vector<std::vector<int>> boardVector(dimension + 1, std::vector<int>(dimension + 1, 0));// the ,0 was added to populate the 2d array with 0 and possibly fix the reference error as referencing an empy array might have caused the issue

	//Insert the row and column vectors
	for (int edgeIndex = 0; edgeIndex < dimension; ++edgeIndex)
	{
		boardVector[dimension][edgeIndex] = rowVector[edgeIndex];
		boardVector[edgeIndex][dimension] = colVector[edgeIndex];
	}
	
	//Since the board's data is always a square area, allows linear wrapping solution
	for (int dataIndex = 0; dataIndex < dataVector.size(); ++dataIndex)
	{
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