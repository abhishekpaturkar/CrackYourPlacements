class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        if (m == 0 || n == 0)
            return 0;

        sort(a.begin(), a.end());

        if (n < m)
            return -1;

        int maxDiff = INT_MAX;
        for (int i = 0; i + m - 1 < a.size(); i++)
        {
            int diff = a[i + m - 1] - a[i];
            maxDiff = min(maxDiff, diff);
        }
        return maxDiff;
    }
};