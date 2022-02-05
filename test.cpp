//
// Created by leila on 2/3/2022.
//
#include "catch.hpp"
#include "DSString.h"

TEST_CASE("DSString class", "[string]"){

    DSString list[3];
    list[0] = DSString("potato");
    list[1] = DSString("stew");
    list[2] = DSString("");
    SECTION("Comparison Operators" ) {
        REQUIRE(!(list[0] > list[1]));
        REQUIRE((list[0] == "potato"));
        REQUIRE((list[2] == ""));

    }
}

