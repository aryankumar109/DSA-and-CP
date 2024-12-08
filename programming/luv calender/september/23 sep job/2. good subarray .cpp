class Solution {
  public:
    long long countoddSubarrays(int n, std::vector<int> &arr) {
        long long t = ((n - 1) / 2);
        long long sum = (t * (t + 1));
        if ((n & 1) == 0) {
            sum += (n / 2);
        }

        long long A = evenPosition(arr, n);
        long long B = oddPosition(arr, n);

        return sum - A - B;
    }

    long long evenPosition(std::vector<int> &arr, int n) {
        long long ans = 0;
        int freq[2] = {0, 0};
        int XOR = 0;

        for (int i = 0; i < n; i++) {
            XOR = XOR ^ arr[i];
            if ((i & 1) == 0)
                continue;
            if (XOR % 2 == 0) {
                ans += freq[0] + 1;
                freq[0]++;
            } else {
                ans += freq[1];
                freq[1]++;
            }
        }

        return ans;
    }

    long long oddPosition(std::vector<int> &arr, int n) {
        long long ans = 0;
        int freq[2] = {0, 0};
        int XOR = 0;

        for (int i = 0; i < n; i++) {
            XOR = XOR ^ arr[i];
            if ((i & 1) == 1)
                continue;
            if (XOR % 2 == 0) {
                ans += freq[0];
                freq[0]++;
            } else {
                ans += freq[1];
                freq[1]++;
            }
        }

        return ans;
    }
};
