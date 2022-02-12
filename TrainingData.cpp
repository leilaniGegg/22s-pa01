//
// Created by leila on 2/3/2022.
//

#include "TrainingData.h"

//
//Stores tweet and sentiment in a map
//
void TrainingData::retrieveTS(const vector<vector<DSString>>& trainingData){
     int size = trainingData.at(0).size(); //how many columns
     DSString tweet;
     for(int r = 0; r < trainingData.size(); r++){
             int sentiment = atoi(trainingData.at(r).at(0).c_str());
             tweet = (trainingData.at(r).at(size-1));
             tweetSentiment.insert(pair<DSString, int>(tweet.toLower(), sentiment));
     }
}

void TrainingData::displayTS(){
    map<DSString, int>::iterator itr;
    for(itr = tweetSentiment.begin(); itr != tweetSentiment.end(); itr++){
        cout << itr->second << "--" << itr->first << endl;
    }
}

//
//Calculating the frequency of words in positive and negative tweets
//
void TrainingData::calculateWF(){
    map<DSString, int>::iterator itr;
    for(itr = tweetSentiment.begin(); itr != tweetSentiment.end(); itr++){
        int tempSValue = itr-> second;  //the corresponding sentiment value from the tweetSentiment map
        DSString tempTweet = itr->first; //the tweet itself from tweetSentiment map
        //Store each word from tweet from tweetSentiment map
        vector<DSString> words = tempTweet.parseTweet(" ,.()!?;/`_$#%'…{}|+~@:&*-\"");
        for (int i = 0; i < words.size(); i++) {
            DSString currWord(words.at(i));
            //if the word is already in the list
            if (wordFrequency.count(currWord)) {
                auto itr2 = wordFrequency.find(currWord); //store location where the word already exists
                //increase the count for the word for either positive or negative count
                if (tempSValue == 0) {
                    itr2->second.incrementNegative();
                } else{
                    itr2->second.incrementPositive();
                }
            }
            else {
                wordFrequency.insert(pair<DSString, Word>(currWord, Word(currWord))); //add new pair to wordfrequency
               if (tempSValue == 0) {
                   auto itr3 = wordFrequency.find(currWord);
                   itr3->second.incrementNegative();
               } else{
                   auto itr4 = wordFrequency.find(currWord);
                   itr4->second.incrementPositive();
               }
            }
        }
    }
    //now for each word in the word frequency map, calculate its rank based on its positive and negative count
    calculateRanks();
}

//
//Calculate its ranking based on positive and negative counts
//
void TrainingData::calculateRanks() {
    map<DSString, Word>::iterator itr;
    for(itr = wordFrequency.begin(); itr != wordFrequency.end(); itr++){
        itr->second.calculateRank();
    }
}

void TrainingData::displayWF(){
    map<DSString, Word>::iterator itr;
    for(itr = wordFrequency.begin(); itr != wordFrequency.end(); itr++){
        cout << itr->first << " -- R:" << itr->second.getRank() << endl;
    }
}

map<DSString, Word, DSStringCompare>& TrainingData::getWF(){
    return wordFrequency;
}

