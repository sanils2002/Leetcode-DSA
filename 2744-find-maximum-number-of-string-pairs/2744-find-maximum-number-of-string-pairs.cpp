class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> count;
        int pairs = 0;

        for(const string& word : words) {
            string reversed = word;
            reverse(reversed.begin(), reversed.end());

            if(count.find(reversed) != count.end()) {
                pairs++;
                count[reversed]--;
                if(count[reversed] == 0) {
                    count.erase(reversed);
                }
            } 
            else {
                count[word]++;
            }
        }

        return pairs;
    }
};