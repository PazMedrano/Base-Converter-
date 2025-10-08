#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <stack>

using namespace std;
extern const char hexDigits[16];
extern const long long size_of_hex;

class Node {
    public:
        string input, output;
        char format1, format2;
        Node* next = nullptr;
    
        Node(string value, string out, char conversion1, char conversion2) {
            format1 = conversion1;
            format2 = conversion2;
            input = value;
            output = out;
        }
    
    };

    struct HistoryRecord {
        string input;
        string output;
        char fromBase;
        char toBase;
        HistoryRecord(string value, string out, char conversion1, char conversion2) {
            fromBase = conversion1;
            toBase = conversion2;
            input = value;
            output = out;
        }
    };

string choose_your_conversion(const bool& check,const char& binary); //Input Validation Function
bool binary_validation(string input); //Helper function for choose_your_conversion
bool octal_validation(string input); //Helper function for choose_your_conversion
string quick_num2binary(char c); //Fast a quick single digit to binary conversion (helper function)

void storesInNodes(string input, string output, Node*& head, char format1, char format2);
//Stores input, output, passes head by reference, and the characters used all to display the history 
class diffConversion{

    private:
    stack<HistoryRecord> historyStack;
    
    public:
    void conversion(char i, char j, Node*& head); //Recieves the characters (B,O,D,H) to know what conversion to do

    string oct_to_binary(long long input); //Octal to Binary
    long long decimal_to_oct(long long input); //Decimal to Octal
    long long hex_to_decimal(string input); //Hexadecimal to Decimal

    string decimal_to_hex(long long input); //Decimal to Hexadecimal
    long long oct_to_decimal(long long input); //Octal to Decimal
    long long binary_to_oct(string binary); //Binary to Oct

    //Const qualified function
    auto getHistoryStack() const { // const ensures the function "read-only" allowing it to be sent by reference and to be used in other places
        return historyStack; // Returns a copy of the stack for UI.cpp to use
    };
};

#endif