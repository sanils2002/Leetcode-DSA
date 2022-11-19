class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, cur, cur2;
        for(auto idx : A) {
            cur2 = {idx};
            for(auto jdx: cur) 
                cur2.insert(idx | jdx);
            for(auto jdx: cur = cur2) 
                res.insert(jdx);
        }
        return res.size();
    }
};