#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string text, key, result = "";
    int keyIndex = 0;

    cout << "=== Vigenere Cipher ===\n\n";

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key: ";
    getline(cin, key);

    if (key == "") {
        cout << "\nPlease enter a key.\n";
        return 0;
    }

    for (int i = 0; i < key.length(); i++) {
        if (!isalpha(key[i])) {
            cout << "\nUse letters only for the key.\n";
            return 0;
        }
    }

    cout << "\nStep by step process:\n";
    cout << "A = 0, B = 1, C = 2, ... Z = 25\n\n";

    for (int i = 0; i < text.length(); i++) {
        char letter = text[i];

        // Spaces, numbers, and symbols are not encrypted.
        if (!isalpha(letter)) {
            result += letter;
            cout << letter << " stays the same\n";
            continue;
        }

        // Get the current key letter, then move to the next one.
        char keyLetter = key[keyIndex % key.length()];
        keyIndex++;

        // Make both letters uppercase so the math is easier.
        char plainUpper = toupper(letter);
        char keyUpper = toupper(keyLetter);

        int plainNumber = plainUpper - 'A';
        int keyNumber = keyUpper - 'A';

        // Add the two numbers. Mod 26 keeps the answer inside A to Z.
        int encryptedNumber = (plainNumber + keyNumber) % 26;
        char encryptedLetter = encryptedNumber + 'A';

        // Put back lowercase if the original letter was lowercase.
        if (islower(letter)) {
            encryptedLetter = tolower(encryptedLetter);
        }

        result += encryptedLetter;

        cout << letter << " with key " << keyUpper
             << " : (" << plainNumber << " + " << keyNumber << ") % 26 = "
             << encryptedNumber << " which is " << encryptedLetter << endl;
    }

    cout << "\nEncrypted text: " << result << endl;

    return 0;
}
    