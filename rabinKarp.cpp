#include <iostream>
#include <string>
#include <vector>

const int prime = 101; // A prime number used for hashing

std::vector<int> RabinKarp(const std::string& pattern, const std::string& text) {
    int patternLength = pattern.length();
    int textLength = text.length();
    std::vector<int> occurrences; // Stores the starting indices of pattern occurrences in the text

    int patternHash = 0; // Hash value of the pattern
    int textHash = 0; // Hash value of the current text window

    int h = 1; // Value of h = prime^(patternLength - 1)

    // Calculate the initial hash values
    for (int i = 0; i < patternLength - 1; i++)
        h = (h * prime) % prime;

    // Calculate the hash values of the pattern and the first window of the text
    for (int i = 0; i < patternLength; i++) {
        patternHash = (patternHash * prime + pattern[i]) % prime;
        textHash = (textHash * prime + text[i]) % prime;
    }

    // Slide the pattern over the text and compare the hash values
    for (int i = 0; i <= textLength - patternLength; i++) {
        // If the hash values match, compare the characters
        if (patternHash == textHash) {
            bool found = true;
            for (int j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found)
                occurrences.push_back(i);
        }

        // Calculate the hash value of the next text window
        if (i < textLength - patternLength) {
            textHash = (prime * (textHash - text[i] * h) + text[i + patternLength]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }

    return occurrences;
}

int main() {
    std::string text = "ABCABCDABCDABCE";
    std::string pattern = "ABCD";
    std::vector<int> occurrences = RabinKarp(pattern, text);

    if (occurrences.empty()) {
        std::cout << "Pattern not found in the text.\n";
    } else {
        std::cout << "Pattern found at indices: ";
        for (int i = 0; i < occurrences.size(); i++) {
            std::cout << occurrences[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
