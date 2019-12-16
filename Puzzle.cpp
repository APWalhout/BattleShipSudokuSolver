#include "Puzzle.h"

Puzzle::Puzzle(std::string codeStr)
{
	const unsigned int stringLength = codeStr.length();
	code = new char[stringLength + 1];
	strcpy_s(code, stringLength + 1, codeStr.c_str());

	dimension = code[0] - '0';
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
	unsigned int boardDataIndex = maxShipSize + (dimension * 2) + 2;
	const unsigned int stringSize = boardDataIndex + (dimension * dimension);

	/*
	 * Generates the board visualization
	 * Terminates upon reaching the end of the encoded string
	 * This FOR just prints every data entry, formatted. The majority of work is in appropriate line wrapping
	 */
	for (boardDataIndex; boardDataIndex < stringSize + 1; ++boardDataIndex)
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
		
		if (boardDataIndex < stringSize)
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
}