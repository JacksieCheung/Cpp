#include <iostream>
#include <cstdio>
#include <vector>
#define MAXLEN 100

using namespace std;

vector<vector<char> > dist; // 字典
int in[26];                 // 入度
int target[26];             // 判别是否修改为目标
char martix[26][26];        // 图

int main()
{
    // 输入
    int A, K; // A 表示要恢复的字母个数，K 表示字典个数
    scanf("%d %d", &A, &K);
    for (int i = 0; i < K; i++)
    {
        char str[MAXLEN];
        scanf("%s", str);
        vector<char> tmp(str, str + sizeof(str));
        dist.push_back(tmp);
    }
    char str[MAXLEN];
    scanf("%s", str);

    // printf("A:%d,K:%d\n", A, K);

    // printf("dist:\n");
    // for (int i = 0; i < K; i++)
    // {
    //     printf("%s\n", dist[i].data());
    // }

    // printf("\nstr:%s\n", str);

    // 建图
    for (int i = 1; i < K; i++)
    {
        int len = dist[i].size() < dist[i - 1].size() ? dist[i].size() : dist[i - 1].size();
        for (int j = 0; j < len; j++)
        {
            if (dist[i][j] == dist[i - 1][j])
                continue;
            int a = dist[i - 1][j] - 'a';
            int b = dist[i][j] - 'a';
            martix[a][b] = 1;
            in[b]++;
            target[a] = 1;
            target[b] = 1;
            break;
        }
    }

    // printf("G:\n");
    // for (int i = 0; i < 26; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         printf("%d ", martix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("============\n");

    // 拓扑排序
    int sort_res[A];
    int count = 0;
    bool flag = true;
    while (count < A && flag)
    {
        flag = false;
        for (int i = 0; i < 26; i++)
        {
            if (target[i] == 0)
                continue;

            if (in[i] == 0)
            {
                // 取出入度为 0 的点
                sort_res[count] = i;
                count++;
                in[i]--; // 入度集合中减去这个点

                // 该点指向的节点入度减一
                for (int j = 0; j < 26; j++)
                {
                    if (martix[i][j])
                    {
                        in[j]--;
                    }
                }

                flag = true;
            }
        }
    }

    // for (int i = 0; i < A; i++)
    //     printf("%d ", sort_res[i]);
    // printf("\n");

    // 给排序的结果重新编号，使得一一对应
    char res[26];
    for (int i = 0, j = 0; i < 26; i++)
    {
        if (target[i])
        {
            res[sort_res[j]] = i;
            j++;
        }
        else
        {
            res[i] = i;
        }
    }

    // 输出
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", res[str[i] - 'a'] + 'a');
    }
    printf("\n");
}