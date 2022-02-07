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
    map<DSString, int, DSStringCompare> tweetSentiment; //tweet and sentiment number (0 or 4)
    map<DSString, Word, DSStringCompare> wordFrequency;  //word and frequency( >0 for positive sentiment and <0 for negative sentiment)

public:
    void retrieveTS(const vector<vector<DSString>>&);  //the tweet sentiment, in training we don't care about id, username, etc
    void displayTS();
    void calculateWF(); //not sure if this is right format
    void displayWF();
    map<DSString, Word, DSStringCompare>& getWF();
    bool isAllSpecialCharacters(const char*);



};

#endif //PA01_SENTIMENT_TRAININGDATA_H
