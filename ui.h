#ifndef UI_H
#define UI_H

#include "functions.h"
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

void show_welcome_screen(); //Welcome screen at the beginning

char prompt_base(const string& prompt); 
// ^^ Displays a prompt and recieves a char (with input validation), and sends the char into conversion in functions.h

bool ask_to_continue(Node*& head, const diffConversion& converter); //asks to continue (to exit program) and asks if you want to view history

void historyPrinter(Node*& head); //Prints Nodes (history)

void whichHistory(Node*& head, const diffConversion& converter);

void historyStackPrinter(const diffConversion& converter);

#endif