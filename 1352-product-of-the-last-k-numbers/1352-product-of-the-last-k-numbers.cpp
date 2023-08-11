class ProductOfNumbers {
private:
    vector<int> A = {1};
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num)
            A.push_back(A.back() * num);
        else
            A = {1};
    }
    
    int getProduct(int k) {
        return k < A.size() ? A.back() / A[A.size() - k - 1]  : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */