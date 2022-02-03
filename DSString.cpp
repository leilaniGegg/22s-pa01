//
//
//Resources used:
//  https://www-geeksforgeeks-org.cdn.ampproject.org/v/s/www.geeksforgeeks.org/overloading-stream-insertion-operators-c/amp/?amp_gsa=1&amp_js_v=a8&usqp=mq331AQKKAFQArABIIACAw%3D%3D#amp_ct=1643261252202&amp_tf=From%20%251%24s&aoh=16432612505518&referrer=https%3A%2F%2Fwww.google.com&ampshare=https%3A%2F%2Fwww.geeksforgeeks.org%2Foverloading-stream-insertion-operators-c%2F
//  https://stackoverflow.com/questions/54526582/implementing-getline-for-my-custom-string-class (used for reference for implementing getline
//
#include "DSString.h"

//
//   Constructors and Destructor
//
DSString::DSString(){
    word = nullptr;
}
DSString::DSString(const char* input){
    if(input == nullptr){
        word = nullptr;
    }
    else {
        word = new char[strlen(input) + 1];
        strcpy(word, input);
    }
}
DSString::DSString(const DSString& input){
    word = new char[strlen(input.word) + 1];
    strcpy(word, input.word);
}
DSString::~DSString(){
    if(word != nullptr){
        delete word;
    }
}

//
//  Overloaded Operators
//
//works!
DSString& DSString::operator= (const char* temp){
        strcpy(word, temp);
        return *this;
}
//works!
DSString& DSString::operator= (const DSString& temp){
        strcpy(this->word, temp.word);
        return *this;
}
//working !!!!!!!!!!!!!!!wait double check
DSString DSString::operator+ (const DSString& temp){
    DSString newWord(*this);
    strcat(newWord.word, temp.word);
    return newWord;
}
//working
DSString& DSString::operator+= (const DSString& temp){
    strcat(this->word, temp.word);
    return *this;
}

//works!
bool DSString::operator== (const char* temp){
    if(strcmp(word, temp) == 0){
        return true;
    }
    return false;
}
//works
bool DSString::operator== (const DSString& temp){
    if (strcmp(this->word, temp.word) == 0)
    {
        return true;
    }
    return false;
}
//works
bool DSString::operator> (const DSString& temp){
    if (strcmp(this->word, temp.word) > 0){
        return true;
    }
    return false;
}
//works
bool DSString::operator> (const char* temp){
    if (strcmp(word, temp) > 0){
        return true;
    }
    return false;
}
//works
bool DSString::operator< (const DSString& temp){
    if (strcmp(this->word, temp.word) < 0){
        return true;
    }
    return false;
}
//works
bool DSString::operator< (const char* temp){
    if (strcmp(word, temp) < 0){
        return true;
    }
    return false;
}
//code the throw better? but it still works!
char& DSString::operator[] (const int index){
    if (index >= this->getLength()){
        throw std::out_of_range ("Index out of range!");
    }
    return word[index];

}

//
// Other functions
//
//works!
int DSString::getLength(){
    return strlen(word);
}
//works!
DSString DSString::substring(int start, int numChars){
    //think about adding error handling
    int substringLength = this->getLength() + 1; // plus one to include the null character at the end
    char tempWord[substringLength];
    int i, x;
    for (i = start, x = 0; i < start + numChars && i !='\0' && x < substringLength; i++, x++){
        tempWord[x] = this->word[i];
    }
    DSString newString(tempWord);  //should this use 'new' or not?
    return newString;
}
//works? not sure the point of this
char* DSString::c_str(){
    return this->word;
}
//works now!
ostream& operator<< (ostream& output, const DSString& temp){
    output << temp.word;
    return output;
}
//file getline
ifstream& DSString::getline(ifstream& inSS, DSString& word){
    char* temp;
    inSS.get(temp, 500);
    word += DSString(temp); //will this work?
    return inSS;
}

//string stream getline
istream& DSString::getline(istream& inSS, DSString& word, const char& delim){
    char* temp;
    inSS.get(temp, 500, delim);
    word += DSString(temp); //will this work?
    return inSS;
}

istream& operator>>(istream& inSS, DSString& word){
    char* temp;
    //memset(&buff[0], 0, sizeof(buff));
    inSS >> temp;
    word = temp;
    return inSS;
}