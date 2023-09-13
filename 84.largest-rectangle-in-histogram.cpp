/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
private:

vector<int> nextsmallerElement(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    vector<int> ans(n,n);
    s.push(0);
    int i=1;
    while(i!=n){
        while(!s.empty() && arr[i]<arr[s.top()]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i++);
    }
    return ans;
}

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right_min = nextsmallerElement(heights);
        reverse(heights.begin(),heights.end());
        vector<int> left_min = nextsmallerElement(heights);
        reverse(heights.begin(),heights.end());
        reverse(left_min.begin(),left_min.end());
        for(int i=0;i<n;i++)left_min[i] = n-left_min[i];
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i] *(right_min[i]-left_min[i]) );
        }
        return ans;
    }
};
// @lc code=end

