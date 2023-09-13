/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ind = -1;
        int len = 0;
        // bool dp[n+1][n] = {false};
        vector<vector<bool>> dp(n + 1,vector<bool>(n, false));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                if(s[j] == s[j+i-1]){ 
                    if(i-2<1 ? true : dp[i-2][j+1]){
                        dp[i][j] = true;
                        if(i>len){
                            ind = j;
                            len = i;
                        }
                    }
                }
            }
        }
        return s.substr(ind,len);
    }
};
// @lc code=end

