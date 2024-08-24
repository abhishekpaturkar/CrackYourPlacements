class Solution
{
public:
    int solve(int n, int cell, unordered_map<int, vector<int>> &mp, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 1;
        if (dp[n][cell] != -1)
            return dp[n][cell];
        int mod = 1e9 + 7;
        int ans = 0;
        for (auto it : mp[cell])
            ans = (ans + solve(n - 1, it, mp, dp)) % mod;
        return dp[n][cell] = ans % mod;
    }

    int knightDialer(int n)
    {
        unordered_map<int, vector<int>> mp;
        mp[0] = {4, 6};
        mp[1] = {6, 8};
        mp[2] = {7, 9};
        mp[3] = {4, 8};
        mp[4] = {0, 3, 9};
        mp[6] = {0, 1, 7};
        mp[7] = {2, 6};
        mp[8] = {1, 3};
        mp[9] = {2, 4};
        int mod = 1e9 + 7;
        if (n == 1)
            return 10;
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(10, -1));
        for (int i = 0; i <= 9; i++)
        {
            if (i == 5)
                continue;
            else
                res = (res + solve(n - 1, i, mp, dp)) % mod;
        }
        return res;
    }
};