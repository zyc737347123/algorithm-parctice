/********************* 
#10. 斐波那契数列 
**********************/

unsigned long Fibonacci(unsigned int n)
{
    unsigned long a1 = 1, a2 = 1;
    int index = 0;
    
    if(n == 0)
    {
        return 0;
    }

    if(n == 1 || n == 2)
    {
        return a1;
    }

    for(index = 3; index <= n; index)
    {
        a2 = a1 + a2;
        a1 = a2;
    }

    return a2;
}