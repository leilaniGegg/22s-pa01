//
// Created by leila on 2/6/2022.
//

#include "Word.h"

Word::Word(const DSString& temp){
    actualWord = temp;
    positiveCount = 0;
    negativeCount = 0;
    rank = 0;
}
//not too sure about this one
Word::~Word(){
}

int Word::getPCount(){
    return positiveCount;
}
int Word::getNCount(){
    return negativeCount;
}
float Word::getRank(){
    return rank;
}

DSString& Word::getActualWord(){
    return actualWord;
}

void Word::incrementPositive(){
    positiveCount++;
}
void Word::incrementNegative(){
    negativeCount++;
}

void Word::calculateRank(){
    rank = positiveCount - negativeCount;//maybe add dividing later
}