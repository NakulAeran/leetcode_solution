

class Solution
{
public:
    long long maximumSum(vector<int> &nums)
    {

        int n = 1000;                     // Calculate squares from 1 to 10^3
        vector<long long> squares(n + 1); // Using a vector to store the squares
        for (int i = 1; i <= n; ++i)
        {
            squares[i] = i*i;
        }
        int nu = nums.size();
        long long ans = 0;
        for (int i = 1; i <= nu; i++)
        {
            long long sum = 0;
            for(int j=1;j<n;j++){
                if(i*squares[j]>nu) break;
                sum += nums[i*squares[j]-1];
            }
            ans = max(sum,ans);
        }

        return ans;
    }
};