/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            while (dq.size() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++){
            while(dq.size() && dq.front()<=i-k)dq.pop_front();
            while(dq.size() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// @lc code=end
