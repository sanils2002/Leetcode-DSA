class Solution {
private:
    string sortedDigits(int n) {
        string digits = to_string(n);
        sort(digits.begin(), digits.end());
        return digits;
    }
public:
    bool reorderedPowerOf2(int n) {
        string number = sortedDigits(n);

        for (int idx = 0 ; idx < 30 ; ++idx) {
            string powerOfTwo = sortedDigits(1 << idx);
            if (number == powerOfTwo)
                return true;
        }

        return false;
    }
};