class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int st = 0, en = 0, x = 0;
        
        while(en < colors.size()) {
            if(colors[st] == colors[en]) {
                if(x >= neededTime[en])
                    time += neededTime[en];
                else
                    time += x, x = neededTime[en];
                en++;
            }
            else
                st = en, x = 0;
        }
        
        return time;
    }
};