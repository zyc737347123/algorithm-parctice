/********************* 
#3. 数组中重复的数字 
**********************/

bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length == 0)
    {
        return false; 
    }

    for(int i = 0;i < length; i++)
    {   
        // 防止下面数组越界
        if(numbers[i] < 0 || numbers[i] > length - 1)
        {
            return false;
        }
    }

    for(int i = 0; i < length ; i++)
    {
        // 一定会结束循环，两种情况，跳出循环，第一种数组没有重复数字，就会满足numbers[i] == i
        // 第二种数组有重复数字，就会满足numbers[i] == numbers[numbers[i]]
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }
}