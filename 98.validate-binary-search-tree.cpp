/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool helper(TreeNode *root, long low, long high)
    {
        if (!root)
            return true;
        if (root->val <= low || root->val >= high)
            return false;
        bool left_subtree = helper(root->left, low, min((long)root->val, high));
        bool right_subtree = helper(root->right, max(low, (long)root->val), high);
        return left_subtree & right_subtree;
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, -1e10, 1e10);
    }
};
// @lc code=end
