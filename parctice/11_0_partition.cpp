/********************* 
#11.0  分区函数，按升序分区 
**********************/

#include <iostream>

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

void printa(int data[], int len)
{
    for (int i = 0; i <= len; i++)
        std::cout << data[i] << ' ';
    std::cout << std::endl;
}

int Parttion(int data[], int start, int end)
{
    if (data == nullptr || start < 0 || end < 0 || end < start)
    {
        return -1;
    }

    // index的初值有意义，但不一定是start，可以是[start, end]任意
    int index = start;

    // 不是为了换start到最后，而是为了将分界值放放到最右边，因为比较是从左到右的
    Swap(&data[index], &data[end]);

    // printa(data, end);

    int small = start - 1;

    for (index = start; index < end; index++)
    {
        if (data[index] < data[end])
        {
            small++;
            if (small != index)
            {
                // 总结分区函数两个下标：samll和index，samll保持指向从start开始最右边比data[end]小的数字就可以了
                // 当发现data[index]比data[end]小，交换 data[small+1] 和当前 data[index]即可
                Swap(&data[small], &data[index]);
                // printa(data, end);
                // 进行交换后，现在的data[samll]还是最右边一个比data[end]小的数字
            }
        }
    }

    small++;
    Swap(&data[small], &data[end]);
    printa(&data[start], end - start);
    return small;
}

void quickSort(int data[], int start, int end)
{
    int position = Parttion(data, start, end);
    if (position >= 0)
    {
        quickSort(data, start, position - 1);
        quickSort(data, position + 1, end);
    }
}

void quickSort2(int data[], int start, int end)
{
    if (start < end)
    {
        int position = Parttion(data, start, end);
        quickSort(data, start, position - 1);
        quickSort(data, position + 1, end);
    }
}

int main()
{
    int array[] = {3, 1, 6, 2, 4, 5};
    quickSort2(array, 0, 5);
    std::cout << std::endl;
    printa(array, 5);
    return 0;
}