class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        queue<pair<int, int>> q;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int count = 0;
        q.push({-1, -1});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            if ((x == -1 and y == -1) and q.size() == 1)
            {
                q.pop();
                break;
            }
            else if ((x == -1 and y == -1) and q.size() > 1)
            {
                count++;
                q.pop();
                q.push({-1, -1});
            }
            else
            {

                if (x - 1 >= 0 and grid[x - 1][y] == 1)
                {
                    q.push({x - 1, y});
                    grid[x - 1][y] = 2;
                }
                if (y - 1 >= 0 and grid[x][y - 1] == 1)
                {
                    q.push({x, y - 1});
                    grid[x][y - 1] = 2;
                }
                if (x + 1 < r and grid[x + 1][y] == 1)
                {
                    q.push({x + 1, y});
                    grid[x + 1][y] = 2;
                }
                if (y + 1 < c and grid[x][y + 1] == 1)
                {
                    q.push({x, y + 1});
                    grid[x][y + 1] = 2;
                }
                q.pop();
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return count;
    }
};