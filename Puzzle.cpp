#include "Puzzle.h"

Puzzle::Puzzle(std::string codeStr)
{
	unsigned int n = codeStr.length();
	code = new char[n + 1];//needs to be deleted with deleteMem after use by printboard
	strcpy_s(code, n+1, codeStr.c_str());

	dimension = code[0] - '0';
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
	//optional stat visualization
	std::cout << "Dimensions: " << dimension << "x" << dimension << std::endl;
	std::cout << "Max Ship Size: " << maxShipSize << std::endl;

	unsigned int x = 1 + maxShipSize + (dimension * 2) + 1;//starting point for filling the board, skips the 'iterator' x ahead of the qualifier characters in the encoding
	unsigned int size = x + (dimension * dimension);//size of the encoded string dim^2 board tiles plus the starting qualifier characters of x
	//loop to fill the board
	for (x; x < size+1; ++x)
	{
		if (!((x - (2+maxShipSize)) % dimension))//if the iterator is pointing at the last char in a dimension, start the next line of the board
		{
			if ((x-(2+maxShipSize)) / dimension > 2)
			{
				//std::cout << code[((x - (2+maxShipSize)) / dimension) + dimension];//adds the appropriate column number
				std::cout << code[(((x - (2 + maxShipSize)) / dimension) + dimension) + 2 + maxShipSize - 3];
			}
			std::cout << "\n";//add the column number here, does the if or the while add it?
		}
		if (x < size)
		{
			std::cout << "[" << code[x] << "] ";
		}
	}

	int y = 2+maxShipSize;//what is this?

	while (y < ((2+maxShipSize)+dimension))//what does this do, why? adds row numbers? why use y and not dim = code[0]?
	{
		std::cout << " " << code[y] << "  ";
		++y;
	}

	std::cout << "\n\n";
}
/*
9 % 3 = 0, 3 is mindim

11 % 4 = 3

13 % 5 = 3

Column index is 2+max+dim??? needs verification
maxShipSize holds data for the alg, but is also a buffer unit.
there are extra characters in the encoding depending upon the maxShipSize 
so it must be used to compute the location of the 'iterator'
*/
