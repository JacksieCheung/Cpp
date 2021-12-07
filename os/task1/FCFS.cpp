// 先来先服务算法
#include <iostream>
#include <vector>

using namespace std;

struct Job
{
    int Id;
    int TimeArrive;
    int TimeWork;
    int TimeInput; // 作业进入系统时间
};

void handleFCFS(vector<Job> *jobList)
{
    // 开始时间为最后一个作业到达时间
    int time = (*jobList)[(*jobList).size() - 1].TimeArrive;
    for (int i = 0; i < (*jobList).size(); i++)
    {
        (*jobList)[i].TimeInput = time;
        // 时间进位，不考虑第二天的情况
        time = time % 100 + (*jobList)[i].TimeWork < 60 ? time + (*jobList)[i].TimeWork : time + (*jobList)[i].TimeWork + 40;
    }
}

// mac EOF 就是 ctrl D
// scanf 遇到 EOF 会返回 -1
int main()
{
    freopen("data.txt", "r", stdin);
    vector<Job> jobList;
    // int count = 0;
    while (1)
    {
        int n, m, k;
        if (scanf("%d %d %d", &n, &m, &k) == -1)
        {
            break;
        }
        Job job;
        job.Id = n;
        job.TimeArrive = m;
        job.TimeWork = k;
        jobList.push_back(job);
    }
    fclose(stdin);

    handleFCFS(&jobList);

    cout << "the result is below:(id, time input)" << endl;
    for (int i = 0; i < jobList.size(); i++)
    {
        cout << jobList[i].Id << " ";
        cout << jobList[i].TimeInput << endl;
    }

    return 0;
}