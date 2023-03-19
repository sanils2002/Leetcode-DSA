class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> v;
        while(n > 0) {
            int x = n % 2;
            v.push_back(x);
            n /= 2;
        }
        // reverse(v.begin(), v.end());
        int odd = 0, even = 0;
        for(int i = 0 ; i < v.size() ; i++) {
            if(i%2 and v[i] == 1)
                odd++;
            else if(i%2 == 0 and v[i] == 1)
                even++;
        }
        vector<int> ans;
        ans.push_back(even);
        ans.push_back(odd);
        
        return ans;
    }
};