#include "Puzzle.h"

Puzzle::Puzzle(std::string codeStr)
{
	unsigned int n = codeStr.length();
	code = new char[n + 1];//needs to be deleted with deleteMem after use by printBoard
	strcpy_s(code, n+1, codeStr.c_str());//make sure you actually need to copy it into a new object

	dimension = code[0] - '0';//see if a string can be referenced this way
	maxShipSize = code[1] - '0';

}

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
	//debug stat visualization
	std::cout << "Dimensions: " << dimension << "x" << dimension << std::endl;
	std::cout << "Max Ship Size: " << maxShipSize << std::endl;

	//make sure x is a useful name and check your const
	unsigned int boardDataIndex = 1 + maxShipSize + (dimension * 2) + 1;//starting point for filling the board: skips the 'iterator' x ahead of the qualifier characters in the encoding
	unsigned int size = boardDataIndex + (dimension * dimension);//size of the encoded string: dim^2 board tiles plus the starting qualifier characters of x
	//loop to fill the board
	//why not use a while loop?
	for (boardDataIndex; boardDataIndex< size+1; ++boardDataIndex)
	{
		if (!((boardDataIndex - (2+maxShipSize)) % dimension))//if the iterator is pointing at the first char in the next row, print the row number and start the next line of the board
		{
			if ((boardDataIndex-(2+maxShipSize)) / dimension > 2)//makes sure the iterator isn't on the first char of the first row, only when on the first char of higher rows should the column number print
			{
				std::cout << code[(((boardDataIndex - (2 + maxShipSize)) / dimension) + dimension) + 2 + maxShipSize - 3];//navigates to the appropriate column number
			}
			std::cout << "\n";//wrap to the next line of the board, executes before the first row is printed as well
		}
		if (boardDataIndex < size)//if x still points to board entries, add that entry to the display
		{
			std::cout << "[" << code[boardDataIndex] << "] ";
		}
	}

	int rowIndex = 2+maxShipSize;//navigates rowIndex as an 'iterator' to point to the first row number

	//why use a while loop? while is for ambiguity, for is for defined exact known termination
	/*while (rowIndex < ((2+maxShipSize)+dimension))//while row numbers still haven't been printed, print them
	{
		std::cout << " " << code[rowIndex] << "  ";
		++rowIndex;
	}*/
	for (int rowIndex = 2 + maxShipSize; rowIndex < ((2 + maxShipSize) + dimension); ++rowIndex)
	{
		std::cout << " " << code[rowIndex] << "  ";
	}

	std::cout << "\n\n";
}
