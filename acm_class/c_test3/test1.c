#include <stdio.h>

int input(int num)
{
    int returnVal = 0;
    char ch;
    char chForward;
    int tmp = 0;
    int numtmp[100];
    int stack = 1;
    int index = 0;
    int sum = 0;
    // printf("num: %d\n", num);
    while (1)
    {
        chForward = ch;
        ch = getchar();
        if (ch == '(')
            break;
    }
    while (stack != 0)
    {
        // printf("new loop,stack: %d\n", stack);
        chForward = ch;
        ch = getchar();
        // printf("ch: %c, chForward: %c, index: %d\n", ch, chForward, index);
        if (ch == '\n')
        {
            continue;
        }

        if (ch == ' ')
        {
            continue;
        }

        if (ch == '(')
        {
            stack++;
            continue;
        }
        else if (ch == ')')
        {
            stack--;
            if (chForward == '(')
            {
                continue;
            }
            else
            {
                // 回退
                if (sum == num)
                {
                    returnVal = 1;
                    break;
                }
                index--;
                sum = sum - numtmp[index];
                continue;
            }
        }
        else
        {
            tmp = ch - '0';
            while (1)
            {
                chForward = ch;
                ch = getchar();
                if (ch == ' ' || ch == '\n')
                    continue;
                // printf("ch: %c, chForward: %c, index: %d\n", ch, chForward, index);
                if (ch == '(')
                {
                    stack++;
                    break;
                }
                else
                {
                    tmp = tmp * 10 + (ch - '0');
                }
            }
            numtmp[index] = tmp;
            index++;
            sum += tmp;
        }
    }

    // 清除输入
    while (stack != 0)
    {
        chForward = ch;
        ch = getchar();
        if (ch == '(')
            stack++;
        if (ch == ')')
            stack--;
    }
    ch = getchar(); // get '\n'

    return returnVal;
}

int main()
{
    char ch;
    int index = 0;
    int result[100];
    int num = 0;
    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;
        while (1)
        {
            if (ch == ' ')
                break;
            num = num * 10 + (ch - '0');
            ch = getchar();
        }
        result[index] = input(num);
        index++;
        num = 0;
    }

    for (int i = 0; i < index; i++)
    {
        if (result[i] == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}