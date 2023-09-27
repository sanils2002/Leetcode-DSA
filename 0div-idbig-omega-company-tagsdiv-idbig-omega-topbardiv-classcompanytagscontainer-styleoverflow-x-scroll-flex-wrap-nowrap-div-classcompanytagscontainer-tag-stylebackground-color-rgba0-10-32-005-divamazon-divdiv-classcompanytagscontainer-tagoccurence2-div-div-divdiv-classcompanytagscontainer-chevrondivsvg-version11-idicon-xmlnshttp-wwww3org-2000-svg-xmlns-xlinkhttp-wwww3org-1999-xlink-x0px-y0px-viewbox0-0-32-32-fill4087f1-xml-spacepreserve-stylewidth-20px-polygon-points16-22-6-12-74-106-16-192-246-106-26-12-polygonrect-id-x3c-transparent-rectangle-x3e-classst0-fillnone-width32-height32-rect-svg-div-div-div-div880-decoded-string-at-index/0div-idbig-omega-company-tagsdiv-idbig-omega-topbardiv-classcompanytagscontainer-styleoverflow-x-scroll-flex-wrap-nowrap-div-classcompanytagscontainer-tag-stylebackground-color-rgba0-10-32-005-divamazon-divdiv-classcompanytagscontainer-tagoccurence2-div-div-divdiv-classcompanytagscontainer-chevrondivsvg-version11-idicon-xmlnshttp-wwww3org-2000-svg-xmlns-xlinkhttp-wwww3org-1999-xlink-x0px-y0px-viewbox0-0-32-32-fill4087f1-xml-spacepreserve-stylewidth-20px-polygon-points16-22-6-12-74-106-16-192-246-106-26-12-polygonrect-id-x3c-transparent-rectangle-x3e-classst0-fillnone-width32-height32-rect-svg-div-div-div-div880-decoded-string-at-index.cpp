class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
    
        // Calculate the size of the decoded string
        for(char c : s) {
            if(isdigit(c)) {
                size *= (c - '0');
            } 
            else {
                size++;
            }
        }
    
        // Traverse the string in reverse to find the kth character
        for(int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            k %= size; // Reduce k according to the current size
        
            if(k == 0 && isalpha(c)) {
                string result = "";
                result += c;
                return result;
            }
        
            if(isdigit(c)) {
                size /= (c - '0');
            } 
            else {
                size--;
            }
        }
    
        return ""; // Shouldn't reach here
    }
};