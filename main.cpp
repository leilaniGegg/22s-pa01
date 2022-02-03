#include <iostream>
#include <fstream>
#include "DSString.h"
#include <vector>
#include <cstring>
#include <iomanip>
#include <map>
#include <iterator>

using namespace std;

int main() {
    ifstream trainingFile("data/train_dataset_20k.csv");
    /*map<int, DSString> order;
    order.insert(pair<int, DSString>(1, "helo"));
    map<int, DSString>::iterator itr;
    for(itr = order.begin(); itr != order.end(); itr++){
        cout << itr->first << " " << itr->second;
    } */

    vector<vector<DSString>> trainingData;
    trainingFile.open("data/train_dataset_20k.csv");
    if(!trainingFile.is_open()){
       cout << "Failed to open training file!" << endl;
        return -1;
    }

    char* line;
    trainingFile.get(line, 500, '\n');
    /*while(trainingFile.getline(line,500, '\n')){

        DSString sValue, ID, date, trash, username, tweet;

        ID.getline(inSS, ID, ',');
        date.getline(inSS, date, ',');
        //just delete this stupid idiot
        trash.getline(inSS, trash, ',');
        username.getline(inSS, username, ',');
        tweet.getline(inSS, tweet, '\n');
        row.push_back(sValue);
        row.push_back(ID);
        row.push_back(date);
        row.push_back(username);
        row.push_back(tweet);
        trainingData.push_back(row);
    }
*/
    for (int r = 0; r < trainingData.size(); r++){
        for (int c = 0; c < trainingData.at(0).size(); c++){
            cout << trainingData.at(r).at(c) << " ";
        }
        cout << endl;
    }

    trainingFile.close();

    return 0;
}
