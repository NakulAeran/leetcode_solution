class Solution
{
public:
    int minOperations(vector<int> &nums, int target)
    {
        int n = nums.size();
        long long sum = 0;
        for (int temp : nums)
            sum += temp;
        if (sum < target)
            return -1;
        sort(nums.begin(), nums.end());
        sum = 0;
        vector<int> arr;
        int i = 0;
        while (sum < target)
        {
            arr.push_back(nums[i]);
            sum += nums[i++];
        }
        int ans = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (target >= arr[i])
            {
                target -= arr[i];
                arr.pop_back();
            }
            else
            {
                long long temp_sum = 0;
                for (int j = 0; j < i; j++)
                    temp_sum += arr[j];
                if (temp_sum >= target)
                {
                    arr.pop_back();
                }
                else
                {
                    arr[i] = arr[i] / 2;
                    if(arr[i]<=target)target -= arr[i];
                    i++;
                    ans++;
                }
            }
            if (target == 0)
                break;
        }
        return ans;
    }
};