// 最高响应比算法
#include <iostream>
#include <vector>

using namespace std;

struct Job
{
    int Id;
    int TimeArrive;
    int TimeWork;
    int TimeInput; // 作业进入系统时间
    int TimeWait;  // 等待时间为 time - time_arrive + 1
    double R;      // 响应比 R = 1 + time_wait / time_work
};

bool LessSort(Job a, Job b) { return (a.R < b.R); }

void handleHRN(vector<Job> *jobList)
{
    // 开始时间为最后一个作业到达时间
    int time = (*jobList)[(*jobList).size() - 1].TimeArrive;

    while ((*jobList).size() != 0)
    {
        for (int i = 0; i < (*jobList).size(); i++)
        {
            (*jobList)[i].R = 1 + (time - (*jobList)[i].TimeArrive + 0.1) / (*jobList)[i].TimeWork;
        }

        // 升序排序
        sort((*jobList).begin(), (*jobList).end(), LessSort);

        // 弹出此 job
        Job tmp = (*jobList)[(*jobList).size() - 1];
        (*jobList).pop_back();

        tmp.TimeInput = time;
        // 时间进位，不考虑第二天的情况
        time = time % 100 + tmp.TimeWork < 60 ? time + tmp.TimeWork : time + tmp.TimeWork + 40;

        // 输出结果
        cout << tmp.Id << " ";
        cout << tmp.TimeInput << endl;
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
        job.TimeWait = 1;
        jobList.push_back(job);
    }
    fclose(stdin);

    cout << "the result is below:(id, time input)" << endl;
    handleHRN(&jobList);

    return 0;
}