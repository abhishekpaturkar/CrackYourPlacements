class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
            dp[0][j] = stoi(string(1, matrix[0][j]));
        for (int i = 0; i < n; i++)
            dp[i][0] = stoi(string(1, matrix[i][0]));

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == '0')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
            }
        }

        int maxSide = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxSide = max(maxSide, dp[i][j]);
            }
        }

        return maxSide * maxSide;
    }
};