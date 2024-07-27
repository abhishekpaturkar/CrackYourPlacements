class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> ans(board);
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ableToLive = 0;
                for (int k = 0; k < 8; k++)
                {
                    if (((i + dir[k][0] >= 0) && (i + dir[k][0] < n)) &&
                        (j + dir[k][1] >= 0) && (j + dir[k][1] < m))
                    {

                        int row = i + dir[k][0], col = j + dir[k][1];
                        if (ans[row][col] == 1)
                            ableToLive++;
                    }
                }
                if (ans[i][j] == 1 && (ableToLive < 2 || ableToLive > 3))
                    board[i][j] = 0;

                else if (ans[i][j] == 0 && ableToLive == 3)
                    board[i][j] = 1;
                else if (ans[i][j] == 1 && (ableToLive == 2 || ableToLive == 3))
                    board[i][j] = 1;
            }
        }
    }
};