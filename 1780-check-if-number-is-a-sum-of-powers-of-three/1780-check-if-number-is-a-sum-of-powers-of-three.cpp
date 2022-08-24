class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> v;
        int temp = 1;
        for(int idx = 0 ; ; idx++) {
            v.push_back(temp);
            temp *= 3;
            if(temp > 10000000)
                break;
        }
        
        int key = n;
        for(int idx = v.size() - 1; idx >= 0 ; idx--) {
            if(key >= v[idx])
                key -= v[idx];
            if(0 == key)
                return true;
        }
        
        return false;
    }
};