/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start

//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                TreeNode *right_subtree = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
                if (root->left)
                {
                    if (right_subtree)
                    {
                        TreeNode *temp = right_subtree;
                        while (temp->right)
                            temp = temp->right;
                        temp->right = root->left;
                        root->left = right_subtree;
                    }
                }
                else
                    root->left = right_subtree;
            }
            if (!curr->right)
            {
                curr->right = root->left;
                root->left = nullptr;
            }
            curr = curr->right;
        }
        return;
    }
};
// @lc code=end
