class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string>set1 ;
        for(int i=0 ; i<bannedWords.size(); i++){
            set1.insert(bannedWords[i]) ;
        }
        int count = 0 ;
        for(int i=0 ; i < message.size() ; i++){
            if(set1.find(message[i]) != set1.end()) count ++ ;
        }
        if(count >= 2) return true ;
        else return false ;
    }
};