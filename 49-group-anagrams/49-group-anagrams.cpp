class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans ;
        unordered_map<string ,vector <string>> anagrams_group;
        
        for(string &str : strs) {
            string key = str;
            sort(begin(key), end(key));// sort entire element by ascii values
            anagrams_group[key].push_back(str);// appending the current element to anagrams_group map
        }
        
        for (const auto [_, anagram]:anagrams_group)
            ans.push_back(anagram);
        
        return ans;
    }
};