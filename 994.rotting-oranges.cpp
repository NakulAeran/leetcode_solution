/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)if (grid[i][j] == 2)q.push({i, j}); 
        int ans = q.empty() ? 1 : 0;
        while (!q.empty()){
            ans++;
            queue<pair<int, int>> temp = q;
            q = queue<pair<int, int>>();
            while (!temp.empty())
            {
                int x = temp.front().first;
                int y = temp.front().second;
                temp.pop();
                for (int i : {-1,0, 1})
                {
                    for (int j : {-1, 0, 1})
                    {
                        if(abs(i+j)!=1)continue;
                        int nx = x + i;
                        int ny = y + j;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if (grid[nx][ny] == 1)
                        {
                            q.push({nx, ny});
                            grid[nx][ny] = 2;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return ans-1;
    }
};
// @lc code=end
