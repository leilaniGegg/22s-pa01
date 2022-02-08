#include <iostream>
#include "porter2_stemmer/porter2_stemmer.cpp"
#include "DSString.h"
#include "FileManager.h"
#include "TrainingData.h"
#include "Tweet.h"
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
        FileManager IO;
        TrainingData training;
        training.retrieveTS(IO.readFile(argv[0]));
        training.calculateWF();
        training.displayWF();
    }

    return 0;
}