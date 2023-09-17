class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        long long  maxWidth = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 1}); // or root,0 here

        while (!q.empty())
        {
            int levelSize = q.size();

            long long startPosition = q.front().second;
            long long endPosition = q.back().second;

            maxWidth = max(maxWidth, endPosition - startPosition + 1);

            for (int i = 0; i < levelSize; ++i)
            {
                pair<TreeNode *, long long> p = q.front();
                q.pop();

                TreeNode *node = p.first;
                long long position = p.second;
                long long offsettedPosition = position - startPosition; // we subtract startPosition as otherwise it
                                                                  // was overflowing the 2*position below

                if (node->left)
                    q.push({node->left, 2 * offsettedPosition}); // or 2 * idx + 1
                if (node->right)
                    q.push({node->right, 2 * offsettedPosition + 1}); // or 2* idx + 2
            }
        }
        return maxWidth;
    }
};