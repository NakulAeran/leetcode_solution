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
        preStart--;
        root->right = helper(preorder, inorder, preStart, mid + 1, inEnd);
        root->left = helper(preorder, inorder, preStart, inStart, mid);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        int pre = n - 1;
        return helper(postorder, inorder, pre, 0, n);
    }
};