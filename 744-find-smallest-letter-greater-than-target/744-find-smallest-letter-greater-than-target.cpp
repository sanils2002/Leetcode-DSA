class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st = 0, en = letters.size();
        while(st < en) {
            int mid = st + (en - st) / 2;
            if(target >= letters[mid])
                st = mid + 1;
            else 
                en = mid;
        }
        
        return letters[st % letters.size()];
    }
};