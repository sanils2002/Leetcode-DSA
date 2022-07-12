class Solution {
public:
    vector<vector<int>> sanils2002;
    
    void backTracking(int ptr, vector<int> &v, vector<int> &bTrkg, int aim) {
        if(0 == aim) {
            sanils2002.push_back(bTrkg);
            return;
        }
        for(int idx = ptr ; idx < v.size() ; idx++) {
            if(idx > ptr && v[idx] == v[idx - 1])
                continue;
            if(aim < v[idx])
                break;
            
            bTrkg.push_back(v[idx]);
            backTracking(idx + 1, v, bTrkg, aim - v[idx]);
            bTrkg.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> bTrkg;
        backTracking(0, candidates, bTrkg, target);
        
        return sanils2002;
    }
};