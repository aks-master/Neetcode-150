/*

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> ump;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            ump[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto entry : ump)
        {
            ans.push_back(entry.second);
        }
        return ans;
    }
};