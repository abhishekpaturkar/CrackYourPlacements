class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        stack<char> p;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                if (!p.empty())
                {
                    p.pop();
                }
            }
            else
            {
                p.push(t[i]);
            }
        }

        while (!st.empty() && !p.empty())
        {
            if (st.top() != p.top())
            {
                return false;
            }
            st.pop();
            p.pop();
        }

        return st.empty() && p.empty();
    }
};