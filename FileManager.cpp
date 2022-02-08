//
// Created by leila on 2/3/2022.
//

#include "FileManager.h"

vector<vector<DSString>> FileManager::readFile(const DSString& filename){
    ifstream trainingFile;
    trainingFile.open(filename.c_str());
    if (!trainingFile.is_open()) {
        cout << "Failed to open training file!" << endl;
    }
    vector<vector<DSString>> data;
    char line[500];
    while(trainingFile.getline(line, 500)) {
        vector<DSString> row;
        /*DSString sValue = strtok(line, ",");
        DSString ID = strtok(NULL, ",");
        DSString date = strtok(NULL, ",");
        DSString trash = strtok(NULL, ",");
        DSString username = strtok(NULL, ",");
        DSString tweet = strtok(NULL, "\n");
        row.push_back(sValue);
        row.push_back(ID);
        row.push_back(date);
        row.push_back(username);
        row.push_back(tweet);
        data.push_back(row);*/
        char* tempWord = strtok(line, ",");
        while(tempWord != NULL){
            DSString newWord(tempWord);
            row.push_back(newWord);
            tempWord = strtok(NULL, ",");
        }
        data.push_back(row);
    }
    trainingFile.close();
    return data;
}

void FileManager::writeToFile(DSString filename, int* []){

}
