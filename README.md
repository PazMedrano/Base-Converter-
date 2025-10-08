# Base-Converter-
A binary, decimal, octal and hexadecimal converter in C++ 

It accomplishes this by utilizing class functions, input valdiation, functions that handle UI, and various librarys for datatype manipulation and other tasks.

The project is seperated into 5 files: main.cpp, ui.cpp, and functions.cpp. The functions.h and ui.h is where the functions and libraries are declared in order to be defined in the respective .cpp files.

First, a class is created (in functions.h) defining 6 different conversion functions that will take an input and return an output that will be used for either passing it down to another function, or displaying the output.

To save memory, sometimes its better to pass certain data by reference, but its not always necessary when its small data. Thats why in some of functions, some things are passed by reference or even in conjucution to constants (const&). At first we used int, and then moved onto a 32-bit data type 'long long' in order to use bigger numbers and not overflow the program.

In order to know what each user wants to convert from and to, we need to ask the User themselves. The prompting should be done in the UI file, and have some sort of input validation. A simple question that asks for a char (twice) and then passes those down into the function that handles what should be done with those chars. The conversion function does that and has a series of if's that check the input. Before any value is parsed down a function, input validation is crucial. The choose_your_conversion() function, does that (could be a misleading name). If it recieves B and H. It will make 3 function calls that parse down the input until it reaches Hexadecimal. (B->O->D->H) ==> Each arrow being a function call

Once the desired output is recieved, we should ask the User if they want to continue the program. But how do we make it so that the program keeps working more than once? A simple while(true) inside the main can get this job done. This while loop in main will keep repeating until something makes the loop break. The way the main has been structured allows for the prompt to come out at the beginning of each while loop iteration and to ask the user, theres an ask_to_continue() function that does precisely this. If it returns false, an if inside the main will check that and break the while loop.

Theres another thing the ask_to_continue() function asks for, and thats history. That segways into how a history is implemented. First we need to create a Node class that recieves information that we will need to display. We chose to want to display: the input, the output, and the two chars in order to display what those numbers are a conversion of. (Ex; 101 -> 7 | B->O) /Not what it looks like/ We need to pass all those values into a function that will store the information and connect them together. Essentially a linked list. If the User wants to see the history, they just input that they do, and a simple print function will take care of tht (historyPrinter).

Assuming the user no longer wants to continue, they type N or n when prompted and the program ends.

We used libraries like #include that uppercases lowercase char, #include for vectors in 2 of the functions handling the conversions, #include was very important because it trasnformed strings to long long using stoll() or got the length of strings, #include for cin.ignore(,) only, and #include for formatting manipulation.

Other libraries are included, but either have no use or are no longer required. But they dont affect the program, so leaving them there is fine.

The use of header gaurds in the program is also very important, like: #ifndef, #define, and #endif all help the program by allowing multiple inclusions of the same header file across different sources, which can cause compilation errors.