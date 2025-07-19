/*

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.length();
        string x;
        for (int i = 0; i < len; i++)
        {
            if (isalnum(s[i]))
            {
                x += s[i];
            }
        }
        len = x.length();
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        for (int i = 0; i < len; i++)
        {
            if (x[i] != x[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};