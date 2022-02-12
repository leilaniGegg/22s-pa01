//
// Created by leila on 2/3/2022.
//

#include "FileManager.h"


vector<vector<DSString>> FileManager::readFile(const DSString& filename){
    ifstream file;
    file.open(filename.c_str());
    if (!file.is_open()) {
        cout << "Failed to open training file!" << endl;
    }
    vector<vector<DSString>> data;
    char line[500];
    while(file.getline(line, 500)) {
        vector<DSString> row;
        char* tempWord = strtok(line, ",");
        while(tempWord != NULL){
            DSString newWord(tempWord);
            row.push_back(newWord);
            tempWord = strtok(NULL, ",");
        }
        data.push_back(row);
    }
    file.close();
    return data;
}

void FileManager::writeToFile(const DSString& filename, TestingData& temp){
    ofstream file;
    file.open(filename.c_str());
    if (!file.is_open()) {
        cout << "Failed to open training file!" << endl;
        throw std::runtime_error("Stupid file");
    }
    file << setprecision(3) << temp.getAccuracy() << endl;
    vector<long>* wrong = &temp.getIT();
    for(int i = 0; i < wrong->size(); i++){
        file << wrong->at(i) << endl;
    }
    file.close();
}
