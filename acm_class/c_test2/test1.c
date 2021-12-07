#include <stdio.h>
#include <string.h>

int isValid(char *tmp)
{
    char stack[100];
    int j = 0;
    for (int i = 0; i < strlen(tmp); i++)
    {
        if (tmp[i] == '(' || tmp[i] == '[' || tmp[i] == '{')
        {
            stack[j] = tmp[i];
            j++;
        }
        else if (tmp[i] == ')')
        {
            if (stack[j - 1] == '(')
            {
                j--;
            }
            else
            {
                return 0;
            }
        }
        else if (tmp[i] == ']')
        {
            if (stack[j - 1] == '[')
            {
                j--;
            }
            else
            {
                return 0;
            }
        }
        else if (tmp[i] == '}')
        {
            if (stack[j - 1] == '{')
            {
                j--;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    if (j == 0)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    char num[N][100];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", num[i]);
    }

    // 调用函数
    for (int i = 0; i < N; i++)
    {
        if (isValid(num[i]))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}