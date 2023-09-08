//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void helper(int sum, vector<int> &ans, vector<int> &arr, int i){
        int n = arr.size();
        if(i==n){
            ans.push_back(sum);
            return;
        }
        helper(sum, ans, arr, i+1);
        sum += arr[i];
        helper(sum,ans, arr, i+1);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        // vector<int> temp;
        sort(arr.begin(),arr.end(), greater<int>());
        helper(0, ans, arr, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends