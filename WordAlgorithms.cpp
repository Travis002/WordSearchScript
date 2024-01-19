#include <iostream>
#include <fstream>

class WordAlgorithms
{
public:
    /*
    * Algorithm 1: Use a parallel array to check if a word can
    * be spelled using letters from another phrase
    */
    static void searchByParallelArray(std::string fileToOpen) {
        std::fstream wordFile;
        wordFile.open(fileToOpen);

        std::string originalPhrase = "GEORGEWASHINGTON";
        std::cout << "The phrase is " << originalPhrase << "\n\n";

        // check each word that is provided
        while (!wordFile.eof()) {
            // the array below is parallel with the original phrase
            // it indicates if a letter is used to spell the candidate.
            // (false = not used, true = used)
            const int lettersUsedLen = 16;
            bool lettersUsed[lettersUsedLen] = { false, false, false, false, false, false, false, false, false, false,
                        false, false, false, false, false, false };

            std::string candidate;
            wordFile >> candidate;

            /*
            * For each letter, search the phrase for that letter.
            * If found, mark it as used.
            */
            int numberOfLettersFound = 0;
            // go through each phrase in the file
            for (int candidateIndex = 0; candidateIndex < candidate.size(); candidateIndex++) {
                // search through each phrase
                for (int phraseIndex = 0; phraseIndex < originalPhrase.size(); phraseIndex++) {
                    // if the letters match AND the letter hasn't been used, use it
                    if (candidate[candidateIndex] == originalPhrase[phraseIndex] && lettersUsed[phraseIndex] == false) {
                        lettersUsed[phraseIndex] = true;
                        numberOfLettersFound++;
                        break;
                    }
                }

            }
            // output a header for the results
            bool canBeSpelled = true;
            if (numberOfLettersFound == candidate.size()) {
                std::cout << "The word " << candidate << " can be spelled using these letters: ";
            }
            else if (numberOfLettersFound > 0 && numberOfLettersFound < candidate.size()) {
                std::cout << "The word " << candidate << " cannot be spelled but shares " << numberOfLettersFound << " letters: ";
            }

            else {
                std::cout << "The word " << candidate << " shares no letters" << "\n";
                canBeSpelled = false;
            }

            // display the letters used and their indexes (if any)
            if (canBeSpelled) {
                for (int index = 0; index < lettersUsedLen; index++) {
                    if (lettersUsed[index]) {
                        std::cout << originalPhrase[index] << "[" << index << "] ";
                    }
                }
            }

            std::cout << "\n";
        }
        wordFile.close();
    }

    /*
    * Algorithm 2: Use a string to check if a word can
    * be spelled using words from another phrase
    */
    static void searchByPhrase(std::string fileToOpen, std::string phraseToSearch) {
        std::fstream wordFile;
        wordFile.open(fileToOpen);

        // a copy of the phrase retained to see which letters were used
        const std::string originalPhrase = phraseToSearch;

        std::cout << "The phrase is " << originalPhrase << "\n\n";

        // check each word that is provided
        int wordCount = 0;
        while (!wordFile.eof()) {
            // this copy is used to overwrite letters with an '*'.
            std::string lettersUsed = "";
            std::string result;

            // copy the phrase to lettersUsed
            for (int index = 0; index < originalPhrase.length(); index++) {
                lettersUsed += originalPhrase[index];
            }

            // the word to check
            std::string candidate;
            wordFile >> candidate;

            // search through the phrase for each letter in the candidate
            int numberOfLettersFound = 0;
            // go through each phrase in the file
            for (int candidateIndex = 0; candidateIndex < candidate.size(); candidateIndex++) {
                // search through each phrase
                for (int phraseIndex = 0; phraseIndex < originalPhrase.size(); phraseIndex++) {
                    // only use a letter if it matches AND has not been used before
                    if (candidate[candidateIndex] == originalPhrase[phraseIndex] && lettersUsed[phraseIndex] != '*') {
                        lettersUsed[phraseIndex] = '*';
                        numberOfLettersFound++;
                        break;
                    }
                }
            }

            // output a summary of results.
            if (numberOfLettersFound == candidate.size()) {
                std::cout << "The word " << candidate << " can be spelled" << "\n";
            }
            else if (numberOfLettersFound > 0 && numberOfLettersFound < candidate.size()) {
                std::cout << "The word " << candidate << " cannot be spelled but shares " << numberOfLettersFound << " letters" << "\n";
            }
            else {
                std::cout << "The word " << candidate << " shares no letters" << "\n";
            }

            // output both the original phrase and the marked up phrase for comparison
            std::cout << originalPhrase << "\n";
            std::cout << lettersUsed << "\n";
        }
        wordFile.close();
    }

    /*
    * Algorithm 3: Check if a word contains letters
    * in an exact order
    */
    static void searchForConsecutiveLetters(std::string fileToOpen, char fl, char sl) {
        // each word must contain these two consecutive letters.
        char firstLetter = fl;
        char secondLetter = sl;

        std::fstream wordFile;
        wordFile.open(fileToOpen);

        // check every candidate word
        while (!wordFile.eof()) {
            std::string candidate;
            wordFile >> candidate;

            // search each word for the consecutive letters (firstLetter then secondLetter)
            bool hasLetters = false;
            int indexOfFirstLetter;
            for (indexOfFirstLetter = 0; indexOfFirstLetter < candidate.length() - 1; indexOfFirstLetter++) {
                if (candidate[indexOfFirstLetter] == firstLetter && candidate[indexOfFirstLetter + 1] == secondLetter) {
                    hasLetters = true;
                    break;
                }
            }

            // display results of the search
            if (hasLetters) {
                std::cout << candidate << " has '" << firstLetter << secondLetter << "' at indexes " << indexOfFirstLetter << " and " << indexOfFirstLetter + 1 << "\n";
            }
            else {
                std::cout << candidate << " does not contain '" << firstLetter << secondLetter << "' consecutively" << "\n";
            }
        }
    }

    /*
    * Algorithm 4: Check if a word begins with a given set of letters
    */
    static void searchForStartChar(std::string fileToOpen, char letters[], const int lettersLen) {
        std::fstream wordFile;
        wordFile.open(fileToOpen);

        // go through each word
        bool doesStartLetterMatch;
        while (!wordFile.eof()) {
            std::string candidate;
            wordFile >> candidate;
            doesStartLetterMatch = false;
            // check if each word starts with a certain letter
            for (int index = 0; index < lettersLen; index++) {
                if (candidate[0] == letters[index]) {
                    doesStartLetterMatch = true;
                    std::cout << candidate << " starts with the letter " << letters[index] << "\n";
                }
            }

            // output if first letter does not match
            if (doesStartLetterMatch == false) {
                std::cout << candidate << " does not start with ";
                for (int index = 0; index < lettersLen; index++) {
                    if (index < lettersLen - 1) {
                        std::cout << letters[index] << ", ";
                    }
                    else {
                        std::cout << "or " << letters[index] << "\n";
                    }
                }
            }
        }
    }
};