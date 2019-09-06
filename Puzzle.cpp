#include "Puzzle.h"

Puzzle::Puzzle(std::string codeStr)
{
	//parse through code and allocate data to the variables of puzzle
	//possibly initializing here would prevent needing new memory
}
/*
Puzzle::Puzzle(char code[])
{
	dimension = code[0];
	maxShipSize = code[1];

}*/

void Puzzle::deleteMem()
{
	
}

void Puzzle::printBoard()
{
	std::cout << "Dimensions: " << dimension << "x" << dimension << std::endl;
	std::cout << "Max Ship Size: " << maxShipSize << std::endl;

	int x = 1 + maxShipSize + (dimension * 2) + 1;//starting point for filling the board
	int size = x + (dimension * dimension);
	//loop to fill the board
	for (x; x < size; ++x)
	{
		if (!((x - (2+maxShipSize)) % dimension))
		{
			std::cout << "\n";
		}
		std::cout << "[" << code[x] << "] ";
	}
}
