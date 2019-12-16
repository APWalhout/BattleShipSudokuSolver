#include "Board.h"

Board::Board(std::string codeStr)
{
	stringLength = codeStr.length();
	code = codeStr;

	//-'0' is for conversion from ASCII to numerical values
	dimension = code[0] - '0'; 
	maxShipSize = code[1] - '0';
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