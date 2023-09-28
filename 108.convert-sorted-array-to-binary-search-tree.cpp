/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *makeTree(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return nullptr;
        int mid = (i + j) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = makeTree(nums, i, mid - 1);
        root->right = makeTree(nums, mid + 1, j);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = makeTree(nums, 0, nums.size() - 1);
        return root;
    }
};
// @lc code=end
