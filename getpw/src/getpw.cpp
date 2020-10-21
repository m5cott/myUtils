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

int main() {
    
    /*  
        time(0) will return the current secound count, 
        prompting srand() function to set a different seed
        for the rand() function each time the program runs.
    */
    srand(time(0));

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
    int passLen;
    cout << "Enter length of password: ";
    cin >> passLen;
    cout << "\n";

    for (int x = 0; x < passLen; x++) {
        cout << bank[rand() % 60];
    }
    cout << "\n";
    return 0;
}