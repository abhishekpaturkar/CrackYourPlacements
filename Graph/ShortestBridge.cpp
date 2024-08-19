/*First we have used DFS to compute one island in the graph*/
void dfs(vector<vector<int>> &grid, vector<vector<int>> &visit, int row, int col, int n, int m,
         queue<pair<int, pair<int, int>>> &q)
{
    if (visit[row][col] == 0)
    {
        visit[row][col] = 1;
        // We have stored all the ones of the current island in a queue
        q.push({0, {row, col}});
        int rownum[] = {-1, 0, 1, 0};
        int colnum[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + rownum[i];
            int ncol = col + colnum[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 &&
                visit[nrow][ncol] == 0)
            {
                dfs(grid, visit, nrow, ncol, n, m, q);
            }
        }
    }
}
int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    int count = 0;
    vector<vector<int>> visit(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visit[i][j] == 0 && count < 1)
            {
                dfs(grid, visit, i, j, n, m, q);
                count++;
            }
        }
    }
    int ans = INT_MAX;
    /*Now we will use BFS to move from each one of the previous island to nearest
    onr of the next island. */
    while (!q.empty())
    {
        int row = q.front().second.first;
        int col = q.front().second.second;
        int dist = q.front().first;
        q.pop();
        int rownum[] = {-1, 0, 1, 0};
        int colnum[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + rownum[i];
            int ncol = col + colnum[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 &&
                visit[nrow][ncol] == 0)
            {
                visit[nrow][ncol] = 1;
                q.push({dist + 1, {nrow, ncol}});
            }
            else if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && visit[nrow][ncol] == 0)
            {
                // As soon as we encounter a 1 of next island we find min of ans and that
                // distance. The minimun distance that is taken from the 1 of the original
                // island will get stored in the answer
                ans = min(ans, dist);
            }
        }
    }
    return ans;
}