#include <iostream>
#include <fstream>
#include "DSString.h"
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ifstream trainingFile;
    vector<vector<string>> trainingData;
    trainingFile.open("data/train_dataset_20k.csv");
    //figure out how to store the training data
    if(!trainingFile.is_open()){
        cout << "Failed to open training file!" << endl;
        return -1;
    }
    DSString test("test");
    cout << test;
    //TEMPORARY, replace string with DSString
    string line;
    while(getline(trainingFile, line)){
        vector<string> row;
        stringstream inSS(line);
        string sValue, ID, date, trash, username, tweet;
        getline(inSS, sValue, ',');
        getline(inSS, ID, ',');
        getline(inSS, date, ',');
        //just delete this stupid idiot
        getline(inSS, trash, ',');
        getline(inSS, username, ',');
        getline(inSS, tweet);
        row.push_back(sValue);
        row.push_back(ID);
        row.push_back(date);
        row.push_back(username);
        row.push_back(tweet);
        trainingData.push_back(row);
    }

    for (int r = 0; r < trainingData.size(); r++){
        for (int c = 0; c < trainingData.at(0).size(); c++){
            cout << trainingData.at(r).at(c) << " ";
        }
        cout << endl;
    }

    //trainingFile.close();

    return 0;
}
