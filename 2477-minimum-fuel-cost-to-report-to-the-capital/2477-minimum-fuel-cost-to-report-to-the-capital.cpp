class Solution {
typedef long long ll;
map<ll,vector<ll>>mp;
ll sp=0; ll ans=0;
private:
    int check(set<int> &v, int node){
        v.insert(node);
        int st=1;
        for(auto x:mp[node]){
           if(!v.count(x)){
              st+=check(v,x);
              v.insert(x);
           }
        }
        if(0 != node) {
            int need = 0;
            if(0 == st%sp) {
                need = st/sp;
            }
            else{
                need = st/sp+1;
            }
            ans += need;
        }
        
        return st;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        sp=seats;
        for(auto &r : roads) {
            mp[r[0]].push_back(r[1]);
            mp[r[1]].push_back(r[0]);
        }//Node and their leaves
        
        set<int> st;
        check(st, 0);
        return ans;
    }
};