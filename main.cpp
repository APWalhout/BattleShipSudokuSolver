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
	const std::string dimensionTestA = testsXML.first_element_by_path("tests/samples/boardA/dimension").child_value();
	const std::string shipSizeTestA = testsXML.first_element_by_path("tests/samples/boardA/shipList").child_value();
	const std::string rowTestA = testsXML.first_element_by_path("tests/samples/boardA/rowNumbers").child_value();
	const std::string colTestA = testsXML.first_element_by_path("tests/samples/boardA/colNumbers").child_value();
	const std::string dataTestA = testsXML.first_element_by_path("tests/samples/boardA/boardData").child_value();

	try
	{
		Board testA(dimensionTestA, shipSizeTestA, rowTestA, colTestA, dataTestA);
		std::cout << testA.printBoard(testA.getBoard());
		std::cout << std::endl << std::endl;
	}
	catch (const std::invalid_argument& e) { std::cout << "\nInvalid argument to constructor.\n"; }

	//test board B
	const std::string dimensionTestB = testsXML.first_element_by_path("tests/samples/boardB/dimension").child_value();
	const std::string shipSizeTestB = testsXML.first_element_by_path("tests/samples/boardB/shipList").child_value();
	const std::string rowTestB = testsXML.first_element_by_path("tests/samples/boardB/rowNumbers").child_value();
	const std::string colTestB = testsXML.first_element_by_path("tests/samples/boardB/colNumbers").child_value();
	const std::string dataTestB = testsXML.first_element_by_path("tests/samples/boardB/boardData").child_value();

	try
	{
		Board testB(dimensionTestB, shipSizeTestB, rowTestB, colTestB, dataTestB);
		std::cout << testB.printBoard(testB.getBoard());
		std::cout << std::endl << std::endl;
	}
	catch (const std::invalid_argument& e) { std::cout << "\nInvalid argument to constructor.\n"; }

	//fail test board C
	const std::string dimensionTestC = testsXML.first_element_by_path("tests/samples/boardC/dimension").child_value();
	const std::string shipSizeTestC = testsXML.first_element_by_path("tests/samples/boardC/shipList").child_value();
	const std::string rowTestC = testsXML.first_element_by_path("tests/samples/boardC/rowNumbers").child_value();
	const std::string colTestC = testsXML.first_element_by_path("tests/samples/boardC/colNumbers").child_value();
	const std::string dataTestC = testsXML.first_element_by_path("tests/samples/boardC/boardData").child_value();

	try 
	{
		Board testC(dimensionTestC, shipSizeTestC, rowTestC, colTestC, dataTestC);
		std::cout << testC.printBoard(testC.getBoard());
		std::cout << std::endl << std::endl;
	}
	catch (const std::invalid_argument& e) { std::cout << "\nInvalid argument to constructor.\n\n"; }

	//fail test board D
	const std::string dimensionTestD = testsXML.first_element_by_path("tests/samples/boardD/dimension").child_value();
	const std::string shipSizeTestD = testsXML.first_element_by_path("tests/samples/boardD/shipList").child_value();
	const std::string rowTestD = testsXML.first_element_by_path("tests/samples/boardD/rowNumbers").child_value();
	const std::string colTestD = testsXML.first_element_by_path("tests/samples/boardD/colNumbers").child_value();
	const std::string dataTestD = testsXML.first_element_by_path("tests/samples/boardD/boardData").child_value();

	try
	{
		Board testD(dimensionTestD, shipSizeTestD, rowTestD, colTestD, dataTestD);
		std::cout << testD.printBoard(testD.getBoard());
		std::cout << std::endl << std::endl;
	}
	catch (const std::invalid_argument& e) { std::cout << "\nInvalid argument to constructor.\n"; }
	
	return 1;
}