/*
* Written by Travis Bode
* 1/19/2024
*
* This C++ program has four different methods for analyzing words.
* Two of the methods use different algorithms but achieve the same end result.
* The words come from several files.
* 
* The first two methods, searchByParallelArray() and searchByPhrase(),
* find letters in a phrase to determine if some given candidate words
* can be spelled from those letters.
*       
*       - searchByParallelArray() uses a parallel array to keep track
            of each letter's usage from the main phrase.
*       - searchByPhrase() overwrites letters in a copy of the phrase.
* 
* The third method, searchForConsecutiveLetters(), checks if some words
* contain the letters 'BA' in that exact order.
* 
* The fourth method, searchForStartChar(), determines if some words
* start with any of the letters in 'MAPLE'.
*/

#include <iostream>
#include <fstream>
#include "WordAlgorithms.cpp"

int main() {
    // Algorithm 1
    std::cout << "1st algorithm: marking letters as present with a parallel array\n";
    std::cout << "----------------------------------------------------\n";
    WordAlgorithms::searchByParallelArray("george_washington_words.txt");
    std::cout << "-------------------------END------------------------\n\n\n";

    // Algorithm 2
    std::cout << "\n2nd algorithm: finding letters by erasing letters from the phrase\n";
    std::cout << "----------------------------------------------------\n";
    WordAlgorithms::searchByPhrase("george_washington_words.txt", "GEORGEWASHINGTON");
    std::cout << "-------------------------END------------------------\n\n\n";

    // Algorithm 3
    std::cout << "\n3rd algorithm: check if 'BA' is in a set of words\n";
    std::cout << "----------------------------------------------------\n";
    WordAlgorithms::searchForConsecutiveLetters("ba_words.txt", 'B', 'A');
    std::cout << "-------------------------END------------------------\n\n\n";

    // Algorithm 4
    std::cout << "\n4th algorithm: check if a set of words start with 'M', 'A', 'P', 'L', or 'E'\n";
    std::cout << "----------------------------------------------------\n";
    const int startLettersLen = 5;
    char startLetters[startLettersLen] = { 'M', 'A', 'P', 'L', 'E'};
    WordAlgorithms::searchForStartChar("maple_words.txt", startLetters, startLettersLen);
    std::cout << "-------------------------END------------------------\n\n\n";
}