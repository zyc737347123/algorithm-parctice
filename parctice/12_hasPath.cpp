/********************* 
#12. 矩阵中的路径
关键思路：回溯法，剪枝法
**********************/

#include <string.h>

bool hasPathCore(char *matrix, int rows, int cols, char* str, int index, int count, bool *visited)
{
    int cur_row = index / cols, cur_col = index % rows;
    bool hasPath = false;

    if(cur_row >= rows || cur_col >= cols || matrix[index] != str[count] || visited[index] || index < 0)
    {
        return false;
    }

    if(str[count + 1] == 0)
    {
        return true;
    }

    visited[index] = true;

    // error
    // return hasPathCore(matrix, rows, cols, str, index - 1, ++count, visited) || 
    // hasPathCore(matrix, rows, cols, str, index + 1 , ++count, visited) || 
    // hasPathCore(matrix, rows, cols, str, index - cols, ++count, visited) ||
    // hasPathCore(matrix, rows, cols, str, index + cols, ++count, visited);

    // fix
    hasPath = hasPathCore(matrix, rows, cols, str, index - 1, ++count, visited) || 
    hasPathCore(matrix, rows, cols, str, index + 1 , ++count, visited) || 
    hasPathCore(matrix, rows, cols, str, index - cols, ++count, visited) ||
    hasPathCore(matrix, rows, cols, str, index + cols, ++count, visited);

    if(!hasPath)
    {
        visited[index] = false;
    }

    return hasPath;
}

bool hasPath(char *matrix, int rows, int cols, char* str)
{
    if(matrix == nullptr || str == nullptr || rows < 1 || cols < 1)
    {
        return false;
    }

    int index = 0;
    bool visited[rows * cols];

    memset(visited, 0, sizeof(visited));

    for(index = 0; index < rows * cols; index++)
    {
        if(hasPathCore(matrix, rows, cols, str, index, 0, visited))
        {
            return true;
        }
    }

    return false;
}

