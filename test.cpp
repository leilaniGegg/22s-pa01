//
// Created by leila on 2/3/2022.
//
#include "catch.hpp"
#include "DSString.h"

TEST_CASE("DSString class", "[string]"){

    DSString list[7];
    list[0] = DSString("potato");
    list[1] = DSString("potato");
    list[2] = DSString("wild west");
    list[3] = DSString("");
    list[4] = DSString("\n");
    list[5] = DSString("A CHILD");
    list[6] = DSString("a child");


    SECTION("Comparison Operators" ) {
        REQUIRE(!(list[0] > list[1]));
        REQUIRE((list[6] < list[2]));
        REQUIRE((list[0] == list[1]));
        REQUIRE((list[5] == list[6]));
        REQUIRE((list[3] == ""));
    }
    SECTION("Adding Operators"){

    }
}