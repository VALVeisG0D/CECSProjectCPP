#include <iostream>
#include <queue>

using namespace std;

// Put severe restrictions on this design first. This will be an 8-bit add only machine. 
// No other operations!
// What do we need to design and build a completely new computing architecture?
// Instruction set, circuit design, 
// How to solve the conditional statements and alphabet/string statements problem in this architecture?
// Addresses are just integers.
class CommandUnit
{
    // Blueprint for a work unit
    // Receive work, do work, work done.
    // Each work unit will have an instruction pointer that tracks which part of the program 
    // it will work on.
    struct WorkUnit
    {
        bool workDone = false;
        int uniqueWork = 0;
        long IP;

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
    // the command unit that it is free for more work.
    void InitializeWorkQueue()
    {
        for (int i = 0; i < 64; ++i)
        {
            workQueue.push(WorkUnit());
            workResult[i] = workQueue.back().DoWork(i);
        }
    }

    void WaitForWorkDone()
    {
        // Wait for work units to report back when it is done
        // with its work.
        for (int i = 0; i < 64; ++i)
        {
            WorkUnit tempUnit = workQueue.front();

            // If work is done, move worker in front to the back
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
