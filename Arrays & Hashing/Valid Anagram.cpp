/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int ans[26] = {0};
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            ans[s[i] - 'a'] += 1;
            ans[t[i] - 'a'] -= 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (ans[i] != 0)
                return false;
        }
        return true;
    }
};