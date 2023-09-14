/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        s.push(root);
        vector<int> ans;
        while (s.size())
        {
            root = s.top();
            s.pop();
            if (!root)
                continue;
            ans.push_back(root->val);
            s.push(root->left);
            s.push(root->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

