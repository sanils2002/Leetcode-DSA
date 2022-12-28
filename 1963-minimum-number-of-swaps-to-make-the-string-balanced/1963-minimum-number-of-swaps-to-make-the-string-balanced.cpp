class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        
        for(char c : s) {
            if(c == '[')
                stk.push(c);
            if(c == ']' && stk.size() != 0)
                stk.pop();
        }
        
        return (stk.size() + 1) / 2;
    }
};