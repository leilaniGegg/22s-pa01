//
// Created by leila on 2/3/2022.
//

#ifndef PA01_SENTIMENT_TRAININGDATA_H
#define PA01_SENTIMENT_TRAININGDATA_H

#include "DSString.h"
#include "Word.h"
#include <map>
#include <vector>
#include <iterator>
#include <iomanip>
#include <stdlib.h>

class TrainingData{
private:
    //tweet and sentiment number (0 or 4)
    map<DSString, int, DSStringCompare> tweetSentiment;
    //DSString and  word object with frequency( >0 for positive sentiment and <0 for negative sentiment)
    map<DSString, Word, DSStringCompare> wordFrequency;

public:
    void retrieveTS(const vector<vector<DSString>>&);  //the tweet sentiment, in training we don't care about id, username, etc
    void displayTS();
    void calculateWF();
    void displayWF();
    map<DSString, Word, DSStringCompare>& getWF();
    void calculateRanks();



};

#endif //PA01_SENTIMENT_TRAININGDATA_H
