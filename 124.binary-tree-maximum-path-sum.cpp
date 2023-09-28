/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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



class Solution {
private :   

    int ans;

public:

    int helper(TreeNode *root){
        if(root==nullptr)return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        ans = max(ans, root->val + left + right);
        return max(0, root->val + max(left, right));
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        helper(root);
        return ans;
    }
};
// @lc code=end

