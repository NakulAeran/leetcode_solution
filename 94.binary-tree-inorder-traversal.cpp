/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    // void inorder(TreeNode *root, vector<int> &ans)
    // {
    //     if (root == NULL)
    //         return;
    //     inorder(root->left, ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }

    vector<int> inorderIterative(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stk;
        while (stk.size() || root)
        {
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        return inorderIterative(root);
    }
};
// @lc code=end
