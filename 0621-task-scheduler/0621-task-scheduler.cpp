class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        for(char task : tasks) {
            freq[task]++;
            maxFreq = std::max(maxFreq, freq[task]);
        }
        
        int numMaxFreq = 0;
        for(auto it : freq) {
            if(it.second == maxFreq) {
                numMaxFreq++;
            }
        }
        
        int emptySlots = (maxFreq - 1) * (n - (numMaxFreq - 1));
        int availableTasks = tasks.size() - maxFreq * numMaxFreq;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};