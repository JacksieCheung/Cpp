#include <stdio.h>

int row = 4;
int col = 5;

int m[4][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20}};

int search(int target, int r, int c)
{
    if (r >= row || c >= col || r < 0 || c < 0)
        return 0;

    if (m[r][c] == target)
    {
        printf("result: %d, row: %d, col: %d\n", m[r][c], r + 1, c + 1);
        return 1;
    }
    else if (m[r][c] > target)
    {
        return search(target, r - 1, c) || search(target, r, c - 1);
    }
    else
    {
        return search(target, r + 1, c) || search(target, r, c + 1);
    }
}

int main()
{
    int res = search(0, (row - 1) / 2, (col - 1) / 2);
    if (res == 0)
    {
        printf("no this number\n");
    }
}