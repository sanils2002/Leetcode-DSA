class RandomizedSet {
public:
    set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()){
            return false;
        }
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){
             s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int l = 0, r = s.size() - 1;
        int idx = l + (rand() % ( r - l + 1 ));
        return *next(s.begin(), idx);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */