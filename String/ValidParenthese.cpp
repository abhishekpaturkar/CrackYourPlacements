class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
            {
                st.push(it);
            }
            else
            {
                if (st.size() == 0)
                    return false;

                char c = st.top();
                st.pop();
                if ((c == '(' && it == ')') || (c == '{' && it == '}') || (c == '[' && it == ']'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};