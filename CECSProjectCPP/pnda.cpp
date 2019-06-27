#include <iostream>
#include <queue>

using namespace std;

class CommandUnit
{
    struct WorkUnit
    {
        bool workDone = false;

        int DoWork(int work)
        {
            return work + 1;
        }

        bool WorkDone()
        {
            return true;
        }
    };

    // The work queue will be dedicated to a single piece of work
    // Work is not done unless all work unit report back that it
    // is done working.
    queue<WorkUnit> workQueue;

public:
    void InitializeWorkQueue()
    {
        for (int i = 0; i < 64; ++i)
        {
            workQueue.push(WorkUnit());
            WorkUnit currentWork = workQueue.back();
            currentWork.DoWork(i);
        }
    }

    void WaitForWorkDone()
    {
        
        while (!workQueue.empty())
        {
            // Wait for work units to report back when it is done
            // with its work.
            for (int i = 0; i < 64; ++i)
            {
                WorkUnit tempUnit = workQueue.front();

                // If work is done, place the worker in front of queue
                // to the back of the queue.
                if (tempUnit.WorkDone())
                {
                    workQueue.pop();
                    workQueue.push(tempUnit);
                }
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

    queue<int> intQ;

    for (int i = 0; i < 64; ++i)
    intQ.push(i);

    for (int i = 0; i < 64; ++i)
    {
    cout << intQ.front() << endl;
    intQ.pop();
    }
    return 0;
}
