class Solution {
private:
    bool isPalindrome(string str){
        int left = 0;
        int right = str.size() - 1;
        
        while(left <= right){
            if(str[left] != str[right])
                return false;
            left++;
            right--;
        }
        
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &s : words) {
            if(isPalindrome(s))
                return s;
        }
        
        return "";
    }
};