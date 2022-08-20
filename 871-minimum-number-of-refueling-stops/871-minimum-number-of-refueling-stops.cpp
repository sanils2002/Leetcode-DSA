class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int currFuel = startFuel, refuel = 0;
        
        int trav = 0;
        
        priority_queue<int> pq;
        
        while(currFuel < target) {
            while(trav < n and currFuel >= stations[trav][0]) { //at a particular station, currFuel>= position of pump
                pq.push(stations[trav][1]);
                trav++;
            }
            if(pq.empty())
                return -1;
            currFuel += pq.top();              //update currFuel by adding pq.top()
            pq.pop();
            
            refuel++;
        }
        
        return refuel;
    }
};