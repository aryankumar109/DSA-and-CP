class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            vector<int> vowelCount(5, 0); 
            
            for (int j = i; j < n; ++j) {
                if (word[j] == 'a') {
                    vowelCount[0]++;
                } else if (word[j] == 'e') {
                    vowelCount[1]++;
                } else if (word[j] == 'i') {
                    vowelCount[2]++;
                } else if (word[j] == 'o') {
                    vowelCount[3]++;
                } else if (word[j] == 'u') {
                    vowelCount[4]++;
                } else {
                    count++;
                }
                if (vowelCount[0] > 0 && vowelCount[1] > 0 && vowelCount[2] > 0 &&
                    vowelCount[3] > 0 && vowelCount[4] > 0 && count == k) {
                    ans++;
                }
                if (count > k) break;
            }
        }
        
        return ans;
    }
};
