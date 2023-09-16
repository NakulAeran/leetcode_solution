/*
 * @lc app=leetcode id=2800 lang=cpp
 *
 * [2800] Shortest String That Contains Three Strings
 */

// @lc code=start
class Solution
{
public:
    string combine(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        string ans = a;
        int index = 0;
        for (int k = 0; k < n; k++)
        {
            int i = k;
            int j = 0;
            for (; j < m && i < n; j++)
            {
                if (a[i] == b[j])
                {
                    i++;
                }
                else
                    break;
            }
            if (i == n || j == m)
            {
                index = j;
                break;
            }
        }
        for (int k = index; k < m; k++)
        {
            ans.push_back(b[k]);
        }
        return ans;
    }
    bool static cmp(const string lhs, const string rhs)
    {
        return lhs.length() < rhs.length();
    }

    string minimumString(string a, string b, string c)
    {
        string ab = combine(a, b);
        string bc = combine(b, c);
        string ac = combine(a, c);
        string ba = combine(b, a);
        string cb = combine(c, b);
        string ca = combine(c, a);
        vector<string> v;
        v.push_back(combine(ab, c));
        v.push_back(combine(ac, b));
        v.push_back(combine(ba, c));
        v.push_back(combine(bc, a));
        v.push_back(combine(ca, b));
        v.push_back(combine(cb, a));
        v.push_back(combine(c, ab));
        v.push_back(combine(b, ac));
        v.push_back(combine(c, ba));
        v.push_back(combine(a, bc));
        v.push_back(combine(b, ca));
        v.push_back(combine(a, cb));
        sort(v.begin(), v.end());
        sort(v.begin(), v.end(), cmp);
        return v[0];
    }
};
// @lc code=end
