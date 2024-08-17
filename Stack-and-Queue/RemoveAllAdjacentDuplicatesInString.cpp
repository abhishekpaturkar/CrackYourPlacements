class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && st.top().second == k)
            {
                st.pop();
            }
            if (!st.empty() && st.top().first == s[i])
            {
                st.top().second++;
            }
            else
                st.push({s[i], 1});
        }
        if (st.top().second == k)
            st.pop();
        string str = "";
        while (!st.empty())
        {
            for (int i = 0; i < st.top().second; i++)
            {
                str += st.top().first;
            }
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};