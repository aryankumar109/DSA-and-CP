class Solution {
public:
    int countBalancedPermutations(string num) {
        const int MOD = 1e9 + 7;
        unordered_set<string> uniquePermutations;
        sort(num.begin(), num.end());
        do {
            uniquePermutations.insert(num);
        } while (next_permutation(num.begin(), num.end()));

        int balancedCount = 0;

        for (const string& perm : uniquePermutations) {
            if (isBalanced(perm)) {
                balancedCount = (balancedCount + 1) % MOD;
            }
        }

        return balancedCount;
    }

private:
    bool isBalanced(const string& s) {
        int evenSum = 0;
        int oddSum = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (i % 2 == 0) {
                evenSum += s[i] - '0';
            } else {
                oddSum += s[i] - '0';
            }
        }
        return evenSum == oddSum;
    }
};