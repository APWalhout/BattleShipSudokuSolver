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

/*
 * Assembles and prints a visualization of the puzzle board to console
 * boardDataIndex is the starting point (ahead of qualifier chars) for the data to populate the board with in the encoded string
 * stringSize is the length of the encoded string: dimension^2 board tiles plus the starting qualifier chars represented by boardDataIndex's starting value
 * The main looping algorithm performs in linear time, the alg can handle enormous board sizes (positive size will never be a limitation) 
 * NOTE: the game cannot use boards smaller than 4x4 and this alg cannot calculate board sizes smaller than 3x3
 */
void Puzzle::printBoard()
{
	unsigned int boardDataIndex = 1 + maxShipSize + (dimension * 2) + 1;
	const unsigned int stringSize = boardDataIndex + (dimension * dimension);

	/*
	 * Generates the board visualization
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