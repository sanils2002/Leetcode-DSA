class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> umap;
        for(int idx = 0 ; idx < list1.size() ; idx++)
            umap[list1[idx]] = idx;
        
        vector<string> interest;
        int max_val = 1e9;
        
        for(int idx = 0 ; idx < list2.size() ; idx++) {
            if(umap.end() != umap.find(list2[idx])) {
                if(max_val > idx + umap[list2[idx]]) {
                    max_val = idx + umap[list2[idx]];
                    interest.clear();
                    interest.push_back(list2[idx]);
                }
                else if(max_val == idx + umap[list2[idx]])
                    interest.push_back(list2[idx]);
            }
        }
        
        return interest;
    }
};