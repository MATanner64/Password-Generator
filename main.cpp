#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define the array to hold all characters
    char allCharacters[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', // Digits
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', // Uppercase letters
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', // Lowercase letters
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '[', ']', '{', '}', '|', '\\', ';', ':', ',', '.', '/', '<', '>', '?', '`', '~', '\''
    };

    int passwordLength;
    int lower, upper;
    char numbers, specialCharacters, randomCharacter, resumeProgram;

    int randomNumber;

    string passwordOutput;

    bool end = false;

    while (end == false)   {
        cout << "Password length: ";
        cin >> passwordLength;

        cout << "Would you like any special characters (Y/N)? ";
        cin >> specialCharacters;

        cout << "Would you like any numbers(Y/N)? ";
        cin >> numbers;

        if (numbers == 'y' || numbers == 'Y')   {
            lower = 0;
            if (specialCharacters == 'Y' || specialCharacters == 'y')   {
                upper = 93;
            }
            else {
                upper = 62;
            }
        }
        else if (numbers == 'N' || numbers == 'n')  {
            lower = 10;
            if (specialCharacters == 'Y' || specialCharacters == 'y')   {
                upper = 93;
            }
            else {
                upper = 62;
            }
        }

        for (int x = 0; x <= passwordLength; x++)    {
            randomNumber = rand() % upper + lower;
            randomCharacter = allCharacters[randomNumber];
            passwordOutput += randomCharacter;
        }

        cout << "Your password is: " << passwordOutput << endl;
        cout << endl;

        passwordOutput.clear();

        //prompts the user if they want to end the program
        cout << "Do you wish to quit? (Y/N): ";
        cin >> resumeProgram;
        cin.ignore();

        // if they output Y/y, the while loop breaks
        if (resumeProgram == 'y' || resumeProgram == 'Y')   {
            end = true;
        }
    }



    return 0;
}
