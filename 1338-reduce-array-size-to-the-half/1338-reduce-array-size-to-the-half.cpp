class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> umap;
        for(auto &ip : arr)
            umap[ip]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto &ip : umap)
            pq.push({ip.second, ip.first});
        
        int cnt = 0, sz = 0;
        while(!pq.empty()) {
            int fi = pq.top().first, se = pq.top().second;
            cnt++, sz += fi;
            if(sz >= arr.size() / 2)
                return cnt;
            pq.pop();
        }
        
        return cnt;
    }
};