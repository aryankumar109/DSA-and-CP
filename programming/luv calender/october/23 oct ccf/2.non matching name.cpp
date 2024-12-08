#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        int n, m;
        cin >> n >> m;
        cin.ignore(); // Ignore the newline character after reading n and m
        
        string sa, sb;
        getline(cin, sa); // Read the first string
        getline(cin, sb); // Read the second string
        
        vector<int> alphabet(26, 0);
        
        // Count characters in sa
        for (char c : sa) {
            if (isalpha(c)) { // Check if it's a letter
                alphabet[tolower(c) - 'a']++;
            }
        }
        
        // Count characters in sb
        for (char c : sb) {
            if (isalpha(c)) { // Check if it's a letter
                alphabet[tolower(c) - 'a']++;
            }
        }

        // Check if all letters are present
        bool allPresent = true;
        for (int count : alphabet) {
            if (count == 0) {
                allPresent = false;
                break;
            }
        }
        
        if (allPresent) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
