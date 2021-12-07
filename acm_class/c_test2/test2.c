#include <stdio.h>
#include <string.h>

int isMirrorValid(char *tmp)
{
    int i = 0, j = strlen(tmp) - 1; // 前后指针
    for (; i < j;)
    {
        if (tmp[i] == 'A' || tmp[i] == 'H' || tmp[i] == 'I' || tmp[i] == 'M' || tmp[i] == 'O' || tmp[i] == 'T' || tmp[i] == 'U' || tmp[i] == 'V' || tmp[i] == 'W' || tmp[i] == 'X' || tmp[i] == 'Y' || tmp[i] == '8')
        {
            if (tmp[i] == tmp[j])
            {
                i++;
                j--;
                continue;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            switch (tmp[i])
            {
            case 'E':
                if (tmp[j] == '3')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            case 'J':
                if (tmp[j] == 'L')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            case 'L':
                if (tmp[j] == 'J')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            case 'S':
                if (tmp[j] == '2')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            case 'Z':
                if (tmp[j] == '5')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            case '2':
                if (tmp[j] == 'S')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            case '3':
                if (tmp[j] == 'E')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            case '5':
                if (tmp[j] == 'Z')
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
            default:
                return 0;
                break;
            }
        }
    }

    return 1;
}

int isPalindrome(char *tmp)
{
    int i = 0, j = strlen(tmp) - 1;
    for (; i < j;)
    {
        if (tmp[i] == tmp[j])
        {
            i++;
            j--;
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char buf[1000][50];
    char ch;
    int row = 0;
    int col = 0;
    while (1)
    {
        ch = getchar();
        if (ch == EOF)
        {
            // buf[row][col] = '\0';
            break;
        }
        if (ch == '\n')
        {
            buf[row][col] = '\0';
            row++;
            col = 0;
            continue;
        }
        buf[row][col] = ch;
        col++;
    }

    for (int i = 0; i < row; i++)
    {
        if (isPalindrome(buf[i]))
        {
            if (isMirrorValid(buf[i]))
            {
                printf("%s -- is a mirrored palindrome\n", buf[i]);
                continue;
            }
            else
            {
                printf("%s -- is a regular palindrome\n", buf[i]);
                continue;
            }
        }
        if (isMirrorValid(buf[i]))
        {
            printf("%s -- is a mirrored string\n", buf[i]);
            continue;
        }

        printf("%s -- is not a palindrome\n", buf[i]);
    }

    return 0;
}