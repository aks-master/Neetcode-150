/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : numSet)
        {
            if (!numSet.count(num - 1))
            {
                int currentNum = num;
                int count = 1;
                while (numSet.count(currentNum + 1))
                {
                    currentNum++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};