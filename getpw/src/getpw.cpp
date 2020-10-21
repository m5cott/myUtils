/***************************************************
 * Name: getpw.cpp
 * Purpose: Password Generator for Person use
 * Author: Michael Scott (m5cott)
 * Created: 2020-10-21
 * License: MIT License
***************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// you can place "int argc, char *argv[]" as parameters in
// the main function to take user input on program run time

int main(int argc, char *argv[]) {
    
    char help[] = "help";
    if (strcmp (argv[1], help) == 0) {
        cout << "Program help information prints here";
        return 0;
    }

    /*  
        time(0) will return the current secound count, 
        prompting srand() function to set a different seed
        for the rand() function each time the program runs.
    */
    srand(time(0));

    // Simple, but no input checking...
    int len = atoi(argv[1]);
    int num = atoi(argv[2]);  

    char bank[] = {
        'a', 'b', 'c', 'd', 'e', 'f',    
        'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 
        's', 't', 'u', 'v', 'w', 'x',
        'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z',
        '!', '@', '#', '$', '%', '^',
        '&', '*'
    };
    
    // using 2nd argument for the amount of passwords to generate
    for (int x = 0; x < num; x++) {
        // creating random password
        for (int x = 0; x < len; x++) {
            cout << bank[rand() % 60];
        }
        cout << " ";
    }

    return 0;
}