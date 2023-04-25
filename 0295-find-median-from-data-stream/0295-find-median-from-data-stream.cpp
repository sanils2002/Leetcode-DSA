class MedianFinder {
private:
    priority_queue<int> maxHeap; // max heap for the smaller half
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // min heap for the larger half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } 
        else {
            minHeap.push(num);
        }
        
        // balance the heaps
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } 
        else if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } 
        else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */