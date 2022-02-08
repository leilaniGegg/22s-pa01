#include <iostream>
#include "porter2_stemmer/porter2_stemmer.cpp"
#include "DSString.h"
#include "FileManager.h"
#include "TrainingData.h"
#include <vector>
#include <iomanip>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

using namespace std;

int main(int argc, char* const argv[]) {
    if(argc == 1){
        return Catch::Session().run();
    }
    else {
        FileManager x;
        TrainingData y;
        y.retrieveTS(x.readFile(argv[0]));
        y.calculateWF();
        y.displayWF();
        /*DSString to_stem = "working";
        DSString orig = to_stem;
        using Porter2Stemmer::trim;
        trim(to_stem.c_str());
        using Porter2Stemmer::stem;
        stem(to_stem.c_str());
        cout << "to stem:  " << orig    << std::endl;
        cout << "stemmed:  " << to_stem << std::endl; */
    }

    return 0;
}