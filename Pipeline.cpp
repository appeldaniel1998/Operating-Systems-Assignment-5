
#include "Pipeline.h"
string removeSpecialChars(string input) {
    input.erase(remove_if(input.begin(), input.end(), ::ispunct), input.end());
    return input;
}

string normalizeString(string input) {
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    replace_if(input.begin(), input.end(), ::ispunct, ' ');
    return input;
}

string checkPalindrome(string input) {
    string reversed(input.rbegin(), input.rend());
    return input == reversed ? "YES" : "NO";
}

void printResult(string input, string palindrome_result) {
    cout << "original: " << input << endl;
    cout << "polyndrom: " << palindrome_result << endl;
}

Pipeline::Pipeline() {
    this->removeSpecialCharsActiveObject.start();
    this->normalizeStringActiveObject.start();
    this->checkPalindromeActiveObject.start();
    this->printResultActiveObject.start();
}

void Pipeline::addString(const string& userInput) {
    this->removeSpecialCharsActiveObject.AddTask([&]() {
        string resultRemoveSpecialChars = removeSpecialChars(userInput);
        this->normalizeStringActiveObject.AddTask([&]() {
            string normalizeStringResult = normalizeString(resultRemoveSpecialChars);
            this->checkPalindromeActiveObject.AddTask([&]() {
                string checkPalindromeResult = checkPalindrome(normalizeStringResult);
                this->printResultActiveObject.AddTask([&]() {
                    printResult(userInput, checkPalindromeResult);
                });
            });
        });
    });
}