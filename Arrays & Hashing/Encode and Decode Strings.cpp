/*

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode


*/

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        // pattern
        //*<len><str>*<len><str>....
        string encoded;
        for (const string &str : strs)
        {
            encoded += "*" + to_string(str.length()) + str;
        }
        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int i = 0;
        while (i < s.length())
        {
            if (s[i] != '*')
            {
                i++;
                continue;
            }
            i++;
            int lenStart = i;
            while (i < s.length() && isdigit(s[i]))
            {
                i++;
            }
            int len = stoi(s.substr(lenStart, i - lenStart));
            string str = s.substr(i, len);
            result.push_back(str);
            i += len;
        }
        return result;
    }
};
