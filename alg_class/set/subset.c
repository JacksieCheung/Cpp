#include <stdio.h>
#include <string.h>

void backtrack(char result[], char str[], int index)
{
    if (strlen(str) == 0)
    {
        result[index] = '\0';
        printf("result:%s\n", result);
        return;
    }

    for (int i = 0; i < strlen(str); i++)
    {
        /* 减少一个元素 */
        char newstr[strlen(str)];
        int strIndex = 0;
        for (int k = 0; k < i; k++, strIndex++)
        {
            newstr[strIndex] = str[k];
        }
        for (int k = i + 1; k < strlen(str) + 1; k++, strIndex++)
        {
            newstr[strIndex] = str[k];
        }
        /* 减少一个元素 */

        result[index] = str[i];
        backtrack(result, newstr, index + 1);
    }
}

void subset(int index, int cur, int maxlen, char str[], char result[])
{
    if (index == maxlen)
    {
        result[index] = '\0';
        printf("%s\n", result);
        return;
    }

    if (cur == strlen(str))
        return;

    // 选择当前位置
    result[index] = str[cur];
    subset(index + 1, cur + 1, maxlen, str, result);

    // 不选择当前位置
    subset(index, cur + 1, maxlen, str, result);
}

int main()
{
    char str[100] = "abcd";
    char result[100];

    for (int i = 1; i < strlen(str) + 1; i++)
        subset(0, 0, i, str, result);

    printf("\n");
}