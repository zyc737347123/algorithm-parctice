/********************* 
#3. 数组中重复的数字 
**********************/

// 3.1 可以更改数组
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

    // 每个数字最多交换两次，就会到对应的位置
    for(int i = 0; i < length ; i++)
    {
        // 一定会结束循环，两种情况，跳出循环，第一种数组没有重复数字，就会满足numbers[i] == i
        // 第二种数组有重复数字，就会满足numbers[i] == numbers[numbers[i]]
        while(numbers[i] != i)
        {
            // 保证了一定会跳出循环
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            // 保证了一定会跳出循环
            numbers[tmp] = tmp;
        }
    }
}


// 3.2 不可以更改数组, 示例代码有问题(没有看清楚题目，题目的条件变了，示例代码没有错，又犯低级错误了)
int countRange(const int* numbers, int length, int start, int end)
{
    if(numbers == nullptr || length <= 0)
    {
        return 0;
    }

    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] >= start && numbers[i] <= end)
        {
            count++;
        }
    }

    return count;
}



int getDuplication(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
    {
        return -1;
    }

    // 因为数组范围是1~n
    int start = 1; 
    int end = length - 1;

    while (end>=start)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        if(end == start)
        {
            if (count > 1)
                return start;
            else
                // count == 0 or count == 1
                break;
        }

        if(count > (middle - start + 1))
        {
            end = middle; // 重复数字在 start ~ middle
        }
        else if (count == (middle - start + 1))
        {
            // 原来的做法，不能保证重复数字不在 start ~ middle，但可以保证重复数字在 middle + 1 ~ end，这是可以根据题目证明出来的
            
            // 原来的做法，直接将这种情况当成 重复数字在 middle + 1 ~ end， 有问题

            int check_middle = ((middle - start) >> 1) + start;
            int check_count = countRange(numbers, length, start, check_middle);

            if(check_count == (check_middle - start + 1))
            {
                // 表示 start ~ middle 中没有重复数字
                start = middle + 1;
            }
            else
            {
                // 表示 start ~ middle 有重复数字
                end = middle;
            }
            
        } 
        else if (count < (middle - start + 1))
        {
            start = middle + 1; // 重复数字在 middle + 1 ~ end
        }
    }   
    return -1;
}