class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, int> mp;
        for(int idx = 0 ; idx < words.size() ; idx++) {
            vector<int> diff;
            for(int jdx = 1 ; jdx < words[0].size() ; jdx++)
                diff.push_back(words[idx][jdx] - words[idx][jdx - 1]);
            mp[diff]++;
        }
        
        vector<int> v;
        for(auto &ip : mp) {
            if(1 == ip.second)
                v = ip.first;
        }
        
        for(int idx = 0 ; idx < words.size() ; idx++) {
            vector<int> temp;
            for(int jdx = 1 ; jdx < words[0].size() ; jdx++)
                temp.push_back(words[idx][jdx] - words[idx][jdx - 1]);
            if(temp == v)
               return(words[idx]);
        }
        return(words[0]);

    }
};