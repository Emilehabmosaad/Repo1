#include <iostream>
#include <string>
#include <map>
using namespace std;

// Function to read text input from the user
string ReadTextFromUser(string massege = "please enter a text: ")
{
    string Input, ValidInput;
    cout << massege;
    getline(cin, Input);

    // Convert input text to uppercase for consistency
    for (int i = 0; i < Input.size(); ++i)
    {
        ValidInput += toupper(Input[i]);
    }
    return ValidInput;
}

// Function to encrypt the text using Morse code
string Encryption(string text)
{
    // Define a map to store Morse code representations for each character
    map <char, string> MorseCode;
    // Assign Morse code representations for each character
    MorseCode['A'] = ".-"; MorseCode['B'] = "-..."; MorseCode['C'] = "-.-."; MorseCode['D'] = "-.."; MorseCode['E'] = "."; MorseCode['F'] = "..-.";
    MorseCode['G'] = "--."; MorseCode['H'] = "...."; MorseCode['I'] = ".."; MorseCode['J'] = ".---"; MorseCode['K'] = "-.-"; MorseCode['L'] = ".-..";
    MorseCode['M'] = "--"; MorseCode['N'] = "-."; MorseCode['O'] = "---"; MorseCode['P'] = ".--."; MorseCode['Q'] = "--.-"; MorseCode['R'] = ".-.";
    MorseCode['S'] = "..."; MorseCode['T'] = "-"; MorseCode['U'] = "..-"; MorseCode['V'] = "...-"; MorseCode['W'] = ".--"; MorseCode['X'] = "-..-";
    MorseCode['Y'] = "-.--"; MorseCode['Z'] = "--.."; MorseCode['1'] = ".----"; MorseCode['2'] = "..---"; MorseCode['3'] = "...--"; MorseCode['4'] = "....-";
    MorseCode['5'] = "....."; MorseCode['6'] = "-...."; MorseCode['7'] = "--..."; MorseCode['8'] = "---.."; MorseCode['9'] = "----."; MorseCode['0'] = "-----";
    MorseCode['?'] = "..--.."; MorseCode['!'] = "-.-.--"; MorseCode['.'] = ".-.-.-"; MorseCode[','] = "--..--"; MorseCode[';'] = "-.-.-."; MorseCode[':'] = "---...";
    MorseCode['+'] = ".-.-."; MorseCode['-'] = "-....-"; MorseCode['/'] = "-..-."; MorseCode['='] = "-...-";

    string EncryptedText;
    // Convert each character of the text to its Morse code representation
    for (char& c : text)
    {
        // If the character is a space, add three spaces to represent a word gap
        if (c == ' ')
        {
            EncryptedText += "   ";
            continue;
        }
        // Append Morse code for the character and a space to separate characters
        EncryptedText += MorseCode[c];
        EncryptedText += ' ';
    }

    return EncryptedText;
}

// Function to decrypt the text from Morse code
string Decryption(string EncryptedText)
{
    string temp, DecryptedText;
    // Define a map to store Morse code representations for each character
    map <char, string> MorseCode;
    // Assign Morse code representations for each character
    MorseCode['A'] = ".-"; MorseCode['B'] = "-..."; MorseCode['C'] = "-.-."; MorseCode['D'] = "-.."; MorseCode['E'] = "."; MorseCode['F'] = "..-.";
    MorseCode['G'] = "--."; MorseCode['H'] = "...."; MorseCode['I'] = ".."; MorseCode['J'] = ".---"; MorseCode['K'] = "-.-"; MorseCode['L'] = ".-..";
    MorseCode['M'] = "--"; MorseCode['N'] = "-."; MorseCode['O'] = "---"; MorseCode['P'] = ".--."; MorseCode['Q'] = "--.-"; MorseCode['R'] = ".-.";
    MorseCode['S'] = "..."; MorseCode['T'] = "-"; MorseCode['U'] = "..-"; MorseCode['V'] = "...-"; MorseCode['W'] = ".--"; MorseCode['X'] = "-..-";
    MorseCode['Y'] = "-.--"; MorseCode['Z'] = "--.."; MorseCode['1'] = ".----"; MorseCode['2'] = "..---"; MorseCode['3'] = "...--"; MorseCode['4'] = "....-";
    MorseCode['5'] = "....."; MorseCode['6'] = "-...."; MorseCode['7'] = "--..."; MorseCode['8'] = "---.."; MorseCode['9'] = "----."; MorseCode['0'] = "-----";
    MorseCode['?'] = "..--.."; MorseCode['!'] = "-.-.--"; MorseCode['.'] = ".-.-.-"; MorseCode[','] = "--..--"; MorseCode[';'] = "-.-.-."; MorseCode[':'] = "---...";
    MorseCode['+'] = ".-.-."; MorseCode['-'] = "-....-"; MorseCode['/'] = "-..-."; MorseCode['='] = "-...-";

    // Iterate through the encrypted text to decrypt Morse code
    for (int i = 0; i < EncryptedText.size(); ++i)
    {
        // If a space is encountered, find the corresponding character for the Morse code sequence stored in temp
        if (EncryptedText[i] == ' ')
        {
            for (const auto& pair : MorseCode)
            {
                if (pair.second == temp)
                {
                    DecryptedText += pair.first;
                    temp = "";
                }
            }
            // If the next character is also a space, add a space to the decrypted text
            if (EncryptedText[i + 1] == ' ')
            {
                if (DecryptedText[DecryptedText.size() - 1] == ' ')
                {
                    continue;
                }
                DecryptedText += " ";
            }
            continue;
        }

        temp += EncryptedText[i];

        if (i == EncryptedText.size() - 1)
        {
            for (const auto& pair : MorseCode)
            {
                if (pair.second == temp)
                {
                    DecryptedText += pair.first;
                    temp = "";
                }
            }
        }
    }
    return DecryptedText;
}

int main()
{
    cout << "Welcome! " << endl;

    // Read text input from the user for encryption
    string text1 = ReadTextFromUser("Please enter the text to encrypt: ");

    // Encrypt the input text using Morse code
    string EncryptedText = Encryption(text1);
    
    // Display the encrypted text
    cout << "the encrypted text is: " << EncryptedText << endl;

    // Read text input from the user for decryption
    string text2 = ReadTextFromUser("Please enter the text to decrypt: ");
    
    // Decrypt the encrypted text
    string DecryptedText = Decryption(text2);

    // Display the decrypted text
    cout << "the decrypted text is: " << DecryptedText << endl;

    return 0;
}
