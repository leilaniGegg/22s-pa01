//
// Created by leila on 2/6/2022.
//

#ifndef PA01_SENTIMENT_WORD_H
#define PA01_SENTIMENT_WORD_H

#include "DSString.h"

class Word{
private:
    DSString actualWord;
    int positiveCount;
    int negativeCount;
    float rank;

public:
    Word(const DSString&);
    ~Word();
    int getPCount();
    int getNCount();
    float getRank();
    DSString& getActualWord(); //not sure if I need this
    void incrementPositive();
    void incrementNegative();
    void calculateRank();

};

#endif //PA01_SENTIMENT_WORD_H
