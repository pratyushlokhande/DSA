class MinStack
{
public:
    stack<int> s;
    stack<int> flag;

    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);

        if (flag.empty())
        {
            flag.push(val);
        }
        else
        {
            if (flag.top() < val)
            {
                flag.push(flag.top());
            }
            else
            {
                flag.push(val);
            }
        }
    }

    void pop()
    {
        s.pop();
        flag.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return flag.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */