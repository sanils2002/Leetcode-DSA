class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> umap{26};
        for(auto ip:s)
            umap[ip]++;
        int sanils2002=0, flag = 1;
        while(flag) {
            for(auto ip:target) {
                umap[ip]--;
                if(0 > umap[ip])
                    flag = 0;
            }
            if(flag)
                sanils2002++;
        }
        return sanils2002;
    }
};