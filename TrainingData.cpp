//
// Created by leila on 2/3/2022.
//

#include "TrainingData.h"


//no clue if this works
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