//
// Created by leila on 2/3/2022.
//

#include "TrainingData.h"


//no clue if this works
//stores tweet and sentiment in a map
void TrainingData::retrieveTS(const vector<vector<DSString>>& trainingData){
     int size = trainingData.at(0).size(); //how many columns
     DSString tweet;
     for(int r = 0; r < trainingData.size(); r++){
             int sentiment = atoi(trainingData.at(r).at(0).c_str());
             tweet = (trainingData.at(r).at(size-1));
             tweetSentiment.insert(pair<DSString, int>(tweet, sentiment));
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
        int tempSValue = itr-> second;  //the corresponding sentiment value from the tweetsentiment map
        char* tempTweet = itr->first.c_str(); //the tweet itself from tweetsentiment map
        char* tempWord = strtok(tempTweet, " "); //each word from tweet from tweetsentiment map
        //check if the word starts with @ (a username) or only contains special characters
        if(tempWord[0] == '@' || isAllSpecialCharacters(tempWord)){ //add second condition
            continue;
        }
        while(tempWord != NULL){
            if(wordFrequency.count(tempWord)){
                //if the word is already in the list
                auto itr2 = wordFrequency.find(tempWord); //store location where the word already exists
                //increase the count for the word for either positive or negative count
                if(tempSValue == 0){
                    itr2->second.incrementNegative();
                }
                else if(tempSValue == 4){
                    itr2->second.incrementPositive();
                }
            }
            else{
                wordFrequency.insert(pair<DSString, Word>(tempWord, Word(tempWord))); //add new pair to wordfrequency
                if(tempSValue == 0){
                    wordFrequency.rbegin()->second.incrementNegative();
                }
                else if(tempSValue == 4){
                    wordFrequency.rbegin()->second.incrementPositive();
                }
            }
            tempWord = strtok(NULL, " ");
        }
    }
}

void TrainingData::displayWF(){
    map<DSString, Word>::iterator itr;
    for(itr = wordFrequency.begin(); itr != wordFrequency.end(); itr++){
        cout << itr->first << " -- P:" << itr->second.getPCount() << "  N:" << itr->second.getNCount() << endl;
    }
}
//might need this function?
map<DSString, Word, DSStringCompare>& TrainingData::getWF(){
    return wordFrequency;
}

bool TrainingData::isAllSpecialCharacters(const char* temp){
    for(int i =0; i < strlen(temp); i++){
        if(isalpha(temp[i])){
            return false;
        }
    }
    return true;
}
