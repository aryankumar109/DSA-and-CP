#include <string>
#include <cmath>

class Solution {
public:
    char kthCharacter(int k) {
        string alice = "a";
        while (alice.size() < k) {
            string next_word;
            for (char c : alice) {
                next_word += (c == 'z') ? 'a' : c + 1;
            }
            alice += next_word;
        }
        return alice[k - 1];
    }
};
