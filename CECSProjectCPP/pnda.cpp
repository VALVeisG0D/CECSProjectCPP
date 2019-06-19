#include <iostream>
#include <queue>

using namespace std;

class CommandUnit
{
    struct WorkUnit
    {
        int work;
    };

    WorkUnit workGroup[64];
    queue<WorkUnit> workQueue;

    public:
    void InitializeWorkQueueWithWorkUnit()
    {
        for (int i = 0; i < 64; ++i)
        {
            workQueue.push(workGroup[i]);
        }
    }

    void DistributeWork(int workerIdentifier)
    {
        while (true)
        {
            for (int i = 0; i < 64; ++i)
            {
                workQueue.front;
                workQueue.pop();
            }
        }
    }
};

int main()
{
    cout << "PNDA" << endl;

    {
        int a = 3;
        int b = 4;
        int c = a + b + 44;
    }
    
    return 0;
}
