/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans;
        int mini = INT_MAX;
        for(int i=0;i<str.size();i++)mini = min(mini, (int)str[i].size());
        for(int i=0;i<mini;i++){
            char temp = str[0][i];
            for(int j=1;j<str.size();j++){
                if(str[j][i]!=temp)return ans;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

