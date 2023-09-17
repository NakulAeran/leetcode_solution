/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *helper(TreeNode *root, pair<TreeNode *, TreeNode *> &temp, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        pair<TreeNode *, TreeNode *> temp2 = {NULL, NULL};
        TreeNode *left = helper(root->left, temp2, p, q);
        if (!temp.first)
            temp.first = temp2.first;
        if (!temp.second)
            temp.second = temp2.second;
        if (temp2.first && temp2.second)
            return left;
        temp2 = {NULL, NULL};
        TreeNode *right = helper(root->right, temp2, p, q);
        if (!temp.first)
            temp.first = temp2.first;
        if (!temp.second)
            temp.second = temp2.second;
        if (temp2.first && temp2.second)
            return right;
        if (root == p)
        {
            temp.first = root;
        }
        if (root == q)
        {
            temp.second = root;
        }
        if (temp.first && temp.second)
            return root;
        return NULL;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        pair<TreeNode *, TreeNode *> temp = {NULL, NULL};
        return helper(root, temp, p, q);
    }
};
// @lc code=end
