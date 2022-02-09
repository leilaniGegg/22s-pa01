//
// Created by leila on 2/8/2022.
//

#ifndef PA01_SENTIMENT_TWEET_H
#define PA01_SENTIMENT_TWEET_H

#include "Word.h"
#include "DSString.h"

class Tweet{
private:
    vector<Word> words;
    int ID; //the ID given from the file
    float predictedSentiment;
    bool predictionStatus;

public:
    Tweet(const DSString&);
    int getID()const;
    vector<Word> getWords()const;
    void calculatePS();
    friend ostream& operator<< (ostream&, const Tweet&);
    void addToSentiment(float);
    float getPS()const;

};
#endif //PA01_SENTIMENT_TWEET_H
