/********************* 
#13. 机器人的运动范围 
关键思路：回溯法，剪枝法
**********************/

#include <string.h>

int getDigitSum(int number)
{
    int sum = 0;
    // 防止输入的number为负数，会出现死循环
    while (number > 0)
    {
        sum += number % 10;
        number = number / 10;
    }
    return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    if (row < rows && rows > 0 && col < cols && cols > 0 && visited[cols * row + col] && (getDigitSum(col) + getDigitSum(col) <= threshold))
    {
        return true;
    }
    return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    int count = 0;

    if (check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;

        count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row, col - 1, visited);
    }

    return count;
}

int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows <= 0 || cols <= 0)
    {
        return 0;
    }

    bool visited[rows * cols];
    memset(visited, 0, sizeof(visited));

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

    return count;
}