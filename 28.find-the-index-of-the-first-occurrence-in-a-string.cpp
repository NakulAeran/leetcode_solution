/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution
{
public:
    vector<int> lpsArray(string str)
    {
        int n = str.size();
        vector<int> lps(n, 0);
        int i = 1;
        int len = 0;
        while (i < n)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle)
    {
        vector<int> lps = lpsArray(needle);
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
            if (j == m)
            {
                return i - m;
            }
        }
        return -1;
    }
};
// @lc code=end
