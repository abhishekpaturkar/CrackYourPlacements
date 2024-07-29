class Solution
{
public:
    vector<string> mp = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    void solve(int c, string &res)
    {
        if (c < 26)
        {
            if (c >= 0)
                res += mp[c];
        }
        else
        {
            solve(c % 26, res);
            c = c / 26;
            c--;
            solve(c, res);
        }
    }

    string convertToTitle(int c)
    {
        c--;
        string res;
        solve(c, res);
        reverse(res.begin(), res.end());
        return res;
    }
};