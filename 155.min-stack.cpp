/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{

private:
    stack<pair<int, int>> stacks;
    stack<pair<int, int>> min_stack;
    int push_number;

public:
    MinStack()
    {
        push_number = 0;
    }

    void push(int val)
    {
        stacks.push({val, push_number});
        if (min_stack.empty() || min_stack.top().first > val)
            min_stack.push({val, push_number});
        push_number++;
    }

    void pop()
    {
        if(stacks.top().second==min_stack.top().second)min_stack.pop();
        stacks.pop();
    }

    int top()
    {
        return stacks.top().first;
    }

    int getMin()
    {
        return min_stack.top().first;
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
// @lc code=end
