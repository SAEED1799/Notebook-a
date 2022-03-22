#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________
         
         
TEST_CASE("test for any ware things"){
    Notebook test;
	CHECK(test.read(0, 0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(test.read(1, 1, 1, Direction::Vertical, 1) == string("_"));
    CHECK(test.read(0, 0, 0, Direction::Horizontal, 10) == string("__________"));
    CHECK(test.read(1, 1, 1, Direction::Vertical, 10) == string("__________"));
    CHECK(test.read(50, 15, 10, Direction::Horizontal, 1) == string("_"));
    CHECK(test.read(40, 45, 11, Direction::Horizontal, 11) == string("___________"));
    CHECK(test.read(60, 65, 7, Direction::Vertical,11) == string("___________"));
    CHECK(test.read(45, 43, 5, Direction::Horizontal, 1) == string("_"));
    CHECK(test.read(78, 22, 4, Direction::Horizontal, 0) == string(""));
    CHECK(test.read(13, 23, 3, Direction::Horizontal, 2) == string("__"));
    test.write(100,100,50,Direction::Horizontal,"abcde");
    CHECK(test.read(100, 100, 50, Direction::Horizontal, 8) == string("abcde___"));
    test.erase(100, 100, 50, Direction::Horizontal, 2);
    CHECK(test.read(100, 100, 50, Direction::Horizontal, 8) == string("~~cde___"));
    test.write(15,12,40,Direction::Horizontal,"saeedesawi");
    CHECK(test.read(15, 12, 40, Direction::Horizontal, 10) == string("saeedesawi"));
    test.erase(15, 12, 40, Direction::Horizontal, 5);
    CHECK(test.read(15, 12, 40, Direction::Horizontal, 10) == string("~~~~~esawi"));
    }

 
TEST_CASE("test write and read-v"){
	Notebook test;
	test.write(0,0,0,Direction::Vertical,"hello");//6
	test.write(1,1,2,Direction::Vertical,"my");//2
	test.write(2,2,4,Direction::Vertical,"name");//4
	test.write(3,3,6,Direction::Vertical,"is");//2
    test.erase(3, 3, 6, Direction::Horizontal, 2);
	test.write(4,4,8,Direction::Vertical,"saeed");//5
	test.write(5,5,10,Direction::Vertical,"how");//3
	test.write(6,6,12,Direction::Vertical,"are");//3
	test.write(7,7,14,Direction::Vertical,"you");//3
	test.write(8,8,16,Direction::Vertical,"today");//5
	test.write(9,9,18,Direction::Vertical,"?");//1

	CHECK(test.read(0,0,0,Direction::Vertical,5)=="hello");//6
	CHECK(test.read(1,1,2,Direction::Vertical,2)=="my");//2
	CHECK(test.read(2,2,4,Direction::Vertical,4)=="name");//4
	CHECK(test.read(3,3,6,Direction::Vertical,2)=="~s");//2
	CHECK(test.read(4,4,8,Direction::Vertical,5)=="saeed");//5
	CHECK(test.read(5,5,10,Direction::Vertical,3)=="how");//3
	CHECK(test.read(6,6,12,Direction::Vertical,3)=="are");//3
	CHECK(test.read(7,7,14,Direction::Vertical,3)=="you");//3
	CHECK(test.read(8,8,16,Direction::Vertical,5)=="today");//5
	CHECK(test.read(9,9,18,Direction::Vertical,1)=="?");//1

}

   