//
// Created by leila on 2/8/2022.
//

#ifndef PA01_SENTIMENT_TESTINGDATA_H
#define PA01_SENTIMENT_TESTINGDATA_H

#include "Tweet.h"
#include "Word.h"
#include <iomanip>

class TestingData{
private:
    map<long, Tweet> tweetsAndIDs;
    vector<long> incorrectTweets;
    float accuracy = 0;

public:
    void retrieveTI(const vector<vector<DSString>>&); //get the tweet and ids from file input
    void displayTI();
    void calculateTS(const map<DSString, Word, DSStringCompare>&);
    void displayPredictedTS();
    void compareSentiments(const vector<vector<DSString>>&);
    void calculateAccuracy();
    float getAccuracy()const;
    vector<long>& getIT(); //show incorrect tweets





};
#endif //PA01_SENTIMENT_TESTINGDATA_H