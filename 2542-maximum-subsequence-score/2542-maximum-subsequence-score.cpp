class Solution {
    struct Pair {
        int first;
        int second;
        Pair(int f, int s) : first(f), second(s) {}
    };

    struct ComparePair {
        bool operator()(const Pair& a, const Pair& b) {
            return a.second < b.second;
        }
    };
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<Pair> pairs;
        pairs.reserve(n);

        for(int i = 0; i < n; ++i) {
            pairs.push_back(Pair(nums1[i], nums2[i]));
        }

        sort(pairs.begin(), pairs.end(), [](const Pair& a, const Pair& b) {
            return a.second > b.second;
        });

        priority_queue<int, vector<int>, greater<int>> topKHeap;
        long topKSum = 0;

        for(int i = 0; i < k; ++i) {
            topKSum += pairs[i].first;
            topKHeap.push(pairs[i].first);
        }

        long answer = topKSum * pairs[k - 1].second;
        for(int i = k; i < n; ++i) {
            topKSum += pairs[i].first - topKHeap.top();
            topKHeap.pop();
            topKHeap.push(pairs[i].first);
            answer = max(answer, topKSum * pairs[i].second);
        }

        return answer;
    }
};