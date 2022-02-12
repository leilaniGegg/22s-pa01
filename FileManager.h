//
// Created by leila on 2/3/2022.
//

#ifndef PA01_SENTIMENT_FILEMANAGER_H
#define PA01_SENTIMENT_FILEMANAGER_H

#include "DSString.h"
#include "TestingData.h"
#include "Tweet.h"
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>

class FileManager{

//create a trainingdata obj in this class and add parts of this map to training data map.
public:
    vector<vector<DSString>> readFile(const DSString&);
    void writeToFile(const DSString&, TestingData&);
};

#endif //PA01_SENTIMENT_FILEMANAGER_H
