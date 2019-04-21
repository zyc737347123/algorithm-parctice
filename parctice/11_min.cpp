/********************* 
#11. 旋转数组的最小数字 
**********************/

int Min(int data[], int length)
{
    if(data == nullptr || length < 0)
    {
        return 0;
    }

    int p1 = 0, p2 = length -1, p = 0;

    while(p1 < p2){
        if(p2 - p1 == 1)
        {
            return data[p2];
        }

        p = p1 + (p2 - p1)/2;
        int mindle = data[p];

        if(mindle > data[p1])
        {
            p1 = p;
        }else
        {
            p2 = p;
        }
    }
    
}


int MinInOrder(int *numbers, int start, int end)
{
    int min = numbers[start];
    for(int index = start; index < end; index++)
    {
        if(min > numbers[index])
        {
            min = numbers[index];
        }
    }
    return min;
}


int Min2(int *numbers, int length)
{
    if(numbers == nullptr || length < 0)
    {
        return -1;
    }

    int index1 = 0, index2 = length - 1, indexMid = 0;

    // 防止边界值，升序数组 or 单元素数组
    while(numbers[index1] >= numbers[index2])
    {
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;

        if(numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid])
        {
            return MinInOrder(numbers, index1, index2);
        }
        
        if(numbers[index1] <= numbers[indexMid])
            index1 = indexMid;
        if(numbers[index2] >= numbers[indexMid])
            index2 = indexMid;
    }

    return numbers[indexMid];
}