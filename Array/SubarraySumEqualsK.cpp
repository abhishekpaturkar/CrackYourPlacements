class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        m[0] = 1;
        int preSum = 0, count = 0;
        // Kadane Algorithm
        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i];
            int remove = preSum - k;
            count += m[remove];
            m[preSum] += 1;
        }
        return count;
    }
};