/********************* 
#3. 二维数组中的查找 
关键思路：根据数组排序规律，有效缩小查找范围
**********************/

bool Find(int *matrix, int rows, int cols, int number)
{
    bool result = false;
    if(matrix == nullptr || rows <= 0 || cols <= 0)
    {
        return result;
    }

    int col = cols - 1;
    int row = 0, index = 0;

    while (col >= 0 && row < rows)
    {
        index = matrix[row * cols + col];
        if(index == number)
        {
            result = true;
            break;
        }
        if(index > number)
            col--;
        if(index < number)
            row++;
    }
    
    return result;
}