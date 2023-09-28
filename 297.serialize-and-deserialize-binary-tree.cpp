/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp){
                ans.append("#,");
            }
            else{
                ans.append(to_string(temp->val)+',');
                q.push(temp->left);
                q.push(temp->right);
            }

        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return nullptr;
        stringstream s(data);
        string str;
        getline(s, str,',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")node->left = nullptr;
            else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s, str,',');
            if(str=="#")node->right = nullptr;
            else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

