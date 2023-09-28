/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode *constructTree(vector<int> &preorder, int i, int j)
    {
        if (i > j)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[i]);
        int req = j + 1;
        int low = i + 1;
        int high = j;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (preorder[mid] > preorder[i])
            {
                req = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        root->left = constructTree(preorder, i + 1, req - 1);
        root->right = constructTree(preorder, req, j);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return constructTree(preorder, 0, preorder.size() - 1);
    }
};
// @lc code=end
