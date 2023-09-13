#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &grid, vector<vector<int>> &distToTheif, int safeDist){
    int n = grid.size();
    queue<pair<int, int>> q;
    if (distToTheif[0][0] < safeDist)
        return false;
    q.push({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    while (!q.empty()){
        int currRow = q.front().first, currCol = q.front().second;
        q.pop();
        if (currRow == n - 1 && currCol == n - 1)
            return true;
        for (int dirIdx = 0; dirIdx < 4; dirIdx++){
            int newRow = currRow + rowDir[dirIdx];
            int newCol = currCol + colDir[dirIdx];
            if (isValid(visited, newRow, newCol)){
                if (distToTheif[newRow][newCol] < safeDist)
                    continue;
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> distToTheif(n, vector<int>(n, -1));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                    distToTheif[i][j] = 0;
                    // visited[i][j] = true;
                }
            }
        }
    int del[] = {-1, 0, 1, 0, -1};
    while (!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (visited[i][j])
            continue;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++){
            int nx = i + del[k];
            int ny = j + del[k + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] != 1){
                distToTheif[nx][ny] = distToTheif[i][j] + 1;
                q.push({nx, ny});
            }
        }
    }
    int lo = 0, hi = n + 1;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        if (check(grid, distToTheif, mid))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo - 1;

}