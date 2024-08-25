class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;
        // if(dp[i][j]!=-1)return dp[i][j];
        int up = solve(i - 1, j, grid, dp);
        int left = solve(i, j - 1, grid, dp);
        // return dp[i][j]=grid[i][j]+min(up,left);
        return grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        // recursion
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m, 0);
        // return solve(n-1,m-1,grid,dp);

        // Tabulation
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {

                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                        up += dp[j];
                    else
                        up += 1e9;
                    int left = grid[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;
                    temp[j] = min(up, left);
                }
            }
            dp = temp;
        }
        return dp[m - 1];
    }
};