class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> fmap, hmap;
        for(int &num : nums)
            fmap[num]++;
        
        for(int &num : nums) {
            if(!fmap[num])
                continue;
            
            fmap[num]--;
            if(hmap[num-1] > 0) {
                hmap[num-1]--;
                hmap[num]++;
            }
            else if(fmap[num+1] and fmap[num+2]) {
                fmap[num+1]--;
                fmap[num+2]--;
                hmap[num+2]++;
            }
            else 
                return false;
        }
        
        return true;
    }
};