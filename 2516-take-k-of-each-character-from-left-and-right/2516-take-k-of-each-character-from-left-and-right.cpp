class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> apcnt(n + 1), bpcnt(n + 1), cpcnt(n + 1);
        for(int i = 1; i <= n; i++) {
            apcnt[i] = apcnt[i - 1];
            bpcnt[i] = bpcnt[i - 1];
            cpcnt[i] = cpcnt[i - 1];
            if(s[i - 1] == 'a')
                apcnt[i] = apcnt[i - 1] + 1;
            else if (s[i - 1] == 'b')
                bpcnt[i] = bpcnt[i - 1] + 1;
            else if (s[i - 1] == 'c')
                cpcnt[i] = cpcnt[i - 1] + 1;
        }

        vector<int> ascnt(n + 1), bscnt(n + 1), cscnt(n + 1);
        for(int i = 1; i <= n; i++) {
            ascnt[i] = ascnt[i - 1];
            bscnt[i] = bscnt[i - 1];
            cscnt[i] = cscnt[i - 1];
            if(s[n - i] == 'a') {
                ascnt[i] = ascnt[i - 1] + 1;
            } 
            else if (s[n - i] == 'b') {
                bscnt[i] = bscnt[i - 1] + 1;
            } 
            else {
                cscnt[i] = cscnt[i - 1] + 1;
            }
        }
        
        if(apcnt[n] < k || bpcnt[n] < k || cpcnt[n] < k)
            return -1;

        int final = INT_MAX;
        for(int left = 0; left < n; left++) {
            int a = max(k - apcnt[left], 0);
            int b = max(k - bpcnt[left], 0);
            int c = max(k - cpcnt[left], 0);

            int righta = lower_bound(ascnt.begin(), ascnt.end(), a) - ascnt.begin();
            int rightb = lower_bound(bscnt.begin(), bscnt.end(), b) - bscnt.begin();
            int rightc = lower_bound(cscnt.begin(), cscnt.end(), c) - cscnt.begin();
            int ans = max(righta, max(rightb, rightc));
            final = min(left + ans, final);
        }
    
        return final;
    }
};