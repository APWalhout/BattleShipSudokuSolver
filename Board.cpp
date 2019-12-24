#include "Board.h"

Board::Board(std::string codeStr)
{
	stringLength = codeStr.length();
	code = codeStr;

	//-'0' is for conversion from ASCII to numerical values, importing and using a function is more work than would be efficient for this trivial use
	dimension = code[0] - '0';
	maxShipSize = code[1] - '0';
}

Board::Board(std::string dimensionString, std::string shipList, std::string rowHints, std::string colHints, std::string dataString)
{
	//need to detect errors before constructor
	std::cout << "\nstarted wholistic constructor\n";
	dimension = std::stoi(dimensionString);
	std::cout << "\nfinished dimension construct\n";
	shipVector = splitToIntByComma(shipList);
	std::cout << "\nfinished shipVector construct\n";
	rowVector = splitToIntByComma(rowHints);
	std::cout << "\nfinished rowVector construct\n";
	colVector = splitToIntByComma(colHints);
	std::cout << "\nfinished colVector construct\n";
	dataVector = splitToIntByComma(dataString);
	std::cout << "\nfinished dataVector construct\n";
	gameBoard = packageBoard();
	std::cout << "\nfinished gameBoard package\n";
	std::cout << "\ntesting middle character\n";
	std::cout << gameBoard[2][1];
	std::cout << "\nstarting print\n";
	std::cout << printBoard(gameBoard);
	std::cout << "\nfinished print\n";
	std::cout << "\nassembling int string test\n";
	std::string testSTR = "";
	testSTR += "test 5: ";
	testSTR += 5;
	std::cout << testSTR;
	std::cout << "\nabove is test for 5\n";
}

std::string Board::printBoard(std::vector<std::vector<int>> boardVector)
{
	std::string boardString = "";
	std::stringstream intToString;
	//here might be able to print in a hash as well?
	//a for loop that's the reverse of the data package, and at the marker points it pre/post pushes the column numbers to the string
	for (int i = 0; i < dataVector.size(); ++i)
	{
		if (boardVector[(i / dimension)][i % dimension] == -1)
		{
			intToString << " ";
		}
		else
			intToString << boardVector[(i / dimension)][i % dimension];
		//gonna have to test this, do strings += ints work as expected????????????????????????????????????????????????????
		boardString += "[";
		boardString += intToString.str();
		boardString += "] ";

		intToString.str(std::string());

		if ((i % dimension) == (dimension - 1))
		{
			intToString << boardVector[(i / dimension)][dimension];
			boardString += intToString.str();
			boardString += "\n";
			intToString.str(std::string());
		}
	}
	//then just ends with a new line push for the row numbers
	for (int i = 0; i < dimension; ++i)
	{
		intToString << boardVector[dimension][i];
		boardString += " ";
		boardString += intToString.str();
		boardString += "  ";
		intToString.str(std::string());
	}
	return boardString;
}

/*
 * Assembles and prints a visualization of the puzzle board to console
 * boardDataIndex is the starting point (ahead of qualifier chars) for the data to populate the board with in the encoded string
 * The main looping algorithm performs in linear time, the alg can handle enormous board sizes (positive size will never be a limitation) 
 * NOTE: the game cannot use boards smaller than 4x4 and this alg cannot calculate board sizes smaller than 3x3
 */
bool Board::printBoard()
{
	unsigned int boardDataIndex = maxShipSize + (dimension * 2) + 2;

	//error catching
	if (dimension < 3) { std::cout << "Exception thrown: dimension smaller than 3 \n"; return 0; }
	if (maxShipSize < 1 || maxShipSize > dimension) { std::cout << "Exception thrown: maxShipSize doesn't fit board \n"; return 0; }
	if (stringLength < dimension) { std::cout << "Exception thrown: dimension greater than data \n"; return 0; }
	if (((dimension * dimension) + boardDataIndex) < stringLength) { std::cout << "Exception thrown: board smaller than data \n"; return 0; }

	/*
	 * Generates the board visualization
	 * Terminates upon reaching the end of the encoded string
	 * This FOR just prints every data entry, formatted. The majority of work is in appropriate line wrapping
	 */
	for (boardDataIndex; boardDataIndex < stringLength + 1; ++boardDataIndex)
	{
		/*
		 * This whole IF block just handles recognizing when to line wrap and print column display data
		 * If boardDataIndex is pointing at the first char in the next row, print the row number and start the next line of the board
		 */
		if (!((boardDataIndex - (2 + maxShipSize)) % dimension))
		{   
			//makes sure boardDataIndex isn't on the first char of the first row, only when on the first char of subsequent rows should the column number print
			if ((boardDataIndex - (2 + maxShipSize)) / dimension > 2)
			{
				//navigates to the index of the appropriate col number and prints it
				std::cout << code[(((boardDataIndex - (2 + maxShipSize)) / dimension) + dimension) + 2 + maxShipSize - 3];
			}
			//wrap to the next line of the board, executes before the first row is printed as well
			std::cout << "\n";
		}
		
		if (boardDataIndex < stringLength)
		{
			std::cout << "[" << code[boardDataIndex] << "] ";
		}
	}

	/* 
	 * Prints the row numbers
	 * rowIndex points to the first row number in the encoded string
	 * Terminates upon reaching the location of col numbers in encoded string
	 */
	for (unsigned int rowIndex = 2 + maxShipSize; rowIndex < ((2 + maxShipSize) + dimension); ++rowIndex)
	{
		std::cout << " " << code[rowIndex] << "  ";
	}

	std::cout << "\n\n";
	return 1;
}

/*
 * Simple refactor of printBoard() that returns the board as a string rather than a live build to the console
 * boardStr is the string that the alg builds the board into for return
 * This can be used to pass the board to a window for simple display
 * This function is otherwise identical to printBoard() and exists as an exploration on how to package data
 */
std::string Board::printBoardString()
{
	std::string boardStr = "";
	unsigned int boardDataIndex = maxShipSize + (dimension * 2) + 2;

	if (dimension < 3) { boardStr += "Exception thrown: dimension smaller than 3 \n"; return boardStr; }
	if (maxShipSize < 1 || maxShipSize > dimension) { boardStr += "Exception thrown: maxShipSize doesn't fit board \n"; return boardStr; }
	if (stringLength < dimension) { boardStr += "Exception thrown: dimension greater than data \n"; return boardStr; }
	if (((dimension * dimension) + boardDataIndex) < stringLength) { boardStr += "Exception thrown: board smaller than data \n"; return boardStr; }

	for (boardDataIndex; boardDataIndex < stringLength + 1; ++boardDataIndex)
	{
		if (!((boardDataIndex - (2 + maxShipSize)) % dimension))
		{
			if ((boardDataIndex - (2 + maxShipSize)) / dimension > 2)
			{
				boardStr += code[(((boardDataIndex - (2 + maxShipSize)) / dimension) + dimension) + 2 + maxShipSize - 3];
			}
			boardStr += "\n";
		}

		if (boardDataIndex < stringLength)
		{
			boardStr += "[";
			boardStr += code[boardDataIndex];
			boardStr += "] ";
		}
	}

	for (unsigned int rowIndex = 2 + maxShipSize; rowIndex < ((2 + maxShipSize) + dimension); ++rowIndex)
	{
		boardStr += " ";
		boardStr += code[rowIndex];
		boardStr += "  ";
	}

	boardStr += "\n\n";
	return boardStr;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TIME TO IMPLEMENT PRINT WITH SEPARATED DATA!!!!!!!!!!!!!!!!!!!!!!
std::vector<std::vector<int>> Board::packageBoard()
{
	//!!!!!!!!!!!! NEED ERROR DETECTION IN CASE DIMENSION IS NOT A NUMBER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//MAYBE DETECT IN CONSTRUCTOR, NO, DO DETECT IN CONSTRUCTOR CAUSE IT CAN SCREW UP THE STOI METHODS

	//initialize a 2d array using dimension +1
	std::vector<std::vector<int>> boardVector(dimension + 1, std::vector<int>(dimension + 1, 0));// the ,0 was added to populate the 2d array with 0 and possibly fix the reference error as referencing an empy array might have caused the issue
	std::cout << "\nbuilt 2d boardVector\n";
	//int (*gameBoard)[dimension] = new int[dimension][dimension];//T (*ptr)[M] = new T[N][M];
	//insert the row and column vectors
	//row inserts in the last row over n columns
	//col inserts in the last column over n rows
	std::cout << "\nabout to start adding row and col\n";
	for (int i = 0; i < dimension; ++i)
	{
		boardVector[dimension][i] = rowVector[i];
		boardVector[i][dimension] = colVector[i];
	}
	std::cout << "\nfinished adding row and col\n";
	//fill the dimension x dimension area with data
	//this is where i might be able to hash
	//i know it's going to be squaer so i can use modular for the colun
	std::cout << "\nabout to start populating data\n";
	for (int i = 0; i < dataVector.size(); ++i)
	{
		//wait, dimension is going to be the square root of the data length, what do i need sqrt for?
		boardVector[(i / dimension)][i % dimension] = dataVector[i];
	}
	std::cout << "\nfinished populating data\n";

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