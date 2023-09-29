/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
// class Solution
// {
// public:
//     bool dfs(vector<bool> &visited, set<int> &s, vector<vector<int>> &adj, int i)
//     {
//         if (s.find(i) != s.end())
//             return true;
//         if (visited[i])
//             return false;
//         s.insert(i);
//         visited[i] = true;
//         for(int &temp : adj[i]){
//             if(dfs(visited, s, adj, temp))return true;
//         }
//         s.erase(i);
//         return false;
//     }

//     bool canFinish(int numCourses, vector<vector<int>> &pre)
//     {
//         vector<vector<int>> adj(numCourses);
//         for (vector<int> &temp : pre)
//         {
//             adj[temp[0]].push_back(temp[1]);
//         }
//         vector<bool> visited(numCourses, false);
//         for (int i = 0; i < numCourses; i++)
//         {
//             if (!visited[i])
//             {
//                 set<int> s;
//                 if (dfs(visited, s, adj, i))
//                     return false;
//             }
//         }
//         return true;
//     }
// };

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &pre)
    {
        vector<vector<int>> adj(numCourses);
        for (vector<int> &temp : pre)
        {
            adj[temp[0]].push_back(temp[1]);
        }
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                queue<pair<unordered_set<int>, int>> q;
                unordered_set<int> s;
                s.insert(i);
                q.push({s, i});
                while (q.size())
                {
                    unordered_set<int> &temp = q.front().first;
                    int ele = q.front().second;
                    q.pop();
                    if (visited[ele])
                        continue;
                    visited[ele] = true;
                    for (int &t : adj[ele])
                    {
                        if (temp.find(t) != temp.end())
                            return false;
                        temp.insert(t);
                        q.push({temp, t});
                        temp.erase(t);
                    }
                }
            }
        }
        return true;
    }
};
