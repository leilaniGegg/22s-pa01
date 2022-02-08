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

void Tweet::calculatePS(){
    //later
}

float Tweet::getPS()const{
    return predictedSentiment;
}

void Tweet::addToSentiment(float rank){
    predictedSentiment += rank;
}

ostream& operator<< (ostream& output, const Tweet& tweet){
    for(int i = 0; i < tweet.words.size(); i++){
        output << tweet.words.at(i) << " ";
    }
    return output;
}