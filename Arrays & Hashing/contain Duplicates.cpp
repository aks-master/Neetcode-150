/*

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

*/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ump.find(nums[i]) != ump.end())
            {
                return true;
                // found
            }
            else
            {
                ump[nums[i]] = 1;
            }
        }
        return false;
    }
};