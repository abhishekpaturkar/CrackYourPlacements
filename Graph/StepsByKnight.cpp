class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
        int x = KnightPos[0] - 1, y = KnightPos[1] - 1;

        if (x == tx && y == ty)
            return 0;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({x, y});
        visited[x][y] = false;
        int count = 0;
        int dx[] = {1, 2, -1, -2, 1, -1, 2, -2};
        int dy[] = {2, 1, -2, -1, -2, 2, -1, 1};

        while (!q.empty())
        {
            int size = q.size();
            count++;
            while (size)
            {
                pair<int, int> p = q.front();
                q.pop();
                int xx = p.first;
                int yy = p.second;
                for (int i = 0; i < 8; i++)
                {
                    int newx = xx + dx[i];
                    int newy = yy + dy[i];
                    if (newx == tx && newy == ty)
                        return count;
                    if (newx >= 0 && newx < n && newy >= 0 && newy < n && visited[newx][newy] == false)
                    {
                        q.push({newx, newy});
                        visited[newx][newy] = true;
                    }
                }
                size--;
            }
        }
        return count;
    }
};