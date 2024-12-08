class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        string alice = "a";
        for(auto it : operations){
            if(it == 1){
                string next_word;
                for (char c : alice) {
                    next_word += (c == 'z') ? 'a' : c + 1;
                }
                alice += next_word  ;
            }
            else {
                alice += alice ;
            }
            if(alice.size() >= k) return alice[k - 1];
        }
        return alice[k - 1];
    }
};

