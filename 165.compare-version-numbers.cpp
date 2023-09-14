/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {

private : 



vector<int> splitByDot(string &str){
    vector<int> ans;
    int n = str.size();
    int i = 0;
    while(i<n){
        string temp;
        while(i<n && str[i]=='0'){
            i++;
        }
        while(i<n && str[i]!='.'){
            temp.push_back(str[i++]);
        }
        if(temp.size()==0)temp.push_back('0');
        ans.push_back(stoi(temp));
        i++;
    }
    while(ans.size()>0 && ans.back()==0)ans.pop_back();
    return ans;
}

public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitByDot(version1);
        vector<int> v2 = splitByDot(version2);
        int n = v1.size();
        int m = v2.size();
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(v1[i]<v2[j])return -1;
            else if(v1[i]>v2[j])return 1;
            i++;
            j++;
        }
        if(i<n)return 1;
        if(j<m)return -1;
        return 0;
    }
};
// @lc code=end

