class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n < m) return 0;

        vector<int> mpp1(26, 0), mpp2(26, 0);

        // Count frequency of characters in word2
        for (int k = 0; k < m; k++) {
            mpp2[word2[k] - 'a']++;
        }

        long long ans = 0;
        int i = 0, j = m - 1;

        // Initialize frequency map for the first m characters of word1
        for (int k = 0; k < m; k++) {
            mpp1[word1[k] - 'a']++;
        }

        while (i <= j - m + 1 && j < n) {
            bool flag = true;
            for (int k = 0; k < 26; k++) {
                if (mpp1[k] < mpp2[k]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans += (n - i) - (j - i + 1) + 1;
                mpp1[word1[i] - 'a']--;
                i++;
            } else {
                j++;
                if (j < n) {
                    mpp1[word1[j] - 'a']++;
                }
            }

            if (i > j - m + 1) {
                j++;
                if (j < n) {
                    mpp1[word1[j] - 'a']++;
                }
            }
        }

        return ans;
    }
}; 