class Solution {
public:
    bool isCircularSentence(string s) {
        char a;
        int cnt = 0;
        char b = s[0];
        for(int idx = 1; idx < s.size() ; idx++){
            if(b != s[idx] && idx + 1 == s.size()){
                return false;
            }
            if(s.size() - 1 == idx && cnt == 0){
                if(b != s[idx]){
                    return false;
                }
            }
            if(s[idx] == ' '){
                cnt++;
                a = s[idx - 1];
            }
            if(a != s[idx] && s[idx - 1] == ' '){
                return false;
            }
        }
        return true;
    }
};