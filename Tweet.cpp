//
// Created by leila on 2/8/2022.
//

#include "Tweet.h"

//this shouldd work??
Tweet::Tweet(const DSString& tweet){
    vector<DSString> wordsFromTweet = tweet.parseTweet(" ");
    for(int i = 0; i < wordsFromTweet.size(); i++){
        words.push_back(Word(wordsFromTweet.at(i)));
    }
}

int Tweet::getID()const{
    return ID;
}

vector<Word> Tweet::getWords()const{
    return words;
}


float Tweet::getTR()const{
    return tweetRank;
}

void Tweet::addtoRank(float rank){
    tweetRank += rank;
}

ostream& operator<< (ostream& output, const Tweet& tweet){
    for(int i = 0; i < tweet.words.size(); i++){
        output << tweet.words.at(i) << " ";
    }
    return output;
}

void Tweet::determinePS(){
    if(tweetRank >= 0){
        predictedSentiment = 4;
    }
    else{
        predictedSentiment = 0;
    }
}

int Tweet::getPS() {
    return predictedSentiment;
}