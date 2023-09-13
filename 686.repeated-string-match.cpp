/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// // @lc code=start
// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//             int ans = 0;
//             if(b.size()==0)return ans;
//             int i = 0, j=0;
//             char first = b[j];
//             queue<int> q;
//             while(i<a.size()){if(a[i]==first)q.push(i);i++;}
//             while(!q.empty()){
//                 i = q.front();
//                 q.pop();
//                 j = 0;
//                 ans = i==0 ? 0 : 1;
//                 while(j<b.size()){
//                     if(a[i]!=b[j])break;
//                     if(i==0)ans++;
//                     i++;
//                     j++;
//                     i %= a.size();
//                 }
//                 if(j==b.size())return ans;
//             }
//             return -1;
//     }
// };

// #define MOD INT_MAX
// class Solution {
// public:

//     bool isSubstring(string check, string b, int hash_val) {
//         int curr_hash = 0;
//         int n = check.length();
//         int m = b.length();
//         long long  mul = 1;
//         for(int i = 0 ; i < b.length(); i++) {
//             curr_hash = (curr_hash + ((check[i] - 'a'+1)*mul)%MOD)%MOD;
//             mul = (mul*11)%MOD;
//         }
//         mul /= 11;
//         if(curr_hash == hash_val) return 1;
//         for(int i = 1; i <= n-m; i++) {
//             curr_hash -= (check[i-1] - 'a'+1);
//             curr_hash /= 11;
//             curr_hash = (curr_hash + ((check[i+m-1] - 'a'+1)*mul)%MOD)%MOD;
//             if(curr_hash == hash_val)
//                 return 1;
//         }
//         return 0;
//     }

//     int repeatedStringMatch(string a, string b) {
//         int m = a.length(), n = b.length();
//         int hash_val = 0;
//         long long mul = 1;
//         for(char x: b) {
//             hash_val = (hash_val + ((x - 'a'+1)*mul)%MOD)%MOD;
//             mul = (mul*11)%MOD;
//         }
//         string check = "";
//         int count = 0;
//         while(check.size() < b.size()) {
//             count++;
//             check += a;
//         }
//         if(isSubstring(check, b, hash_val)) return count;
//         if(isSubstring(check + a, b, hash_val)) return count+1;
//         return -1;
//     }
// };

class Solution
{

private:
    vector<int> lpss(string &str)
    {
        int i = 1;
        int j = 0;
        int n = str.size();
        vector<int> lps(n, 0);
        while (i < n)
        {
            if (str[i] == str[j])
            {
                j++;
                lps[i] = j;
                i++;
            }
            else
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return lps;
    }

    bool kmp(string a, string b, vector<int> &lps)
    {
        int n = a.size();
        int m = b.size();
        // check weather b is a substring of a.
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] == b[j])
                i++, j++;
            else
            {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return j == m;
    }

public:
    int repeatedStringMatch(string a, string b)
    {
        string check = "";
        int count = 0;
        while (check.size() < b.size())
        {
            count++;
            check += a;
        }
        vector<int> lps = lpss(b);
        if (kmp(check, b, lps))
            return count;
        if (kmp(check + a, b, lps))
            return count + 1;
        return -1;
    }
};

// @lc code=end
