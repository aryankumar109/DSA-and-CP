#include <unordered_map>
#include <string>

class Solution {
public:
    int numberOfSubstrings(std::string s, int k) {
        std::unordered_map<char, int> mpp;
        int i = 0, j = 0, n = s.size(), ans = 0;
        
        while (j < n) {
            mpp[s[j]]++;
            
            // Check if we have a valid substring where each character appears at least k times
            while (mpp[s[j]] >= k) {
                ans += (n - j); // Count all substrings starting from i to j
                mpp[s[i]]--; // Move the left end of the window forward
                i++; // Increase i to shrink the window
            }
            j++; // Move the right end of the window forward
        }
        
        return ans;
    }
};
