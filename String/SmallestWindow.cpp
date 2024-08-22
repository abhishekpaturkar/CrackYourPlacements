class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        // Your code here
        // unordered_map<char,int> mp;
        vector<int> mp(26, 0);
        int n = s.length();
        int m = p.length();
        if (n < m)
            return "-1";
        int l = 0;
        int r = 0;
        int cnt = 0;
        int mini = 1e9;
        int stI = -1;
        for (int i = 0; i < m; i++)
            mp[p[i] - 'a']++;
        while (l < n && r < n)
        {
            if (mp[s[r] - 'a'] > 0)
                cnt++;
            mp[s[r] - 'a']--;
            while (cnt == m)
            {
                if (r - l + 1 < mini)
                {
                    mini = r - l + 1;
                    stI = l;
                }
                mp[s[l] - 'a']++;
                if (mp[s[l] - 'a'] > 0)
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if (stI == -1)
            return "-1";
        string ans = s.substr(stI, mini);
        return ans;
    }
};