class Solution {
private:
    bool static cmp(vector<int> &a,vector<int> &b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int countWays(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        stack<vector<int>> s;
        // int mn;
        s.push(v[0]);
        for(int i = 1; i < v.size(); i++){
            while(!s.empty() && s.top()[1] >= v[i][0]){
                s.pop();
            }
            
            if(s.empty()){
                s.push(v[i]);
            }
            else if(s.top()[1] < v[i][0]){
                s.push(v[i]);
            }
            else{
                s.top()[1] = v[i][1];
            }
            
        }
        
        int mod = 1e9+7;
        int ans = 1;
        while(s.size()){
            ans = (ans*2) % mod;
            s.pop();
        }
        
        return ans;
    }
};