class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int iniColor, int delRow[], int delCol[])
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {

            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor)
            {
                dfs(nRow, nCol, image, ans, newColor, iniColor, delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        dfs(sr, sc, image, ans, color, iniColor, delRow, delCol);
        return ans;
    }
};