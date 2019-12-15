#include "Puzzle.h"

Puzzle::Puzzle(std::string codeStr)
{
	unsigned int stringLength = codeStr.length();
	code = new char[stringLength + 1];//needs to be deleted with deleteMem after use by printBoard
	strcpy_s(code, stringLength + 1, codeStr.c_str());//make sure you actually need to copy it into a new object

	dimension = code[0] - '0';//see if a string can be referenced this way
	maxShipSize = code[1] - '0';

}

//Manual garbage collection
void Puzzle::deleteMem()
{
	delete [] code;
}

//calculates the size of the board,
//the location and count of column and row numbers
//loops through the data and displays in a linear time, extensible alg
//the board cannot be smaller than 3x3
void Puzzle::printBoard()
{
	unsigned int boardDataIndex = 1 + maxShipSize + (dimension * 2) + 1;//starting point for filling the board: skips boardDataIndex ahead of the qualifier characters in the encoding
	const unsigned int stringSize = boardDataIndex + (dimension * dimension);//size of the encoded string: dim^2 board tiles plus the starting qualifier characters of boardDataIndex

	/*
	 * Generates the board visualization
	 * boardDataIndex points to the first element of data for populating the board in the encoded string
	 * Terminates upon reaching the end of the encoded string
	 */
	for (boardDataIndex; boardDataIndex < stringSize + 1; ++boardDataIndex)
	{
		if (!((boardDataIndex - (2 + maxShipSize)) % dimension))//if boardDataIndex is pointing at the first char in the next row, print the row number and start the next line of the board
		{
			if ((boardDataIndex - (2 + maxShipSize)) / dimension > 2)//makes sure boardDataIndex isn't on the first char of the first row, only when on the first char of subsequent rows should the column number print
			{
				std::cout << code[(((boardDataIndex - (2 + maxShipSize)) / dimension) + dimension) + 2 + maxShipSize - 3];//navigates to the appropriate column number
			}
			std::cout << "\n";//wrap to the next line of the board, executes before the first row is printed as well
		}
		if (boardDataIndex < stringSize)//if boardDataIndex still points to board entries, add that entry to the display
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

	std::cout << "\n\n";//spacing accommodation for future print calls
}
