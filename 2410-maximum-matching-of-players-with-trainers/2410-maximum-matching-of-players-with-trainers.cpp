class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int cnt = 0;
        int st = 0, en = 0;
        while(st < players.size() and en < trainers.size()) {
            if(trainers[en] >= players[st])
                cnt++, st++, en++;
            else
                en++;
        }
        
        return cnt;
        
    }
};