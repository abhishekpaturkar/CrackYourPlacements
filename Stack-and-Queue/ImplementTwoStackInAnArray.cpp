class twoStacks
{
public:
    int s[100];
    int top1 = -1;
    int top2 = 100;
    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        s[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        s[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        else
        {
            return s[top1--];
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == 100)
        {
            return -1;
        }
        else
        {
            return s[top2++];
        }
    }
};