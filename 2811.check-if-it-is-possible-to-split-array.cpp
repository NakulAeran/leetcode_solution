/*
 * @lc app=leetcode id=2811 lang=cpp
 *
 * [2811] Check if it is Possible to Split Array
 */

// @lc code=start
class Solution
{
public:
    bool canSplitArray(vector<int> &nums, int m)
    {
        if(nums.size()<3)return true;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] + nums[i + 1] >= m)
                return true;
        return false;
    }
};
// @lc code=end
