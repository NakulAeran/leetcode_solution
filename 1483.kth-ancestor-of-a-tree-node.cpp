/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor
{

private:
    vector<vector<int>> dp;
    vector<int> parent;


public:
    TreeAncestor(int n, vector<int> &parent)
    {
        this->parent = parent;
        dp.resize(n, vector<int>(17, -1));
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = parent[i];
            if (parent[i] != -1)
                adj[parent[i]].push_back(i);
        }

        vector<int> temp;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int pop_element = q.front();
            q.pop();
            temp.push_back(pop_element);
            for(int i : adj[pop_element])q.push(i);
        }

        for (int i : temp)
        {
            for (int j = 1; j < 17; j++)
            {
                if (dp[i][j - 1] == -1)
                    break;
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 16; i >= 0; i--)
        {
            if (k & 1 << i)
            {
                if (dp[node][i] == -1)
                    return -1;
                node = dp[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end
