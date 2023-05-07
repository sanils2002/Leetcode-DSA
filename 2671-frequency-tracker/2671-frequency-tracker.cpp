class FrequencyTracker {
private:
    unordered_map<int, int> dataMap;
    unordered_map<int, int> freqMap;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int oldFreq = freqMap[number];
        freqMap[number]++;
        dataMap[oldFreq]--;
        dataMap[freqMap[number]]++;
    }
    
    void deleteOne(int number) {
        if(freqMap.find(number) != freqMap.end() && freqMap[number] > 0) {
            int oldFreq = freqMap[number];
            freqMap[number]--;
            dataMap[oldFreq]--;
            if(freqMap[number] > 0) {
                dataMap[freqMap[number]]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return dataMap.find(frequency) != dataMap.end() && dataMap[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */