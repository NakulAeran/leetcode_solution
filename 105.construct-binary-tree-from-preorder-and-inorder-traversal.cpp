/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &preStart, int inStart, int inEnd)
    {
        if (inStart == inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int mid;
        for (int i = inStart; i < inEnd; i++)
        {
            if (inorder[i] == preorder[preStart])
            {
                mid = i;
                break;
            }
        }
        preStart++;
        root->left = helper(preorder, inorder, preStart, inStart, mid);
        root->right = helper(preorder, inorder,preStart, mid + 1, inEnd);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        int pre = 0;
        return helper(preorder, inorder, pre, 0, n);
    }
};
// @lc code=end
