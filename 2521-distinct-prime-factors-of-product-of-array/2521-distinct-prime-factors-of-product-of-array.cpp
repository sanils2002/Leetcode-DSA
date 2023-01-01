class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        // set to store the distinct prime factors
        unordered_set<int> distinctPrimes;

        // iterate through the elements of nums
        for (int num : nums)
        {
            int sqr = sqrt(num);

            // find the prime factors of num
            for (int i = 2; i <= sqr; i++)
            {
                if (num % i == 0)
                {
                    distinctPrimes.insert(i);

                    while (num % i == 0)
                    {
                        num /= i;
                    }
                }
            }

            if (num > 1)
            {
                distinctPrimes.insert(num);
            }
        }

        // return the size of the set
        return distinctPrimes.size();
    }
};