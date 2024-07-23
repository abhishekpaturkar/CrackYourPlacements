class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool rowZero = false;

        // Determine which rows/cols need to be zero

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if (i > 0)
                    {
                        matrix[i][0] = 0;
                    }
                    else
                    {
                        rowZero = true;
                    }
                }
            }
        }

        // Zero the rows and cols

        // 0ing rows and cols except first
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 0ing first col
        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // 0ing first rows
        if (rowZero == true)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};