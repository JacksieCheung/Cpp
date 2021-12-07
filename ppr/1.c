#include <stdio.h>

int main()
{
    int x = 0;
    int a[9];
    // [0,1,,2,3,4,5,6,7,8]

    for (int i = 0; i < 9; i++)
    {
        x++;
        a[i] = x;
    }

    for (int i = 0; i < 9; i++)
        printf("result: %d\n", a[i]);
    return 0;
}