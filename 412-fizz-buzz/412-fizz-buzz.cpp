class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> naive;
        
        for(int idx = 1 ; idx <= n ; idx++) {
            if(0 == idx % 3 and 0 == idx % 5)
                naive.push_back("FizzBuzz");
            else if(0 == idx % 3)
                naive.push_back("Fizz");
            else if(0 == idx % 5)
                naive.push_back("Buzz");
            else
                naive.push_back(to_string(idx));
        }
        
        return naive;
    }
};