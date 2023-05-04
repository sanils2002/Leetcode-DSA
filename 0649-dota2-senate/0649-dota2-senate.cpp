class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qR, qD; // create two queues to store the indices of the senators from the two parties
    
        for(int i = 0 ; i < n ; i++) {
            if(senate[i] == 'R') 
                qR.push(i);
            else qD.push(i);
        }
    
        while(!qR.empty() && !qD.empty()){ // continue the round-based procedure until one of the parties runs out of senators
            int r = qR.front(), d = qD.front();
            qR.pop();
            qD.pop();
            if(r < d) 
                qR.push(r + n); // if the Radiant senator has a smaller index than the Dire senator, add n to its index and put it at the end of the Radiant queue
            else 
                qD.push(d + n); // if the Dire senator has a smaller index than the Radiant senator, add n to its index and put it at the end of the Dire queue
        }
    
        return qR.size() > qD.size() ? "Radiant" : "Dire"; // the party with more senators remaining wins
    }
};