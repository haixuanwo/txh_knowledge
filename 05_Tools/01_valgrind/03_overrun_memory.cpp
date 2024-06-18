/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-06-18 12:57:57
 * @LastEditors: Clark
 * @LastEditTime: 2024-06-18 13:40:37
 * @Description: file content
 */

#include <iostream>

int main()
{
    int *array = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i <= 10; i++)
    {
        array[i] = i;
    }

    // Valgrind不检查静态分配数组的使用情况！
    int array2[10] = {0};
    for (int i = 0; i <= 10; i++)
    {
        array2[i] = i;
    }

    return 0;
}
