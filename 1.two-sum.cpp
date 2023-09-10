/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> arr = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> ans;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                break;
            }
            if (nums[i] + nums[j] > target)
                j--;
            else
                i++;
        }
        vector<int> new_ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == ans[0])
            {
                new_ans.push_back(i);
            }
            else if (arr[i] == ans[1])
            {
                new_ans.push_back(i);
            }
        }
        return new_ans;
    }
};
// @lc code=end
