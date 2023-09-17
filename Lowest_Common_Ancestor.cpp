#include <bits/stdc++.h>
using namespace std;

class TreeAncestor
{

private:
    vector<vector<int>> dp;
    vector<int> parent;
    vector<int> depth;

public:
    TreeAncestor(int n, vector<vector<int>> &adj)
    {
        dp.resize(n, vector<int>(16, -1));
        parent.resize(n, -1);
        depth.resize(n, 0);
        vector<int> temp;
        queue<int> q;
        q.push(0);
        while (q.size())
        {
            int pop_element = q.front();
            q.pop();
            temp.push_back(pop_element);
            for (int i : adj[pop_element])
            {
                q.push(i);
                parent[i] = pop_element;
                depth[i] = depth[pop_element] + 1;
            }
        }
        for (int i = 0; i < n; i++)
            dp[i][0] = parent[i];
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
        if(k==0)return node;
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

    int lca(int f, int s)
    {
        if (depth[f] < depth[s])
        {
            swap(f, s);
        }
        f = this->getKthAncestor(f, depth[f]-depth[s]);
        int i = 0;
        while(f!=s){
            int first_ancestor = this->getKthAncestor(f,1<<i);
            int second_ancestor = this->getKthAncestor(s,1<<i);
            if(first_ancestor!=second_ancestor){
                i++;
            }
            else if(i==0)return first_ancestor;
            else{
                i--;
                f = this->getKthAncestor(f,1<<i);
                s = this->getKthAncestor(s,1<<i);
                i=0;
            }
        }
        return f;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> temp;
        while (m--)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }
    TreeAncestor sol(n, adj);
    int q;
    cin >> q;
    while (q--)
    {
        int f, s;
        cin >> f >> s;
        cout << sol.lca(f, s) << endl;
    }
}