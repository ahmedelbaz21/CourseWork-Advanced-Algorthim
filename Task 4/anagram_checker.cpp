#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string word1, string word2) {
  
    if (word1.length() != word2.length())
        return false;

    int freq[26] = {0}; 

    
    for (int i = 0; i < word1.length(); i++) {
        char c = word1[i];
        freq[c - 'a']++; 
    }

    
    for (int i = 0; i < word2.length(); i++) {
        char c = word2[i];
        freq[c - 'a']--;
        if (freq[c - 'a'] < 0) 
            return false;
    }

    return true;
}

int main() {
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    if (areAnagrams(word1, word2))
        cout << "The words are anagrams!" << endl;
    else
        cout << "The words are NOT anagrams." << endl;

    return 0;
}
