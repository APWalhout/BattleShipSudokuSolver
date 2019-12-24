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

	//grab the test's encoded strings
	/*const std::string testAStr = testsXML.first_element_by_path("tests/trivial/a").child_value();
	const std::string testBStr = testsXML.first_element_by_path("tests/trivial/b").child_value();
	const std::string testCStr = testsXML.first_element_by_path("tests/trivial/c").child_value();
	const std::string testDStr = testsXML.first_element_by_path("tests/trivial/d").child_value();
	const std::string testEStr = testsXML.first_element_by_path("tests/trivial/e").child_value();
	const std::string testFStr = testsXML.first_element_by_path("tests/trivial/f").child_value();
	*/

	//grab the fail's encoded strings
	/*const std::string failGStr = testsXML.first_element_by_path("tests/fails/g").child_value();
	const std::string failHStr = testsXML.first_element_by_path("tests/fails/h").child_value();
	const std::string failIStr = testsXML.first_element_by_path("tests/fails/i").child_value();
	const std::string failJStr = testsXML.first_element_by_path("tests/fails/j").child_value();
	const std::string failKStr = testsXML.first_element_by_path("tests/fails/k").child_value();
	*/

	//test board A
	const std::string dimensionTest = testsXML.first_element_by_path("tests/samples/boardA/dimension").child_value();
	const std::string shipSizeTest = testsXML.first_element_by_path("tests/samples/boardA/shipList").child_value();
	const std::string rowTest = testsXML.first_element_by_path("tests/samples/boardA/rowNumbers").child_value();
	const std::string colTest = testsXML.first_element_by_path("tests/samples/boardA/colNumbers").child_value();
	const std::string dataTest = testsXML.first_element_by_path("tests/samples/boardA/boardData").child_value();

	std::cout << "test of the wholistic method: \n";
	Board wholeTest(dimensionTest, shipSizeTest, rowTest, colTest, dataTest);
	std::cout << wholeTest.printBoard(wholeTest.getBoard());

	//test clusters
	/*std::cout << "\n testAStr: " << testAStr << std::endl;
	Board testA(testAStr);
	testA.printBoard();

	std::cout << "\n testBStr: " << testBStr << std::endl;
	Board testB(testBStr);
	testB.printBoard();

	std::cout << "\n testCStr: " << testCStr << std::endl;
	Board testC(testCStr);
	testC.printBoard();

	std::cout << "\n testDStr: " << testDStr << std::endl;
	Board testD(testDStr);
	testD.printBoard();

	std::cout << "\n testEStr: " << testEStr << std::endl;
	Board testE(testEStr);
	testE.printBoard();

	std::cout << "\n testFStr: " << testFStr << std::endl;
	Board testF(testFStr);
	testF.printBoard();
	std::cout << "testing the string method: \n";
	std::cout << testF.printBoardString();

	//fail test clusters
	std::cout << "\n failGStr: " << failGStr << std::endl;
	Board failG(failGStr);
	failG.printBoard();
	std::cout << "testing string method: \n";
	std::cout << failG.printBoardString();
	
	std::cout << "\n failHStr: " << failHStr << std::endl;
	Board failH(failHStr);
	failH.printBoard();

	std::cout << "\n failIStr: " << failIStr << std::endl;
	Board failI(failIStr);
	failI.printBoard();

	std::cout << "\n failJStr: " << failJStr << std::endl;
	Board failJ(failJStr);
	failJ.printBoard();

	std::cout << "\n failKStr: " << failKStr << std::endl;
	Board failK(failKStr);
	failK.printBoard();*/

	return 1;
}