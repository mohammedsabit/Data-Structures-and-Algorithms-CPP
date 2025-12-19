// Topic: String Processing (NLP)
// Problem: Split a sentence into individual words (Tokenization).
// Logic: Using the 'stringstream' class to treat a string like a data stream.
// Relevance: This logic is used in Data Science to parse textual data (e.g., CSV parsing).

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    // Read the full line (including spaces)
    getline(cin, s);
    
    // Initialize stringstream with the input string
    stringstream ss(s);
    string word;
    
    // Extraction operator (>>) automatically skips spaces and splits words
    while(ss >> word)
    {
        cout << word << endl;
    }
    return 0;
}