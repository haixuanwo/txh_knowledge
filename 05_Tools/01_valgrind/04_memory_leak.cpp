
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

    return 0;
}
