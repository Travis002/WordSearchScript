# Description

This C++ program has four different methods for analyzing words.
Two of the methods use different algorithms but achieve the same end result.
The words come from several files. 

The first two methods, searchByParallelArray() and searchByPhrase(),
find letters in a phrase to determine if some given candidate words
can be spelled from those letters.
       
- searchByParallelArray() uses a parallel array to keep track
  of each letter's usage from the main phrase.
- searchByPhrase() overwrites letters in a copy of the phrase.
 
The third method, searchForConsecutiveLetters(), checks if some words
contain the letters 'BA' in that exact order.
 
The fourth method, searchForStartChar(), determines if some words
start with any of the letters in 'MAPLE'.
