class Solution {
private:
    static bool cmp(pair<string, int>p1, pair<string, int>p2 ){
          if(p1.second!=p2.second) 
              return p1.second > p2.second; 
           return p1.first < p2.first;
    }
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, vector<pair<string, int>>>mp;
        
        unordered_map<string, long long>mp1;
        for(auto idx = 0 ; idx < ids.size() ; idx++){
            mp[creators[idx]].push_back({ids[idx], views[idx]});
            mp1[creators[idx]] += views[idx];
        }
        
        long long maxi=-1;
        for(auto &ip : mp1){
            maxi= max(maxi, ip.second);
        }
        vector<string>res;
        for(auto &ip : mp1){
            if(ip.second==maxi) 
                res.push_back(ip.first);
        }
        
        vector<vector<string>>res1;
        for(auto &x : res){
            vector<string>v;
            auto temp= mp[x];
            sort(temp.begin(), temp.end(), cmp);
            v.push_back(x);
            v.push_back(temp[0].first);
            res1.push_back(v);
        }
        return res1;
        
    }
};