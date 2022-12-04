class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int st = 1, en = skill.size() - 2;
        
        
        int sample = skill[0] + skill[n - 1];
        int chem = skill[0] * skill[n - 1];
        long long sum = chem;
        
        // if(x != sample)
        //     return -1;
        while(st < en) {
            int x = skill[st] + skill[en];
            if(x != sample)
                return -1;
            int y = skill[st] * skill[en];
            sum += y;
            st++;
            en--;
        }
        
        return sum;
    }
};