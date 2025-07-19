/*

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        // Min-heap based on frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto &[num, count] : freq)
        {
            pq.push({count, num});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
