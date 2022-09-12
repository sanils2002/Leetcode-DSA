class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int st = 0, en = tokens.size();
        while(st < en) {
            if(power >= tokens[st])
                power -= tokens[st++];
            else if(st - (tokens.size() - en) and en > st + 1)
                power += tokens[--en];
            else
                break;
        }
        return st - (tokens.size() - en);
        
    }
};