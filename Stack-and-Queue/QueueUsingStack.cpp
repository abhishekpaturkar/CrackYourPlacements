class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int temp;
        while (!s1.empty())
        {
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        s2.pop();
        int last = temp;
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return last;
    }

    int peek()
    {
        int temp;
        while (!s1.empty())
        {
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        int last = temp;
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return last;
    }

    bool empty()
    {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */