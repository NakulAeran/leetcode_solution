/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
// class Solution {
// public:

//     bool helper(TreeNode *left, TreeNode *right){
//         if(left==nullptr && right==nullptr)return true;
//         if(left == nullptr || right == nullptr)return false;
//         if(left->val!=right->val)return false;
//         bool left_bool = helper(left->left, right->right);
//         bool right_bool = helper(left->right, right->left);
//         return left_bool & right_bool;
//     }

//     bool isSymmetric(TreeNode* root) {
//         return helper(root->left, root->right);
//     }
// };

class Solution {
public:


    bool isSymmetric(TreeNode* root) {
        stack<TreeNode *> l;
        stack<TreeNode *> r;
        l.push(root->left);
        r.push(root->right);
        while(l.size() && r.size()){
            TreeNode *le = l.top();
            l.pop();
            TreeNode *ri = r.top();
            r.pop();
            if(le==nullptr && ri==nullptr)continue;
            if(le==nullptr || ri==nullptr)return false;
            if(le->val != ri->val)return false;
            l.push(le->left);
            l.push(le->right);
            r.push(ri->right);
            r.push(ri->left);

        }
        if(l.size() || r.size())return false;
        return true;
    }
};

