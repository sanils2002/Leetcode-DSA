class MyHashSet {
private:
    vector<int> v;
    int size;
public:
    MyHashSet() {
        size = 1e6+1;
        v.resize(size);
    }
    
    void add(int key) {
        v[key] = 1;
    }
    
    void remove(int key) {
        v[key] = 0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */