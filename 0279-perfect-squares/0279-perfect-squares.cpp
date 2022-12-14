class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        set<int> vis;
        
        for(int i = 1 ; i * i <= n ; i++) {
            q.push(i * i);
            vis.insert(i * i);
        }
        
        int res = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curr = q.front();
                q.pop();
                if(n == curr)
                    return res;
                
                for(int i = 1 ; i * i <= n ; i++) {
                    int newCurr = curr + i * i;
                    if(newCurr <= n and vis.find(newCurr) == vis.end()) {
                        q.push(newCurr);
                        vis.insert(newCurr);
                    }
                }
            }
            res++;
        }
        
        return res;
    }
};