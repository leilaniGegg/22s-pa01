//
// Created by leila on 2/8/2022.
//

#include "TestingData.h"

void TestingData::retrieveTI(const vector<vector<DSString>>& testingData){
    int size = testingData.at(0).size();
    for(int r = 0; r < testingData.size(); r++){
        long ID = atol(testingData.at(r).at(0).c_str());
        Tweet tweet((testingData.at(r).at(size-1))); //correct syntax?
        tweetsAndIDs.insert(pair<long, Tweet>(ID, tweet));
    }
}

void TestingData::displayTI(){
    map<long, Tweet>::iterator itr;
    for(itr = tweetsAndIDs.begin(); itr != tweetsAndIDs.end(); itr++){
        cout << itr->first << "--" << itr->second << endl;
    }
}

//calculate the sentiment of each tweet. parameter is the wordFrequency map from training
void TestingData::calculateTS(const map<DSString, Word, DSStringCompare>& wordFrequency){
    //go through each word of the tweet, find its corresponding word in the
    // tweetsAndIds map, and calculate its sentiment by adding up the ranks
    vector<Word> wordsFromTweet;
    map<long, Tweet>::iterator itr;
    for(itr = tweetsAndIDs.begin(); itr != tweetsAndIDs.end(); itr++){
        Tweet* currTweet = &itr->second;
        wordsFromTweet = currTweet->getWords();
        for(int i = 0; i < wordsFromTweet.size(); i++){
            Word* currWord = &wordsFromTweet.at(i);
            if(wordFrequency.count(currWord->getActualWord())){
                auto itr2 = wordFrequency.find(currWord->getActualWord());
                currTweet->addToSentiment(itr2->second.getRank());
            }
        }
    }
}

void TestingData::displayPredictedTS(){
    map<long, Tweet>::iterator itr;
    for(itr = tweetsAndIDs.begin(); itr != tweetsAndIDs.end(); itr++){
        //print the predicted sentiment, the ID, and the tweet
        int sValue;
        if(itr->second.getPS() >= 0){
            sValue = 4;
        }
        else{
            sValue = 1;
        }
        cout << sValue << endl;
    }
}

void TestingData::compareSentiments(const vector<vector<DSString>>& input){
    map<long, Tweet>::iterator itr;
    for(itr = tweetsAndIDs.begin(); itr != tweetsAndIDs.end(); itr++){

    }
}