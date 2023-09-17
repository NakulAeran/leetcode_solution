/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int n = q.size();
            map<int, vector<int>> temp;
            for(int i = 0; i < n; i++) {
                auto curr = q.front();
                q.pop();
                temp[curr.second].push_back(curr.first->val);
                if(curr.first->left) q.push({curr.first->left, curr.second-1});
                if(curr.first->right) q.push({curr.first->right, curr.second+1});
            }
            for(auto &i : temp) {
                sort(i.second.begin(), i.second.end());
                for(auto &j : i.second) {
                    m[i.first].push_back(j);
                }
            }
        }
        for(auto &i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
// @lc code=end

