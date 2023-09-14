class Solution {
private : 

string convert(int count, int prev){
    string temp = to_string(count);
    temp.push_back(prev+'0');
    return temp;
}

public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string s = countAndSay(n-1);
        string ans;
        int m = s.size();
        int prev = s[0]-'0';
        int count = 1;
        for(int i=1;i<m;i++){
            if(s[i]-'0'==prev)count++;
            else{
                ans.append(convert(count, prev));
                prev = s[i] - '0';
                count = 1;
            }
        }
        ans.append(convert(count, prev));
        return ans;
    }
};