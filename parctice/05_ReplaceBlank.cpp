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