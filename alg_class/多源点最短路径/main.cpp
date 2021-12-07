#include <iostream>

using namespace std;

const int n = 3;
void Floyd(int arc[n][n], int dist[n][n])
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = arc[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
    int arc[][3] = {
        {0, 4, 11},
        {6, 0, 2},
        {3, 100, 0},
    };
    int dist[3][3];

    Floyd(arc, dist);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}