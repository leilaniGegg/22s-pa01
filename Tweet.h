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
    int predictedSentiment; // 0 or 4
    float tweetRank;  //adding up the ranks of every word in the tweet

public:
    Tweet(const DSString&);
    int getID()const;
    vector<Word> getWords()const;
    friend ostream& operator<< (ostream&, const Tweet&);
    void addtoRank(float); // add to the tweet rank
    float getTR()const;
    void determinePS(); //prediced sentiment
    int getPS();

};
#endif //PA01_SENTIMENT_TWEET_H
