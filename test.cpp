//
// Created by leila on 2/3/2022.
//
#include "catch.hpp"
#include "DSString.h"

TEST_CASE("DSString class", "[string]"){

    DSString list[10];
    list[0] = DSString("potato");
    list[1] = DSString("lilyPad");
    list[2] = DSString("wild west");
    list[3] = DSString("");
    list[4] = DSString("\n");
    list[5] = DSString("A CHILD");
    list[6] = DSString("a child");
    list[7] = DSString("!!!!");
    list[8] = DSString("How much wood can a wood chuck chuck");
    list[9] = DSString("cOkE ZeRO");
    list[10] = DSString("lily");


    SECTION("Comparison Operators" ) {
        REQUIRE((list[0] > list[1]));
        REQUIRE((list[6] < list[2]));
        REQUIRE((list[5] > list[7]));
        REQUIRE((list[0] == "potato"));
        REQUIRE(!(list[5] == list[6]));
        REQUIRE((list[3] == ""));
    }
    SECTION("Adding Operators"){
        REQUIRE((list[0] + list[2] == "potatowild west"));
        REQUIRE((list[2] + list[3] == "wild west"));
        REQUIRE((list[5] + list[7] == "A CHILD!!!!"));
        REQUIRE((list[3] + list[4] == "\n"));
    }
    SECTION("Assignment Operator?"){
        REQUIRE((list[1][4] == 'P' ));
        REQUIRE((list[0][0] == 'p'));
        REQUIRE((list[2][8] == 't'));
        REQUIRE((list[5][2] == 'C'));
    }

    SECTION("Length Function"){
        REQUIRE((list[0].getLength() == 6));
        REQUIRE((list[2].getLength() == 9));
        REQUIRE((list[3].getLength() == 0));
        REQUIRE((list[7].getLength() == 4));
    }

    SECTION("Substring Functions"){
        REQUIRE(!(list[2].substring(0,4) == "west"));
        REQUIRE(!(list[8].substring(4,4) == "wood"));
        REQUIRE(!(list[6].substring(2,5) == "CHILD"));
    }
    SECTION("c_str function"){
        char* p = "potato";
        char* x = "cOkE ZeRO";
        REQUIRE((strcmp(list[0].c_str(), p) == 0));
        REQUIRE(!(strcmp(list[6].c_str(), p) == 0));
        REQUIRE((strcmp(list[9].c_str(), x) == 0));

    }
    SECTION("Parse Tweet Function"){
        vector<DSString> words = list[8].parseTweet(" ");
        REQUIRE((words.at(2) == "wood"));
        REQUIRE((words.at(4) == "a"));
        REQUIRE((words.at(6) == "chuck"));
    }

    SECTION("To Lower Function"){
        REQUIRE((list[5].toLower() == "a child"));
        REQUIRE((list[1].toLower() == "lilypad"));
        REQUIRE((list[9].toLower() == "coke zero"));
    }
}