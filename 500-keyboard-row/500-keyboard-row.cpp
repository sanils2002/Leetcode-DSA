class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string key1 = "qwertyuiop";
        string key2 = "asdfghjkl";
        string key3 = "zxcvbnm";
        
        vector<string> Amk;
        
        for(string s : words) {
            int pad1 = 0, pad2 = 0, pad3 = 0, flag = 0;
            for(int idx = 0 ;  idx < s.size() ; idx++) {
                if(string::npos != key1.find(s[idx])) {
                    pad1++;
                }
                else if(string::npos != key2.find(s[idx])) {
                    pad2++;
                }
                else if(string::npos != key3.find(s[idx])) {
                    pad3++;
                }
                if((pad1>0 && pad2>0) or (pad2>0 && pad3>0) or (pad1>0 && pad3>0)) {
                    flag = 1;
                    break;
                }
            }
            if(0 == flag) {
                Amk.push_back(s);
            }
        }
        return Amk;
    }
};