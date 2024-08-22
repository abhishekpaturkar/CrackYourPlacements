class Solution
{
    int mod = 1e5;

public:
    vector<int> search(string pat, string txt)
    {
        // code here.
        vector<int> ans;
        int txtHash = 0, patHash = 0;
        int n = txt.size();
        int m = pat.size();

        for (int i = 0; i < m; i++)
        {
            txtHash = ((txt[i] - 'a') + txtHash) % mod;
            patHash = ((pat[i] - 'a') + patHash) % mod;
        }

        if (txtHash == patHash)
        {
            if (txt.substr(0, m) == pat)
                ans.push_back(1);
        }

        for (int i = m, j = 0; i < txt.size(); i++, j++)
        {
            txtHash = (txtHash - txt[j]) % mod;
            txtHash = (txtHash + txt[i]) % mod;

            if (txtHash == patHash)
            {
                if (txt.substr(j + 1, m) == pat)
                    ans.push_back(j + 2);
            }
        }
        return ans;
    }
};