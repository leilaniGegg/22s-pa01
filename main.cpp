#include <iostream>
#include "porter2_stemmer/porter2_stemmer.cpp"
#include "DSString.h"
#include "FileManager.h"
#include "TrainingData.h"
#include "TestingData.h"
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
        training.retrieveTS(IO.readFile(argv[1]));
        training.calculateWF();
        //training.displayWF();
        TestingData testing;
        testing.retrieveTI(IO.readFile(argv[2]));
        testing.displayTI();
        testing.calculateTS(training.getWF());
        //testing.displayPredictedTS();
        testing.compareSentiments(IO.readFile(argv[3]));
        testing.calculateAccuracy();
        cout << testing.getAccuracy() << endl;
    }

    return 0;
}