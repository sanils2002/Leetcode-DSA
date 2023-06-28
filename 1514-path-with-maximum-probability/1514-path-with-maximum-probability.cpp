class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        map<int, vector<pair<int, double>>> graph;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph[u].push_back(make_pair(v, pathProb));
            graph[v].push_back(make_pair(u, pathProb));
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
        pq.push(make_pair(1.0, start));
    
        while(!pq.empty()) {
            pair<double, int> cur = pq.top();
            pq.pop();
        
            double curProb = cur.first;
            int curNode = cur.second;
        
            if(curNode == end) {
                return curProb;
            }
        
            for(pair<int, double> nxt : graph[curNode]) {
                int nxtNode = nxt.first;
                double pathProb = nxt.second;
            
                if(curProb * pathProb > maxProb[nxtNode]) {
                    maxProb[nxtNode] = curProb * pathProb;
                    pq.push(make_pair(maxProb[nxtNode], nxtNode));
                }
            }
        }
    
        return 0.0;
    }
};