#ifndef ASSIGNMENT5_PIPELINE_H
#define ASSIGNMENT5_PIPELINE_H

#include <string>
#include <algorithm>
#include <iostream>
#include "ActiveObject.h"

using namespace std;

class Pipeline {
private:
    ActiveObject removeSpecialCharsActiveObject;
    ActiveObject normalizeStringActiveObject;
    ActiveObject checkPalindromeActiveObject;
    ActiveObject printResultActiveObject;
public:
    Pipeline();
    void addString(const string& userInput);
};


#endif //ASSIGNMENT5_PIPELINE_H
