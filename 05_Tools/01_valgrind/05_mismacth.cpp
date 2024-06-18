/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-06-18 13:51:26
 * @LastEditors: Clark
 * @LastEditTime: 2024-06-18 14:09:39
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
    *p = 100;
    delete p;

    char *c = new char[1];
    free(c);

    char *a = new char[10];
    delete a;

    char *b = new char;
    delete[] b;
    return 0;
}
