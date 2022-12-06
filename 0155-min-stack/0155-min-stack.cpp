class MinStack {
public:
    vector<pair<int, int>> vp;
    MinStack() {
        
    }
    
    void push(int val) {
        if(vp.empty()) {
            vp.push_back({val, val});
        }
        else {
            vp.push_back({val, min(vp.back().second, val)});
        }
    }
    
    void pop() {
        vp.pop_back();
    }
    
    int top() {
        return vp.back().first;
    }
    
    int getMin() {
        return vp.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */