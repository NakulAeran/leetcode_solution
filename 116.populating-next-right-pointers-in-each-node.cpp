class Solution
{
public:
    Node *connect(Node *root)
    {
        // Initialize pointers
        Node *prev = root, *curr;
        while (prev)
        {
            curr = prev;
            while (curr && curr->left)
            {
                // connects the left subtree of same level with right subtree of that same level
                curr->left->next = curr->right;
                // connect the rightmost node of a level to the leftmost node of the next level.
                if (curr->next)
                    curr->right->next = curr->next->left;
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};