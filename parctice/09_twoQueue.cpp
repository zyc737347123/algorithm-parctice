/********************* 
#9. 用两个栈实现队列 
**********************/

#include <queue>

template <typename T>
class CStack
{
  public:
    CStack(void);
    ~CStack(void);

    void push(const T &node);
    //T& top();
    T pop();

  private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};

template <typename T>
void CStack<T>::push(const T &node)
{
    if (queue2.empty())
    {
        queue1.push(node);
    }
    else
    {
        queue2.push(node);
    }
}

template <typename T>
T CStack<T>::pop()
{
    if (!queue1.empty())
    {
        while (queue1.size() > 1)
        {
            T data = queue1.front();
            queue1.pop();
            queue2.push(data);
        }

        T tail = queue1.front();
        queue1.pop();
        return tail;
    }
    else
    {
        while (queue2.size() > 1)
        {
            T data = queue2.front();
            queue2.pop();
            queue1.push(data);
        }

        T tail = queue2.front();
        queue2.pop();
        return tail; 
    }
    
}
