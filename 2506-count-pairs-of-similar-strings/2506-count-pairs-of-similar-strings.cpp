class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<string>v;
        for(string str : words){
            set<char> chars;
            str.erase(
                remove_if(
                    str.begin(), str.end(), [&chars] (char i) {
                        if (chars.count(i)) { return true; }

                        chars.insert(i);
                        return false;
                    }
                ),
                str.end()
            );
            
            sort(str.begin(),str.end());
            v.push_back(str);
        }
        
        int ans = 0;
        for(int i = 0 ; i < v.size() - 1 ; i++){
            for(int j = i + 1 ; j < v.size() ; j++){
                if(v[i] == v[j])
                    ans+= 1;
            }
        }
        
        return ans;
    }
};