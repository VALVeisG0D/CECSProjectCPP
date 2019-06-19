#include <iostream>
#include <queue>

using namespace std;

class CommandUnit
{
    struct WorkUnit
    {
        int work;
    };

    queue<WorkUnit> freeWorkQueue;
    queue<WorkUnit> busyWorkQueue;

public:
    void InitializeWorkQueue()
    {
        for (int i = 0; i < 64; ++i)
        {
            freeWorkQueue.push(WorkUnit());
        }
    }

    // Pop worker off freeWorkQueue
    // Push worker onto busyWorkQueue
    // Pop worker off busyWorkQueue when work is finish
    // Push worker onto freeWorkQueue when work is finish
    void DistributeWork(int workerIdentifier)
    {
        while (!freeWorkQueue.empty)
        {
            busyWorkQueue.push(freeWorkQueue.front);
            freeWorkQueue.pop();
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
