class Solution
{
public:
    void markIslands(int i, int j, int &r, int &c, vector<vector<char>> &g)
    {
        if (i < 0 || i == r || j < 0 || j == c || g[i][j] == '0')
            return;
        g[i][j] = '0';
        markIslands(i + 1, j, r, c, g);
        markIslands(i, j + 1, r, c, g);
        markIslands(i - 1, j, r, c, g);
        markIslands(i, j - 1, r, c, g);
    }

    int numIslands(vector<vector<char>> &g)
    {
        int r = g.size();
        int c = g[0].size();

        int ans = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (g[i][j] == '1')
                {
                    markIslands(i, j, r, c, g);
                    ans++;
                }
            }
        }

        return ans;
    }
};