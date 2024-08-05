class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        map<int, pair<int, int>> mp;
        int n = mat.size(), maxi = 0, mx = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j])
                {

                    mp[j].first++;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (mp[i].first)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (mat[i][j])
                    {

                        mp[i].second = -1;
                        break;
                    }
                }
            }
        }
        for (auto &x : mp)
        {
            if (x.second.second == 0)
            {
                if (x.second.first > maxi)
                {
                    maxi = x.second.first;
                    mx = x.first;
                }
            }
        }
        if (maxi == n - 1)
            return mx;
        return -1;
    }
};