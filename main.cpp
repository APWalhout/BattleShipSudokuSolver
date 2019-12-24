#include <iostream>
#include <pugixml.hpp>
#include <pugiconfig.hpp>
#include "Board.h"

int main()
{
	//set up and load settings xml doc
	pugi::xml_document testsXML;
	pugi::xml_parse_result testsResult = testsXML.load_file("../BattleShipSudokuSolver/include/Tests.xml");

	//verification tests
	if (testsResult)
	{
		std::cout << "File found\n";
	}
	else
		std::cout << "File not found\n";

	if (testsXML.empty())
		std::cout << "File is empty\n";
	else
		std::cout << "File is not empty\n";

	//test board A
	const std::string dimensionTest = testsXML.first_element_by_path("tests/samples/boardA/dimension").child_value();
	const std::string shipSizeTest = testsXML.first_element_by_path("tests/samples/boardA/shipList").child_value();
	const std::string rowTest = testsXML.first_element_by_path("tests/samples/boardA/rowNumbers").child_value();
	const std::string colTest = testsXML.first_element_by_path("tests/samples/boardA/colNumbers").child_value();
	const std::string dataTest = testsXML.first_element_by_path("tests/samples/boardA/boardData").child_value();

	std::cout << "test of the wholistic method: \n";
	Board wholeTest(dimensionTest, shipSizeTest, rowTest, colTest, dataTest);
	std::cout << wholeTest.printBoard(wholeTest.getBoard());

	return 1;
}