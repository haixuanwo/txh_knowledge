/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-06-18 12:52:25
 * @LastEditors: Clark
 * @LastEditTime: 2024-06-18 12:52:29
 * @Description: file content
 */

#include <iostream>
#include <cstdlib>

int *create()
{
    return (int *)malloc(sizeof(int));
}

int main()
{
    int* p = create();
    *p =  100;

    printf("%d\n", *p);
    free(p);

    int a = *p;

    return 0;
}
