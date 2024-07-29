class Solution
{
public:
    void backtrack(int n, int leftCount, int rightCount, vector<char> &output,
                   vector<string> &result)
    {
        // Base case where count of left and right braces is "n"
        if (leftCount >= n && rightCount >= n)
        {
            // Join the array elements into a string without any separators.
            string outputStr(output.begin(), output.end());
            result.push_back(outputStr);
        }

        // Case where we can still append left braces
        if (leftCount < n)
        {
            output.push_back('(');
            backtrack(n, leftCount + 1, rightCount, output, result);
            output.pop_back();
        }

        // Case where we append right braces if the current count of right braces is
        // less than the count of left braces
        if (rightCount < leftCount)
        {
            output.push_back(')');
            backtrack(n, leftCount, rightCount + 1, output, result);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        vector<char> output;
        backtrack(n, 0, 0, output, result);
        return result;
    }
};