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
    for(int i = 0; i <= len ; i++)
        std::cout << data[i] << ' ';
    std::cout << std::endl;
}

int Parttion(int data[], int start, int end)
{
    if(data == nullptr || start < 0 || end < 0 || end < start)
    {
        return -1;
    }

    int index = start;
    Swap(&data[index], &data[end]);

    printa(data, end);

    int small = start - 1;

    for(index = start; index < end; index++)
    {
        if(data[index] < data[end])
        {
            small++;
            if(small != index)
            {
                // 此时data[index]比data[end]小, samll 和 index 之间存在距离
                // 此时data[small - 1]会是最右边一个比data[end]小的数子
                // 此时data[small]，是最左边一个比data[end]大的数字
                // 所以需要交换
                Swap(&data[small], &data[index]);
                printa(data, end);
            }
        }
    }

    small++;
    Swap(&data[small], &data[end]);
    printa(data, end);
    return small;
}

int main()
{
    int array[] = {3, 1, 6, 2, 4, 5};
    std::cout << Parttion(array, 0, 5) << std::endl;
    return 0;
}