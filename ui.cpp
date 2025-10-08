#include "ui.h"

void show_welcome_screen()
{
    cout << "\033[2J\033[H";

    cout << string(40, '=') << "\n";
    cout << "|" << string(22 / 2, ' ') << "Base Number Tool"  << string(22 / 2, ' ')  << "|\n";
    cout << string(40, '=') << "\n\n";

    cout << "Welcome! This tool converts numbers between bases.\n";
    cout << "- You’ll be prompted for source and target base.\n";
    cout << "Press Enter...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\033[2J\033[H";

}

char prompt_base(const string &prompt)
{
    char choice;
    while(true){
    cout << prompt;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    choice = toupper(choice);
    if (choice == 'D' || choice == 'O' || choice == 'B' || choice == 'H') {
        return choice;     
    }
    cout << "Invalid choice. Please enter B, O, D, or H.\n"; // Redoes the while loop
    }
}

bool ask_to_continue(Node*& head, const diffConversion& converter)
{
    char ans;
    cout <<"\n";
    while(true){
        cout << "Convert another number? (Y/N): H to see history: ";
        cin >> ans;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ans = toupper(ans);
    if (ans == 'Y'){ 
        return true;}

    if (ans == 'N'){ 
        return false;}

    if (ans == 'H'){
        whichHistory(head, converter);
        continue;} //Re-executes the while loop
    
    cout << "Invalid input. Please enter Y or N.\n";
    }

    return false; //Fail-safe return
}

void historyPrinter(Node *&head)
{
    Node* temp = head;
    cout << "\nConversion History (Old -> New):\n";
    cout << setw(10) << "Input" << setw(12) << "Output" << setw(15) << "Conversion\n";
    cout << string(50, '-') << "\n";
    while(temp != nullptr){
        cout << setw(10) << temp->input << setw(12) << temp->output << setw(10) << temp->format1 << "->" << temp->format2 << "\n";
        temp = temp->next;
    }
    cout << string(50, '-') << "\n";

}

void whichHistory(Node*& head, const diffConversion& converter)
{
    char ans;
    while(true){
    cout << "Do you want to see History New->Old(N) or Old->New(O) or Exit(X): ";
    cin >> ans;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ans = toupper(ans);
    if(ans == 'N'){
        historyStackPrinter(converter);
        break;
    }
    if(ans == 'O'){
        historyPrinter(head);
        break;
    }
    if(ans == 'X'){
        break;
    }
    cout << "Invalid Input\n";
    }
}

void historyStackPrinter(const diffConversion& converter)
{
    auto s = converter.getHistoryStack();

    cout << "\nConversion History (New -> Old):\n";
    cout << setw(10) << "Input" << setw(12) << "Output" << setw(15) << "Conversion\n";
    cout << string(50, '-') << "\n";
    while (!s.empty()) {
        const auto &r = s.top();
        cout << setw(10) << r.input << setw(12) << r.output << setw(10) << r.fromBase << "->" << r.toBase<< "\n";
        s.pop();
    }
    cout << string(50, '-') << "\n";
}