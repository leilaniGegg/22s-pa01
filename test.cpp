//
// Created by leila on 2/3/2022.
//
#include "catch.hpp"
#include "DSString.h"

TEST_CASE("DSString class", "[string]"){

    DSString list[8];
    list[0] = DSString("potato");
    list[1] = DSString("lilyPad");
    list[2] = DSString("wild west");
    list[3] = DSString("");
    list[4] = DSString("\n");
    list[5] = DSString("A CHILD");
    list[6] = DSString("a child");
    list[7] = DSString("!!!!");


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
        REQUIRE((list[3].getLength() == NULL));
        REQUIRE((list[7].getLength() == 4));
    }

    SECTION("Substring Functions"){
        //REQUIRE((list[1].substring(0,4) == "ilyP"));
    }
}