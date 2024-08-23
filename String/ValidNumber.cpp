class Solution
{
public:
    bool isValidInt(string s, int i)
    {
        bool isNo = false;
        if (i < s.length())
        {
            if (s[i] == '-' || s[i] == '+')
            {
                i++;
            }
        }

        while (i < s.length())
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                isNo = true;
            }
            else
            {
                return false;
            }
            i++;
        }
        return isNo;
    }

    bool isNumber(string s)
    {
        bool decimal_used = false;
        bool number_seem = false;

        int i = 0;

        if (s[i] == '-' || s[i] == '+')
        {
            i++;
        }

        while (i < s.length())
        {
            if (s[i] == '+' || s[i] == '-')
            {
                return false;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                if (s[i] == 'e' || s[i] == 'E')
                {
                    if (number_seem && isValidInt(s, i + 1))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '.')
            {
                if (decimal_used)
                {
                    return false;
                }
                else
                {
                    decimal_used = true;
                }
            }
            else
            {
                number_seem = true;
            }
            i++;
        }
        return number_seem;
    }
};