#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define Polybius Square as a 2D vector
vector<vector<char>> PolybiusSquare = { { 'A', 'B', 'C', 'D', 'E' },
                                        { 'F', 'G', 'H', 'I', 'K' },
                                        { 'L', 'M', 'N', 'O', 'P' },
                                        { 'Q', 'R', 'S', 'T', 'U' },
                                        { 'V', 'W', 'X', 'Y', 'Z' } };

// Function to check if a string contains only digits
bool isDigit(string input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to read text from the user
string ReadTextFromUser()
{
    string Input, ValidInput;
    cout << "Welcome! Please enter the text to encrypt: ";
    getline(cin, Input);

    // Convert input text to uppercase
    for (int i = 0; i < Input.size(); ++i)
    {
        ValidInput += toupper(Input[i]);
    }
    return ValidInput;
}

// Function to read the encryption key from the user
string ReadKeyFromUser()
{
    string Input, ValidInput;
    cout << "Enter the key (5 digits): ";
    getline(cin, Input);

    // Validate the key (must be 5 digits)
    while (!isDigit(Input) || Input.size() != 5)
    {
        cout << "Invalid input. Please enter a 5-digit key: ";
        getline(cin, Input);
    }

    // Remove any spaces from the key
    for (int i = 0; i < Input.size(); ++i)
    {
        if (Input[i] == ' ')
        {
            continue;
        }
        else
        {
            ValidInput += Input[i];
        }
    }
    return ValidInput;
}

// Function to encrypt the text using the Polybius Square and key
string Encryption(string text, string key)
{
    string EncryptedText;

    // Iterate through each character in the text
    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i] == ' ')
        {
            if (text[i - 1] == ' ')
            {
                continue;
            }
            EncryptedText += ' ';
        }
        else if (text[i] == 'J')
        {
            EncryptedText += "24"; // If the character is 'J', encrypt it as "24"
        }
        else if (isdigit(text[i]))
        {
            EncryptedText += text[i]; // If the character is a digit, keep it unchanged
        }
        else
        {
            // Find the corresponding coordinates in the Polybius Square and encrypt
            for (int k = 0; k < PolybiusSquare.size(); ++k)
            {
                for (int j = 0; j < PolybiusSquare[k].size(); ++j)
                {
                    if (text[i] == PolybiusSquare[k][j])
                    {
                        EncryptedText += key[k]; // Row coordinate
                        EncryptedText += key[j]; // Column coordinate
                    }
                }
            }
        }
    }
    return EncryptedText;
}

int main()
{
    // Read text to encrypt from the user
    string Input = ReadTextFromUser();

    // Read encryption key from the user
    string key = ReadKeyFromUser();

    // Encrypt the text using the Polybius Square and key
    string EncryptedText = Encryption(Input, key);

    // Display the encrypted text
    cout << "Encrypted text: " << EncryptedText << endl;

    return 0;
}
