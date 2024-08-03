class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;

        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                st.push(S[i] - '0');
            }
            else
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                switch (S[i])
                {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
                default:
                    break;
                }
            }
        }
        return st.top();
    }
};