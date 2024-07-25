class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0]++;
        // (sum%k+k)%k for converting -ve to +ve
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (m[(sum % k + k) % k] > 0)
            {
                count += m[(sum % k + k) % k];
            }
            m[(sum % k + k) % k]++;
        }
        return count;
    }
};