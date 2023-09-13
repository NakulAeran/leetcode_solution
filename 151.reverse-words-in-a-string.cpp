d /*
   * @lc app=leetcode id=151 lang=cpp
   *
   * [151] Reverse Words in a String
   */

    // @lc code=start
    class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        int i = 0;
        while (i != s.size())
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            string word;
            while (i < s.size() && s[i] != ' ')
            {
                word.push_back(s[i++]);
            }
            st.push(word);
        }
        string res;
        while (!st.empty())
        {
            res += st.top() + " ";
            st.pop();
        }
        res.pop_back();
        return res;
        // return res.substr(0,res.size()-1);
    }
};
// @lc code=end
