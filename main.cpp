#include <iostream>
#include "functions.h"
#include "ui.h"
#include <string>

int main(){
    diffConversion converter; //Initializes class instance with functions
    Node* head = nullptr; //Beginning of Nodes (the head)
    show_welcome_screen(); 
    while(true){

        char fromBase = prompt_base("Source base? (B=Binary, O=Octal, D=Decimal, H=Hex): ");
        char toBase = prompt_base("Target base? (B=Binary, O=Octal, D=Decimal, H=Hex): ");
        converter.conversion(fromBase, toBase, head);
        if(!ask_to_continue(head, converter)){
            break;
        }
        
    }
    
    cout << "Goodbye!\n";
    return 0;
}