class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        while(i < chars.size()) {
            int count = 0;
            char c = chars[i];
            while(i < chars.size() && chars[i] == c) {
                count++;
                i++;
            }
        
            chars[j++] = c;
            if(count == 1) 
                continue;
            string str = to_string(count);
            for(int k = 0; k < str.size(); k++) {
                chars[j++] = str[k];
            }
        }
    
        return j;
    }
};