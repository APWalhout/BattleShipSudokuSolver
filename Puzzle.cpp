#include "Puzzle.h"

Puzzle::Puzzle(std::string codeStr)
{
	//parse through code and allocate data to the variables of puzzle
	//possibly initializing here would prevent needing new memory
	//a string is a char array? might not be so complicated

	unsigned int n = codeStr.length();
	code = new char[n + 1];
	strcpy_s(code, n+1, codeStr.c_str());

	dimension = code[0] - '0';
	maxShipSize = code[1] - '0';

}
/*
Puzzle::Puzzle(char code[])
{
	dimension = code[0];
	maxShipSize = code[1];

}*/

void Puzzle::deleteMem()
{
	delete [] code;
}

void Puzzle::printBoard()
{
	std::cout << "Dimensions: " << dimension << "x" << dimension << std::endl;
	std::cout << "Max Ship Size: " << maxShipSize << std::endl;

	unsigned int x = 1 + maxShipSize + (dimension * 2) + 1;//starting point for filling the board
	unsigned int size = x + (dimension * dimension);
	//loop to fill the board
	for (x; x < size+1; ++x)
	{
		if (!((x - (2+maxShipSize)) % dimension))
		{
			if (x / dimension > 2)
			{
				std::cout << code[(x / dimension) + dimension];//adds the appropriate column number
			}
			std::cout << "\n";//add the column number here if you can
		}
		if (x < size)
		{
			std::cout << "[" << code[x] << "] ";
		}
	}

	int y = 3;

	while (y < (3+dimension))
	{
		std::cout << " " << code[y] << "  ";
		++y;
	}

	std::cout << "\n\n";
}
