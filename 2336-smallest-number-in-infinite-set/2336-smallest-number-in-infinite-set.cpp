class SmallestInfiniteSet {
private:
    set<int> set_;
public:
    SmallestInfiniteSet() {
        for(int i = 1 ; i<= 1000 ; i++)
            set_.insert(i);
    }
    
    int popSmallest() {
        int smallest = *set_.begin();
        set_.erase(set_.begin());
        return smallest;
    }
    
    void addBack(int num) {
        set_.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */