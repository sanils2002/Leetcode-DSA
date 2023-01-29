class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyValue; // key, {value, freq}
    unordered_map<int, list<int>::iterator> keyIter; // key, iterator in freqList
    unordered_map<int, list<int>> freqList; // freq, list of keys
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyValue.find(key) == keyValue.end()) 
            return -1;
        freqList[keyValue[key].second].erase(keyIter[key]);
        keyValue[key].second++;
        freqList[keyValue[key].second].push_back(key);
        keyIter[key] = --freqList[keyValue[key].second].end();
        if(freqList[minFreq].size() == 0) 
            minFreq++;
        return keyValue[key].first;
    }
    
    void put(int key, int value) {
        if(capacity == 0) 
            return;
        if(get(key) != -1) {
            keyValue[key].first = value;
            return;
        }
        if(keyValue.size() == capacity) {
            int lfu = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyValue.erase(lfu);
            keyIter.erase(lfu);
        }
        
        keyValue[key] = {value, 1};
        freqList[1].push_back(key);
        keyIter[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */