/********************* 
#14. 剪绳子 
关键思路：动态递归，贪婪法
**********************/

#include <math.h>

int maxCut_Dy(int length)
{
    if(length <= 1)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int *cutmax = new int[length + 1];
    int max = 0;

    cutmax[0] = 0;
    cutmax[1] = 1;
    cutmax[2] = 2;
    cutmax[3] = 3;

    for(int i = 4; i <= length; i++)
    {
        max = 0;
        for(int j = 1; j <= i/2; j++)
        {
            int curmax = cutmax[i] * cutmax[i - j];
            if(curmax > max)
                max = curmax;
        }
        cutmax[i] = max;
    }

    max = cutmax[length];
    delete[] cutmax;

    return max;
}

int maxCut_Greeddy(int length)
{
    if(length <= 1)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int timesOf3 = length / 3;

    if(length - timesOf3 * 3 == 1)
        timesOf3--;
    
    int timesOf2 = (length - timesOf3 * 3) / 2;

    return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}