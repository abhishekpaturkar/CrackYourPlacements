class Solution
{
public:
    // Function to find the number of islands.
    int dfs(int r, int c, vector<vector<char>> &g, vector<vector<int>> &v)
    {
        if (r < 0 || r >= g.size() || c < 0 || c >= g[0].size() || v[r][c] || g[r][c] != '1')
            return 0;
        v[r][c] = 1;
        for (int dr : {-1, -1, -1, 0, 1, 1, 1, 0})
            for (int dc : {-1, 0, 1, 1, 1, 0, -1, -1})
                dfs(r + dr, c + dc, g, v);
        return 1;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j] && grid[i][j] == '1')
                    count += dfs(i, j, grid, visited);
        return count;
    }
};