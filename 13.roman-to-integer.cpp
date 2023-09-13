/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string str) {
        int n = 0;
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        stack<int> s;
        for(int i=0;i<str.size();i++){
            int curr_value = m[str[i]];
            if(!s.empty() && curr_value>s.top()){
                curr_value -= 2 * s.top();
            }
            s.push(curr_value);
        }
        while(!s.empty()){
            n += s.top();
            s.pop();
        }
        return n;
    }
};
// @lc code=end

