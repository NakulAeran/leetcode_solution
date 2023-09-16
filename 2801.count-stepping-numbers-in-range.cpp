/*
 * @lc app=leetcode id=2801 lang=cpp
 *
 * [2801] Count Stepping Numbers in Range
 */

// @lc code=start

#define mod 1000000007;

class Solution
{
public:
    bool check(string &str1, string &str2)
    {
        int n1 = str1.length(), n2 = str2.length();

        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;

        for (int i = 0; i < n1; i++)
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;

        return false;
    }

    long long helper(string &low, string &curr)
    {
        if (check(low, curr))
            return 0;
        long long ans = 1;
        if (curr[curr.size() - 1] != '9')
        {
            curr.push_back(curr[curr.size() - 1] + 1);
            ans = (ans + helper(low, curr)) % mod;
            curr.pop_back();
        }
        if (curr[curr.size() - 1] != '0')
        {
            curr.push_back(curr[curr.size() - 1] - 1);
            ans = (ans + helper(low, curr)) % mod;
            curr.pop_back();
        }
        return ans;
    }

    int countSteppingNumbers(string low, string high)
    {
        reverse(low.begin(), low.end());
        if (low[0] != 0)
            low[0]--;
        else
        {
            int i = 0;
            while (low[i] == 0)
            {
                low[i] = 9;
                i++;
            }
            low[i]--;
            if (low[i] == '0' && i == low.size() - 1)
                low.pop_back();
        }
        reverse(low.begin(), low.end());
        long long ans = 0;
        long long lo = 0;
        long long hi = 0;
        for (int i = 1; i < 10; i++)
        {
            string temp = to_string(i);
            string temp2 = to_string(i);
            lo = (lo + helper(low, temp)) % mod;
            hi = (hi + helper(high, temp2)) % mod;
        }
        ans = hi - lo;
        return ans % mod;
    }
};
// @lc code=end
