class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxCount = 0;
        int count = 0;
    
        // count the number of vowels in the first k characters
        for(int i = 0; i < k; i++) {
            if(vowels.count(s[i])) {
                count++;
            }
        }
    
        maxCount = count;
    
        // slide the window and update the count of vowels
        for(int i = k; i < s.length(); i++) {
            if(vowels.count(s[i - k])) {
                count--;
            }
            if(vowels.count(s[i])) {
                count++;
            }
            maxCount = max(maxCount, count);
        }
    
        return maxCount;
    }
};