class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &visited)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }

        // Downwards
        if (i + 1 < n && !visited[i + 1][j] && mat[i + 1][j])
        {
            visited[i][j] = 1;
            solve(i + 1, j, mat, n, ans, move + "D", visited);
            visited[i][j] = 0;
        }

        // leftwards
        if (j - 1 >= 0 && !visited[i][j - 1] && mat[i][j - 1])
        {
            visited[i][j] = 1;
            solve(i, j - 1, mat, n, ans, move + "L", visited);
            visited[i][j] = 0;
        }

        // Rightwards
        if (j + 1 < n && !visited[i][j + 1] && mat[i][j + 1])
        {
            visited[i][j] = 1;
            solve(i, j + 1, mat, n, ans, move + "R", visited);
            visited[i][j] = 0;
        }

        // Upwards
        if (i - 1 >= 0 && !visited[i - 1][j] && mat[i - 1][j])
        {
            visited[i][j] = 1;
            solve(i - 1, j, mat, n, ans, move + "U", visited);
            visited[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Your code goes here
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (mat[0][0] == 1)
        {
            solve(0, 0, mat, n, ans, "", visited);
        }

        return ans;
    }
};