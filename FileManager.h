//
// Created by leila on 2/3/2022.
//

#ifndef PA01_SENTIMENT_FILEMANAGER_H
#define PA01_SENTIMENT_FILEMANAGER_H

#include "DSString.h"
#include <fstream>
#include <map>
#include <vector>

class FileManager{
//create a trainingdata obj in this class and add parts of this map to training data map.
public:
    //map<DSString,int> readFile(DSString filename); use this one in trainingdata
    vector<vector<DSString>> readFile(const DSString& filename);
    void writeToFile(DSString, int* []); //array of incorrect tweet id's, this could change


};

#endif //PA01_SENTIMENT_FILEMANAGER_H
