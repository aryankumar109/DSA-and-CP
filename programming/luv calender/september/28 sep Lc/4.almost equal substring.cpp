

class Solution {
public:
    int minStartingIndex(string s, string pattern) {
        int n = s.size();
        int m = pattern.size();
        if (n < m) return -1;

        vector<int> dp1(n, 0), dp2(n, 0);

        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (j < m && i + j < n && s[i + j] == pattern[j]) {
                j++;
            }
            dp1[i] = j;
        }

        for (int i = n - 1; i >= 0; --i) {
            int length = 0;
            for (int j = 0; j < m && i - j >= 0; ++j) {
                if (s[i - j] == pattern[m - 1 - j]) {
                    length++;
                } else {
                    break;
                }
            }
            dp2[i] = length;
        }

        for (int i = 0; i <= n - m; ++i) {
            if (dp1[i] + dp2[i + m - 1] >= m - 1) {
                return i;
            }
        }

        return -1;
    }
};
