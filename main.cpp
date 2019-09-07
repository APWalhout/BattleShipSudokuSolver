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
	if (testsResult)
	{
		std::cout << "File found\n";
	}
	else
		std::cout << "File not found\n";
	if (!testsResult)
	{
		std::cout << "File also not found\n";
	}

	if (testsXML.empty())
		std::cout << "file is empty\n";
	else
		std::cout << "file is NOT empty\n";

	//std::cout << "setRes: " << setRes << std::endl;
	std::cout << "Child_value(): " << testsXML.child_value() << std::endl;
	std::cout << "Child 'trivial': " << testsXML.child("trivial") << std::endl;
	std::cout << "Child 'trivial' name: " << testsXML.child("trivial").name() << std::endl;
	std::cout << "Child 'trivial' value: " << testsXML.child("trivial").value() << std::endl;
	std::cout << "Doc element: " << testsXML.document_element() << std::endl;
	std::cout << "Doc element value: " << testsXML.document_element().value() << std::endl;
	//returns "settings"
	std::cout << "Doc element name: " << testsXML.document_element().name() << std::endl;
	//returns a non NULL address
	std::cout << "Doc element last attr: " << testsXML.document_element().last_attribute() << std::endl;
	std::cout << "Doc element attr 'description': " << testsXML.document_element().attribute("description") << std::endl;
	std::cout << "Doc element attr 'description' as string: " << testsXML.document_element().attribute("description").as_string() << std::endl;

	std::cout << "Doc element child 'trivial' child 'a': " << testsXML.document_element().child("trivial").child("a") << std::endl;
	std::cout << "Doc element by path tests/trivial/a attr description as string: " << testsXML.first_element_by_path("tests/trivial/a").attribute("description").as_string() << std::endl;
	std::cout << std::endl;
	std::cout << "Doc element by path tests/trivial/a child value: " << testsXML.first_element_by_path("tests/trivial/a").child_value() << std::endl;

	//grab the first test's structure string
	testsXML.first_element_by_path("tests/trivial/a").child_value();

	//need to make a struct that you pass the string into and it constructs a puzzle with needed attributes.
	//arrays for row and column codes
	//dimensions
	//number and size of ships
	//place existing ships and water where they belong in a multi-dim array

	Puzzle testA(testsXML.first_element_by_path("tests/trivial/a").child_value());
	testA.printBoard();
	testA.deleteMem();

	return 0;
}