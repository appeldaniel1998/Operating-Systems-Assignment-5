
#include "Pipeline.h"

string resultRemoveSpecialChars;
string normalizeStringResult;
string checkPalindromeResult;

string removeSpecialChars(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '\n' || input[i] == '\r' || input[i] == '\t' || input[i] == '\v' || input[i] == '\f' ||
        input[i] == '\a' || input[i] == '\b' || input[i] == '\'' || input[i] == '\"' || input[i] == '\?' || input[i] == '\\') {
            input.erase(i, 1);
            i--;
        }
    }
    return input;
}

string normalizeString() {
    transform(resultRemoveSpecialChars.begin(), resultRemoveSpecialChars.end(), resultRemoveSpecialChars.begin(), ::toupper); //to upper case
    replace_if(resultRemoveSpecialChars.begin(), resultRemoveSpecialChars.end(), ::ispunct, ' ');
    return resultRemoveSpecialChars;
}

string checkPalindrome() {
    string reversed(normalizeStringResult.rbegin(), normalizeStringResult.rend());
    return normalizeStringResult == reversed ? "YES" : "NO";
}

void printResult(string input) {
    cout << "original: " << input << endl;
    cout << "polyndrom: " << checkPalindromeResult << endl;
}

Pipeline::Pipeline() {
    this->removeSpecialCharsActiveObject.start();
    this->normalizeStringActiveObject.start();
    this->checkPalindromeActiveObject.start();
    this->printResultActiveObject.start();
}

void Pipeline::addString(const string& userInput) {
    this->removeSpecialCharsActiveObject.AddTask([&]() {
        resultRemoveSpecialChars = removeSpecialChars(userInput);
        this->normalizeStringActiveObject.AddTask([&]() {
            normalizeStringResult = normalizeString();
            this->checkPalindromeActiveObject.AddTask([&]() {
                checkPalindromeResult = checkPalindrome();
                this->printResultActiveObject.AddTask([&]() {
                    printResult(userInput);
                });
            });
        });
    });
}