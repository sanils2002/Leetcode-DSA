class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> ums;
    int maxfreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        maxfreq = max(maxfreq, ++freq[val]);
        ums[freq[val]].push(val);
    }
    
    int pop() {
        int x = ums[maxfreq].top();
        ums[maxfreq].pop();
        if (!ums[freq[x]--].size()) 
            maxfreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */