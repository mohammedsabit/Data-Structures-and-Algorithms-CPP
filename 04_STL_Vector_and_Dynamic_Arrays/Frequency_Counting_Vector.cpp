// Topic: Frequency Analysis
// Problem: Count the occurrence of each character in a string.
// Approach: Direct Mapping (Hashing). Using 'a' (ASCII 97) as the base index.
// Complexity: O(N) for counting, O(1) for printing (fixed alphabet size 26).

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // Fixed size vector for 26 lowercase letters
    vector<int> freq(26);               

    // Iterate string once -> O(N)
    for(int i = 0; i < s.size(); i++)       
    {
        int index = s[i] - 97; // Map 'a' to 0, 'b' to 1...
        freq[index]++;
    }

    // Iterate alphabet -> O(26) -> O(1)
    for(int i = 0; i < 26; i++)             
    {
        if(freq[i] > 0)
        {
            cout << char(i + 97) << " : " << freq[i] << endl;
        }
    }
    return 0;
}