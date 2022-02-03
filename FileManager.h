//
// Created by leila on 2/3/2022.
//

#ifndef PA01_SENTIMENT_FILEMANAGER_H
#define PA01_SENTIMENT_FILEMANAGER_H

#include "DSString.h"
#include <map>

class FileManager{
//create a trainingdata obj in this class and add parts of this map to training data map.
public:
    //map<DSString,int> readFile(DSString filename); use this one in trainingdata
    void readFile(DSString filename);
    void writeToFile(DSString filename, int* []); //array of incorrect tweet id's, this could change


};

#endif //PA01_SENTIMENT_FILEMANAGER_H
