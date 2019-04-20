/********************* 
#9.1 用两个队列实现栈 
**********************/

#include <stack>

template <typename T>
class CQueue
{
  public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T &node);
    T deleteHead();

  private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T &node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if (!stack2.empty())
    {
        T head = stack2.top();
        stack2.pop();
        return head;
    }
    else
    {
        if (stack1.empty())
        {
            T error;
            return error;
        }

        while (!stack1.empty())
        {
            // need fix, but why?
            //stack2.push(stack1.top());
            //stack1.pop();

            T& data = stack1.top()
            stack1.pop();
            stack2.push(data);
        }
        T head = stack2.top();
        stack2.pop(); 
        return head;
    }
}