/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start

// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        vector<bool> visited(101, false);
        map<int , Node*> m;
        queue<Node*> q;
        q.push(node);
        while(q.size()){
            Node* temp = q.front();
            q.pop();
            m[temp->val] = new Node(temp->val);
            for(Node* nei : temp->neighbors){
                if(!visited[nei->val]){
                    q.push(nei);
                    visited[nei->val] = true;
                }
            }
        }
        q.push(node);
        visited = vector<bool> (101, false);
        while(q.size()){
            Node* temp = q.front();
            q.pop();
            if(visited[temp->val])continue;
            visited[temp->val] = true;
            for(Node* nei : temp->neighbors){
                m[temp->val]->neighbors.push_back(m[nei->val]);
                q.push(nei);
            }
        }
        return m[node->val];
    }
};
// @lc code=end

