#include "functions.h"
const char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
const long long size_of_hex = 16;
const char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string choose_your_conversion(const bool &check,const char &binary){ //Input Validation
    // if true, only can type numbers
    // if false, can type both letters and numbers
string hex_input;
string input;
string upperOut;

if(check && binary == 'b'){ // for if input is binary 0 and 1's 

    while(true){
        
        cout << "Enter Binary (Only 1's and 0's): ";
        cin >> input;
        if(binary_validation(input)){
            break;
        }
        cout << "Invalid Input, Try again\n";
    }
    return input;
}
if(check && binary == 'o'){ // For if input is meant to be octal 0-7

    while(true){
        
        cout << "Enter Octal (Only 0-7): ";
        cin >> input;
        if(octal_validation(input)){
            break;
        }
        cout << "Invalid Input, Try again\n";
    }
    return input;
}
if(check){ //if input is meant to be Hex Characters only
    while(true){

        bool valid = true;
        cout << "Enter HEX (0-9, A-F): ";
        cin >> hex_input; 
        for(int i = 0; i < hex_input.size(); i++){
            char c = toupper(hex_input[i]);
            bool found = false;
            for(int j = 0; j < size_of_hex; j++){
                if(c == hexDigits[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "Invalid Character!\n"; 
                valid = false;
                break;
            }
            
        }
        for (int i = 0; i < hex_input.size(); i++){
            upperOut += toupper(hex_input[i]);}
        hex_input = upperOut;
        if(valid){
            break;}
    }   // end of first while check
    return hex_input;
} // end of first if check
else{ // if input is meant to be numbers 0-9
    while(true){
        bool valid = true;
        cout << "Enter only Real Numbers (0-9): ";
        cin >> input;
        for(int i = 0; i < input.length(); i++){
            bool found = false;
            for(int j = 0; j < 10; j++){
                if(input[i] == digits[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "Invalid Character!\n"; 
                valid = false;
                break;
            }
        }
        if(valid){
            break;}

    }
return input;
} // end of else check, for if its only 0-9 ints 
}
bool octal_validation(string input){

    if(input.length() == 0){
    return false;}

    for(int i = 0; i < input.length(); i++) {
        if (input[i] < '0' || input[i] > '7') {
            return false;
        }
    }
    return true;
}

bool binary_validation(string input){
    
    if(input.empty()){ 
        return false;}

    for(int i = 0; i < input.length(); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return false;
        }
    }
    return true;
}

string quick_num2binary(char c){
    int num = c - '0';
    string numArray[8] = {"000","001","010","011","100","101","110","111"};
    return numArray[num];
}

void storesInNodes(string input, string output, Node*& head, char format1, char format2)
{
    Node* newNode = new Node(input, output, format1, format2);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;

}

void diffConversion::conversion(char i, char j, Node*& head){
    
    if (i == 'D' && j == 'O') {
        string input = choose_your_conversion(false, 'a');
        long long numberInput = stoll(input);
        string output = to_string(decimal_to_oct(numberInput));
        cout << output << endl;
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j });
    }
    else if (i == 'H' && j == 'D') {
        // Hex to decimal
        string value = choose_your_conversion(true, 'a');
        string output = to_string(hex_to_decimal(value));
        cout << output << endl;
        storesInNodes(value, output, head, i, j);
        historyStack.push({value, output, i, j});
    }
    else if (i == 'O' && j == 'D') {
        // Octal to decimal
        int input = stoi(choose_your_conversion(true, 'o'));
        string output = to_string(oct_to_decimal(input));
        cout << output << endl;
        storesInNodes(to_string(input), output, head, i, j);
        historyStack.push({to_string(input), output, i, j});

    }
    else if (i == 'B' && j == 'O') {
        // Binary to octal
        string input = choose_your_conversion(true, 'b');
        string output = to_string(binary_to_oct(input));
        cout << output << endl;
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j});
        
    }
    else if (i == 'D' && j == 'H') {
        // Decimal to hex
        string newInput = choose_your_conversion(false, 'a');
        long long input = stoll(newInput);
        string hexOutput = decimal_to_hex(input);
        cout << hexOutput << endl;
        storesInNodes(newInput, hexOutput, head, i, j);
        historyStack.push({newInput, hexOutput, i, j});


    }
    else if (i == 'H' && j == 'B') {
        // Hex to decimal to binary
        string input = choose_your_conversion(true, 'a');
        long long decimal = hex_to_decimal(input);  
        long long octal = decimal_to_oct(decimal);
        string output = oct_to_binary(octal);
        cout << output << endl;
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j});


    }
    else if (i == 'B' && j == 'D') {
        // Binary to decimal to octal
        string input = choose_your_conversion(true, 'b');
        long long decimal = binary_to_oct(input);
        string output = to_string(oct_to_decimal(decimal));
        cout << output << endl; 
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j});

    }
    else if (i == 'O' && j == 'B') {
        // Octal to decimal to binary
        string newinput = choose_your_conversion(true, 'o');
        long long input = stoll(newinput);
        string output = oct_to_binary(input);
        cout << output << endl;
        storesInNodes(newinput, output, head, i, j);
        historyStack.push({newinput, output, i, j});

  
    }
    else if (i == 'B' && j == 'H'){
        //Binary to octal to decimal to hex
        string input = choose_your_conversion(true, 'b');
        long octal = binary_to_oct(input);
        long long decimal = oct_to_decimal(octal);
        string output = decimal_to_hex(decimal);
        cout << output << endl;
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j});


    }
    else if (i == 'D' && j == 'B'){
        string input = choose_your_conversion(false, 'a');
        long long newInput = stoll(input);
        long long oct = decimal_to_oct(newInput);
        string output = oct_to_binary(oct);
        cout << output << endl;
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j});


    } 
    else if (i == 'H' && j == 'O'){
        string input = choose_your_conversion(true, 'a');
        long long newInput = hex_to_decimal(input);
        string output = to_string(decimal_to_oct(newInput));
        cout << output << endl;
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j});

    }
    else if (i == 'O' && j == 'H'){
        string input = choose_your_conversion(true, 'o');
        long long newInput =oct_to_decimal(stoll(input));
        string output = decimal_to_hex(newInput);
        cout << output << endl;
        storesInNodes(input, output, head, i, j);
        historyStack.push({input, output, i, j});
 
    }
    else{
        cout << "Invalid arguments!" << endl; //Fail-Safe
    }
}
    

    string diffConversion::oct_to_binary(long long input){
        string newInput = to_string(input);
        string output;
        for(int i = 0; i < newInput.length(); i++){
            output += quick_num2binary(newInput[i]);
        }
        return output;
    }

    long long diffConversion::decimal_to_oct(long long input){
    long long newInput;
    string output;
    vector<long long> my_vector;
    while(true){
    newInput = input % 8;
        my_vector.push_back(newInput);
        input /= 8;
        if(input <= 0){
        break;
        }
    }
        
    for(int i = int(my_vector.size()) - 1; i >= 0; --i){
        string c = to_string(my_vector[i]);
        output += c;
    }
    long long num = stoll(output);
    return num;
    }
    
    long long diffConversion::hex_to_decimal(string input){

    long long decimal = 0;
        for(int i = 0; i < input.length(); i++){
            for(int j = 0; j < 16; j++){
                if(input[i] == hexDigits[j]){
                    decimal = decimal * 16 + j;
                }
            }
        }
        return decimal;
    }

    string diffConversion::decimal_to_hex(long long input){
        long long newInput;
        string output;
        vector<long long> my_vector;
        while(true){
        newInput = input % 16;
            my_vector.push_back(newInput);
            input /= 16;
            if(input <= 0){
                break;
            }
        }
        
        for(int i = int(my_vector.size()) - 1; i >= 0; --i){
            char c = hexDigits[my_vector[i]];
            output += c;
        }
        return output;
    }

    long long diffConversion::oct_to_decimal(long long input){
        string newInput = to_string(input);
        long long output = 0;
        for(int i = 0; i < newInput.length(); i++){
            long long num = newInput[i] - '0';
            output = output * 8 + num; 
        }
    return output;
    }

    long long diffConversion::binary_to_oct(string binary){
        
        string final;
        if(binary.length()%3 == 1){
            string temp = "00";
            temp += binary;
            binary = temp;
        }
        if(binary.length()%3 == 2){
            string temp = "0";
            temp += binary;
            binary = temp;
        }
        for(int i = 3; i <= binary.length(); i += 3){
            long long sum = 0;
            if(binary[i - 3] == '1'){
                sum += 4;
            }
            if(binary[i - 2] == '1'){
                sum += 2;
            }
            if(binary[i - 1] == '1'){
                sum += 1;
            }
            
            final += to_string(sum);
            }
            long long num = stoll(final);
    return num;
        
    }