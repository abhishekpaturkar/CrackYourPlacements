class Solution
{
public:
    vector<int> counting(string s)
    {
        vector<int> count(2, 0);
        for (auto &c : s)
        {
            count[c - '0']++;
        }
        return count;
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto &s : strs)
        {
            vector<int> count = counting(s);
            for (int zero = m; zero >= count[0]; zero--)
            {
                for (int one = n; one >= count[1]; one--)
                {
                    dp[zero][one] = max(dp[zero - count[0]][one - count[1]] + 1, dp[zero][one]);
                }
            }
        }

        return dp[m][n];
    }
};