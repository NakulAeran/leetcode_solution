// class Solution {
// public:
//     vector<int>rowDir = {-1, 1, 0, 0};
//     vector<int>colDir = {0, 0, -1, 1};
//     bool isValid(vector<vector<bool>>&visited, int i, int j)
//     {
//         if (i < 0 || j < 0 || i == visited.size() || j == visited[0].size() || visited[i][j])
//             return false;
//         return true;
//     }
//     //============================================================================================================
//     bool isSafe(vector<vector<int>>&distToTheif, int safeDist) //check the validity of safenessFactor
//     {
//         int n = distToTheif.size();
//         queue<pair<int, int>>q;
//         if (distToTheif[0][0] < safeDist) return false;
//         q.push({0, 0});
//         vector<vector<bool>>visited(n, vector<bool>(n, false));
//         visited[0][0] = true;
//         while(!q.empty())
//         {
//             int currRow = q.front().first, currCol = q.front().second;
//             q.pop();
//             if (currRow == n - 1 && currCol == n - 1) return true;
//             for (int dirIdx = 0; dirIdx < 4; dirIdx++)
//             {
//                 int newRow = currRow + rowDir[dirIdx];
//                 int newCol = currCol + colDir[dirIdx];
//                 if (isValid(visited, newRow, newCol))
//                 {
//                     if (distToTheif[newRow][newCol] < safeDist) continue;
//                     visited[newRow][newCol] = true;
//                     q.push({newRow, newCol});
//                 }
//             }
//         }
//         return false;
//     }
//     //===========================================================================================================
//     int maximumSafenessFactor(vector<vector<int>>& grid)
//     {
//         int n = grid.size();
//         queue<pair<int, int>>q;
//         vector<vector<bool>>visited(n, vector<bool>(n, false));
//         vector<vector<int>>distToTheif(n, vector<int>(n, -1));
//         //========================================================================
//         //Add all the theives in current queue
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     visited[i][j] = true;
//                     q.push({i, j});
//                 }
//             }
//         }
//         //=============================================================================
//         //BFS to fill the "DistToTheif" 2D array
//         int dist = 0;
//         while(!q.empty())
//         {
//             int size = q.size();
//             while(size--)
//             {
//                 int currRow = q.front().first, currCol = q.front().second;
//                 q.pop();
//                 distToTheif[currRow][currCol] = dist;
//                 for (int dirIdx = 0; dirIdx < 4; dirIdx++)
//                 {
//                     int newRow = currRow + rowDir[dirIdx], newCol = currCol + colDir[dirIdx];
//                     if (!isValid(visited, newRow, newCol)) continue;

//                     visited[newRow][newCol] = true;
//                     q.push({newRow, newCol});
//                 }
//             }
//             dist++;
//         }
//         //==================================================================================
//         //BINARY SEARCH
//         int low = 0, high = INT_MAX;
//         int ans = 0;
//         while(low <= high)
//         {
//             int mid = low + (high - low) / 2;
//             if (isSafe(distToTheif, mid))
//             {
//                 ans = mid;
//                 low = mid + 1;
//             }
//             else high = mid - 1;
//         }
//         //=========================================================================================
//         return ans;

//     }
// };

// class Solution {
// public:
//     int findman(int r, int c, vector<pair<int,int>> &nums){
//         int mini=10000;
//         for(int i=0;i<nums.size();i++){
//             mini=min(mini,abs(r-nums[i].first)+abs(c-nums[i].second));
//         }
//         return mini;
//     }
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         int n=grid.size();
//         vector<pair<int,int>> nums;
//         //store chor ki pos
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1) nums.push_back({i,j});
//             }
//         }
//         priority_queue<pair<int,pair<int,int>>> pq;
//         vector<vector<int>> vis(n,vector<int>(n,0));
//         int del[]={-1,0,1,0,-1};
//         int dist=findman(0,0,nums);
//         pq.push({dist,{0,0}});
//         while(!pq.empty()){
//             int d=pq.top().first;
//             int r=pq.top().second.first;
//             int c=pq.top().second.second;
//             pq.pop();
//             if(r==n-1 and c==n-1) return d;
//             if(d==0) return d;
//             if(vis[r][c]==1) continue;
//             vis[r][c]=1;
//             for(int i=0;i<4;i++){
//                 int nr=r+del[i];
//                 int nc=c+del[i+1];
//                 int nd=d;
//                 if(nr>=0 and nr<n and nc>=0 and nc<n and !vis[nr][nc]){
//                     nd=min(nd,findman(nr,nc,nums));
//                     pq.push({nd,{nr,nc}});
//                 }
//             }
//         }
//         return 0;
//     }
// };

class Solution
{

private:
    bool isSafe(vector<vector<int>> &dist, int mid)
    {
        queue<pair<int, int>> q;
        int n = dist.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if (dist[0][0] < mid)
            return false;
        q.push({0, 0});
        visited[0][0] = true;
        int del[] = {-1, 0, 1, 0, -1};
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i == n - 1 && j == n - 1)
                return true;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + del[k];
                int ny = j + del[k + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && dist[nx][ny] >= mid)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> distToTheif(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    distToTheif[i][j] = 0;
                    // visited[i][j] = true;
                }
            }
        }
        int del[] = {-1, 0, 1, 0, -1};
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (visited[i][j])
                continue;
            visited[i][j] = true;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + del[k];
                int ny = j + del[k + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && distToTheif[nx][ny] == -1)
                {
                    q.push({nx, ny});
                    distToTheif[nx][ny] = distToTheif[i][j] + 1;
                }
            }
        }


        int low = 0;
        int high = INT_MAX;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isSafe(distToTheif, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
