#include <iostream>
#include "porter2_stemmer/porter2_stemmer.cpp"
#include "DSString.h"
#include "FileManager.h"
#include "TrainingData.h"
#include "TestingData.h"
#include <vector>
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
        TestingData testing;
        /*vector<vector<DSString>> x = IO.readFile(argv[2]);
        for(int i = 0; i < x.size(); i++){
            for(int j = 0; j < x.at(0).size(); j++){
                cout << x.at(i).at(j) << "--";
            }
            cout << endl;
        } */
        testing.retrieveTI(IO.readFile(argv[2]));
        testing.calculateTS(training.getWF());
        testing.displayPredictedTS();
    }

    return 0;
}