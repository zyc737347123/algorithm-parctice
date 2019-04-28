/********************* 
#5. 替换空格 
关键思路：不允许新建内存时，考虑从后往前进行操作
**********************/

void ReplaceBlank(char string[], int length)
{
    if(string == nullptr || length <= 0)
    {
        return;
    }

    int oldlen = 0, newlen = 0;

    while (string[oldlen] != '\0')
    {
        if(string[oldlen] == ' ')
            newlen += 2;
        newlen++;
        oldlen++;
    }
    
    if(newlen > length)
        return;

    // 第二个判断条件，可以提前结束循环，当两个数组其中一个已经结束，时间复杂度为O(min(n,m))
    while (oldlen >= 0 && oldlen > newlen)
    {
        if(string[oldlen] == ' ')
        {
            string[newlen--] = '0';
            string[newlen--] = '2';
            string[newlen--] = '%';
        }
        else
        {
            string[newlen--] = string[oldlen];
        }
        oldlen--;
    }

}

/********************* 
#5.1 合并数组, 假设数组A有足够空间
关键思路：不允许新建内存时，考虑从后往前进行操作
**********************/

bool mergeTwo(int a[], int b[], int alen, int blen, int length)
{
    if(a == nullptr || b == nullptr || alen <= 0 || blen <= 0 || length < alen + blen)
    {
        return false;
    }

    int indexOfA = alen - 1;
    int indexOfB = blen - 1;
    int index = alen + blen - 1;

    while (indexOfA >= 0 && indexOfB >= 0)
    {
        if(a[indexOfA] > b[indexOfB])
        {
            a[index++] = a[indexOfA--];
        }
        else
        {
            a[index++] = b[indexOfB--];
        }  
    }
    
    if(indexOfB)
    {
        while (indexOfB)
        {
            a[index++] = b[indexOfB--];
        }
        
    }

}

