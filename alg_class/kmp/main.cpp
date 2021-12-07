#include <cstdio>
#include <cstring>

void GetNext(char T[], int next[])
{
    int i, j, len;
    next[0] = -1;
    for (j = 1; T[j] != '\0'; j++)
    {
        for (len = j - 1; len >= 1; len--)
        {
            for (i = 0; i < len; i++)
            {
                if (T[i] != T[j - len + 1])
                    break;
            }

            if (i == len)
            {
                next[j] = len;
                break;
            }
        }

        if (len < 1)
            next[j] = 0;
    }
}

void GetNext2(char T[], int next[])
{
    int j = 0, k = -1;
    next[0] = -1;
    while (T[j] != '\0')
    {
        if (k == -1)
        {
            next[++j] = 0;
            k = 0;
        }
        else if (T[j] == T[k])
        {
            k++;
            next[++j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP(char S[], char T[])
{
    int i = 0, j = 0;
    int next[80];
    GetNext2(T, next);

    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[i])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
    if (T[j] == '\0')
        return (i - strlen(T) + 1);
    else
        return -1;
}

int main()
{
    char S[] = "abcabcacb";
    char T[] = "abcac";
    printf("%d\n", KMP(S, T));
}