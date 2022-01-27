//
//
//Resources used:
//  https://www-geeksforgeeks-org.cdn.ampproject.org/v/s/www.geeksforgeeks.org/overloading-stream-insertion-operators-c/amp/?amp_gsa=1&amp_js_v=a8&usqp=mq331AQKKAFQArABIIACAw%3D%3D#amp_ct=1643261252202&amp_tf=From%20%251%24s&aoh=16432612505518&referrer=https%3A%2F%2Fwww.google.com&ampshare=https%3A%2F%2Fwww.geeksforgeeks.org%2Foverloading-stream-insertion-operators-c%2F
//
//
#include "DSString.h"

//
//   Constructors and Destructor
//
DSString::DSString(){
    word = nullptr;
    size = 0;
}
DSString::DSString(const char* input){
    size = strlen(input);
    word = new char[size + 1];
    strcpy(word, input);
}
DSString::DSString(const DSString& input){
    this->size = strlen(input.word);

    strcpy(this->word, input.word);
}
DSString::~DSString(){
    delete word;
}

//
//  Overloaded Operators
//
DSString& DSString::operator= (const char* temp){
    if(word != temp) {
        strcpy(word, temp);
        return *this;
    }
}
DSString& DSString::operator= (const DSString& temp){
    if(this->word != temp.word) {
        strcpy(this->word, temp.word);
        return *this;
    }
}
DSString DSString::operator+ (const DSString& temp){
    strcat(this->word, temp.word);
    this->size = strlen(this->word);
    return *this;
}
bool DSString::operator== (const char* temp){
    if(strcmp(word, temp) == 0){
        return true;
    }
    return false;
}
bool DSString::operator== (const DSString& temp){
    if (strcmp(this->word, temp.word) == 0)
    {
        return true;
    }
    return false;
}
bool DSString::operator> (const DSString& temp){
    if (strcmp(this->word, temp.word) > 0){
        return true;
    }
    return false;
}
bool DSString::operator> (const char* temp){
    if (strcmp(word, temp) > 0){
        return true;
    }
    return false;
}
bool DSString::operator< (const DSString& temp){
    if (strcmp(this->word, temp.word) < 0){
        return true;
    }
    return false;
}
bool DSString::operator< (const char* temp){
    if (strcmp(word, temp) < 0){
        return true;
    }
    return false;
}
//not too sure about this one
char& DSString::operator[] (const int index){
    return word[index];
}

//
// Other functions
//
int DSString::getLength(){
    return size;
}
DSString DSString::substring(int start, int numChars){
    char* tempWord;
    for (int i = start; i < start + numChars && i !='\0'; i++){
        strcat(tempWord, this->word);
    }
    DSString newString(tempWord);  //should this use 'new' or not?
    return newString;
}
//NOT sure on this
char* DSString::c_str(){
    return this->word;
}
//I thINK this will work??
std::ostream& operator<< (std::ostream& output, const DSString& temp){
    output << temp.word;
}