#include "Board.h"

Board::Board(std::string codeStr)
{
	stringLength = codeStr.length();
	code = codeStr;

	//-'0' is for conversion from ASCII to numerical values, importing and using a function is more work than would be efficient for this trivial use
	dimension = code[0] - '0';
	maxShipSize = code[1] - '0';
}

Board::Board(const unsigned int dimension, std::string shipList, std::string rowHints, std::string colHints, std::string dataString)
{
	this->dimension = dimension;
	shipVector;

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