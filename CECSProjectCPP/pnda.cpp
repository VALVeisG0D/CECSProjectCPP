#include <iostream>
#include <queue>

using namespace std;

class CommandUnit
{
    // Blueprint for a work unit
    // Receive work, do work, result work done.
    struct WorkUnit
    {
        bool workDone = false;
        int uniqueWork = 0;

        int DoWork(int work)
        {
            workDone = false;
            uniqueWork = work + 5;
            workDone = true;

            return uniqueWork;
        }

        bool IsWorkDone()
        {
            return workDone;
        }
    };

    // The work queue will be dedicated to a single piece of work
    // Work is not done unless all work unit report back that it
    // is done working.
    queue<WorkUnit> workQueue;
    int workResult[64];

public:

    // Worker is put on the queue and given work.
    // Worker will give result of work back when done and signal
    // the command unit.
    void InitializeWorkQueue()
    {
        for (int i = 0; i < 64; ++i)
        {
            workQueue.push(WorkUnit());
            WorkUnit currentWorker = workQueue.back();
            workResult[i] = currentWorker.DoWork(i);
        }
    }

    void WaitForWorkDone()
    {
        // Wait for work units to report back when it is done
        // with its work.
        for (int i = 0; i < 64; ++i)
        {
            WorkUnit tempUnit = workQueue.front();

            // If work is done, place the worker in front of queue
            // to the back of the queue.
            if (tempUnit.IsWorkDone())
            {
                workQueue.pop();
                workQueue.push(tempUnit);
            }
        }

        cout << "Work done" << endl;

        for (int i = 0; i < 64; ++i)
            cout << workResult[i] << endl;
    }
};

int main()
{
    cout << "PNDA" << endl;

    CommandUnit cmu;

    cmu.InitializeWorkQueue();
    cmu.WaitForWorkDone();

    {
        int a = 3;
        int b = 4;
        int c = a + b + 44;
    }

    return 0;
}
