#include <iostream>
#include <pugixml.hpp>
#include <pugiconfig.hpp>
#include <array>
#include "Puzzle.h"

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

	//grab the first test's structure string
	std::string testAStr = testsXML.first_element_by_path("tests/trivial/a").child_value();
	std::string testBStr = testsXML.first_element_by_path("tests/trivial/b").child_value();
	std::string testCStr = testsXML.first_element_by_path("tests/trivial/c").child_value();
	std::string testDStr = testsXML.first_element_by_path("tests/trivial/d").child_value();
	std::string testEStr = testsXML.first_element_by_path("tests/trivial/e").child_value();
	std::string testFStr = testsXML.first_element_by_path("tests/trivial/f").child_value();

	//test clusters
	std::cout << "\n testAStr: " << testAStr << std::endl;
	Puzzle testA(testAStr);
	testA.printBoard();

	std::cout << "\n testBStr: " << testBStr << std::endl;
	Puzzle testB(testBStr);
	testB.printBoard();

	std::cout << "\n testCStr: " << testCStr << std::endl;
	Puzzle testC(testCStr);
	testC.printBoard();

	std::cout << "\n testDStr: " << testDStr << std::endl;
	Puzzle testD(testDStr);
	testD.printBoard();

	std::cout << "\n testEStr: " << testEStr << std::endl;
	Puzzle testE(testEStr);
	testE.printBoard();

	std::cout << "\n testFStr: " << testFStr << std::endl;
	Puzzle testF(testFStr);
	testF.printBoard();

	return 0;
}