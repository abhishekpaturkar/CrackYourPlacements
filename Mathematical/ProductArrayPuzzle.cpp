class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        vector<long long> ans(n);

        ans[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = ans[i + 1] * nums[i];
        }

        long long prefix = 1;
        for (int i = 0; i < n - 1; i++)
        {
            ans[i] = ans[i + 1] * prefix;
            prefix *= nums[i];
        }

        ans[n - 1] = prefix;

        return ans;
    }
};