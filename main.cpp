#include <iostream>
#include "oleanderstemminglibrary/include/olestem/stemming/english_stem.h"
#include "DSString.h"
#include "FileManager.h"
#include "TrainingData.h"
#include <vector>
#include <iomanip>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

using namespace std;

int main(int argc, char* const argv[]) {
    //if(argc == 1){
      //  return Catch::Session().run();
    //}
    //else {

        FileManager x;
        TrainingData y;
        y.retrieveTS(x.readFile("data/train_dataset_20k.csv"));
        y.calculateWF();
        y.displayWF();

        /*DSString p("test");
        wstring word(L"documentation");
        stemming::english_stem<DSString> StemEnglish;
        wcout << L"(English) Original text:\t" << p.c_str() << endl;
        StemEnglish(p);
        wcout << L"(English) Stemmed text:\t" << p.c_str() << endl;*/

        //ifstream trainingFile;

        //vector<vector<DSString>> trainingData;

    return 0;
}