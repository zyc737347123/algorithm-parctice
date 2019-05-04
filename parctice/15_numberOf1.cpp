/********************* 
#15. 数1 
关键思路：位运算
**********************/

int NumberOf1_base(int n)
{
    int count = 0;
    unsigned int flag = 1;
    
    while(flag)
    {
        if(flag & n)
            count++;
        flag = flag << 1;
    }

    return count;
}

int NumberOf1_good(int n)
{
    int count = 0;
    
    while (n)
    {
        count++;
        n = (n - 1) & n;
    }
    
    return count;
}