/*
For encrypting strings this region of chars is given (in this order!):

all letters (ascending, first all UpperCase, then all LowerCase)
all digits (ascending)
the following chars: .,:;-?! '()$%&"
These are 77 chars! (This region is zero-based.)

Write two methods:

std::string encrypt(std::string text)
std::string decrypt(std::string text)
Prechecks:

If the input-string has chars, that are not in the region, throw an Exception(C#, Python) or Error(JavaScript).
If the input-string is null or empty return exactly this value!
For building the encrypted string:

For every second char do a switch of the case.
For every char take the index from the region. Take the difference from the region-index of the char before (from the input text! Not from the fresh encrypted char before!). (Char2 = Char1-Char2)
Replace the original char by the char of the difference-value from the region. In this step the first letter of the text is unchanged.
Replace the first char by the mirror in the given region. ('A' -> '"', 'B' -> '&', ...)
Simple example:

Input: "Business"
Step 1: "BUsInEsS"
Step 2: "B61kujla"
B -> U
B (1) - U (20) = -19
-19 + 77 = 58
Region[58] = "6"
U -> s
U (20) - s (44) = -24
-24 + 77 = 53
Region[53] = "1"
Step 3: "&61kujla"
*/

#include <string>

using namespace std;

string ASCII = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;-?! '()$%&\"";

class Kata
{
public:
string encrypt(string text) {
    string newText = "";
    for (int i = 0; i < text.length(); i++) {
        // Do the switch of case every second char
        if (0 != i%2)
            if (islower(text[i])) text[i] = toupper(text[i]);
            else text[i] = tolower(text[i]);
        // Region index difference
        size_t indexCurrent = ASCII.find(text[i]);
        if (indexCurrent == string::npos) throw std::exception();
        size_t indexPrev = ASCII.find(text[i-1]);
        if (i > 0) {
            int calc = indexPrev - indexCurrent;
            newText += 0 > calc ? ASCII[77+calc] : ASCII[calc];
        } else newText += text[i];
    }
    // Replace the first char by the mirror in the given region.
    size_t firstCharIndex = ASCII.find(newText[0]);
    int mirror = abs((int)(firstCharIndex-76));
    newText[0] = ASCII[mirror];
    return newText;
}
  
string decrypt(string encryptedText) {
    // Replace the first char by the mirror in the given region.
    size_t firstCharIndex = ASCII.find(encryptedText[0]);
    int mirror = abs((int)(firstCharIndex-76));
    encryptedText[0] = ASCII[mirror];
    for (int i = 0; i < encryptedText.length(); i++) {
        // Region index difference.
        size_t indexCurrent = ASCII.find(encryptedText[i]);
        if (indexCurrent == string::npos) throw std::exception();
        size_t indexPrev = ASCII.find(encryptedText[i-1]);
        if (i > 0) {
            int calc = 77 - indexCurrent + indexPrev;
            if (calc > 76) calc -= 77;
            encryptedText[i] = ASCII[calc];
        }
    }
    // Do the switch of case every second char
    for (int i = 0; i < encryptedText.length(); i++) {
        if (0 != i%2) 
            if (islower(encryptedText[i])) encryptedText[i] = toupper(encryptedText[i]);
            else encryptedText[i] = tolower(encryptedText[i]);
    }
    return encryptedText;
}
};