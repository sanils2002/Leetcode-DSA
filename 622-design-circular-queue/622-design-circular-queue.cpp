class MyCircularQueue {
public:
    vector<int> cq;
    int q_size = 0;
    MyCircularQueue(int k) {
        q_size = k;
    }
    
    bool enQueue(int value) {
        if(q_size == cq.size())
            return false;
        cq.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(0 == cq.size())
            return false;
        cq.erase(cq.begin());
        return true;
    }
    
    int Front() {
        if(0 == cq.size())
            return -1;
        int x = cq[0];
        return x;
    }
    
    int Rear() {
        if(0 == cq.size())
            return -1;
        int x = cq.back();
        return x;
    }
    
    bool isEmpty() {
        if(0 == cq.size())
            return true;
        return false;
    }
    
    bool isFull() {
        if(q_size == cq.size())
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */