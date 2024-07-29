class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        stack<string> st;

        while (i < s.size() && s[i] == ' ')
        {
            if (s[i] == ' ')
                i++;
        }

        while (j >= 0 && s[j] == ' ')
        {
            if (s[j] == ' ')
                j--;
        }

        while (i <= j)
        {
            string word;
            while (s[i] != ' ' && i <= j)
            {
                word += s[i];
                i++;
            }
            st.push(word);

            while (i <= j && s[i] == ' ')
            {
                i++;
            }
        }

        string ans = "";
        while (!st.empty())
        {
            string top = st.top();
            ans += top;
            st.pop();
            if (!st.empty())
            {
                ans += " ";
            }
        }
        return ans;
    }
};