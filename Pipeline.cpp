
#include "Pipeline.h"

string resultRemoveSpecialChars;
string normalizeStringResult;
string checkPalindromeResult;

string removeSpecialChars(string input) {
    input.erase(remove_if(input.begin(), input.end(), ::ispunct), input.end());
    return input;
}

string normalizeString(string input) {
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    replace_if(input.begin(), input.end(), ::ispunct, ' ');
    return input;
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