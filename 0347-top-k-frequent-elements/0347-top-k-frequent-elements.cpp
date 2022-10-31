class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> v;
        
        for(auto &num : nums)
            mp[num]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto &ip : mp)
            pq.push({ip.second, ip.first});
        
        while(k--) {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};