/********************* 
#11.0  分区函数，按升序分区 
**********************/

int RandomInRange(int start, int end)
{
    return (start + end) / end;
}

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Parttion(int data[], int start, int end)
{
    if(data == nullptr || start < 0 || end < 0 || end < start)
    {
        return -1;
    }

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;

    for(index = start; index < end; index++)
    {
        if(data[index] < data[end])
        {
            small++;
            if(small != index)
            {
                // 在small和index之间有比data[end]大的数字
                Swap(&data[small], &data[index]);
            }
        }
    }

    small++;
    Swap(&data[small], &data[end]);

    return small;
}