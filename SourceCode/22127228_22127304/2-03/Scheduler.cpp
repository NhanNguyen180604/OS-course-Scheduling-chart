#include "Scheduler.h"

bool Scheduler::ReadFile(const std::string& path)
{
    std::ifstream fin(path);
    if (!fin)
        return false;

    int n, q;
    fin >> n;
    fin >> q;

    for (int i = 0; i < n; i++)
    {
        std::string name;
        int arrivalTime;
        int cpuBurst;
        int priority;
        fin >> name >> arrivalTime >> cpuBurst >> priority;
        this->processes.push_back(Process(name, arrivalTime, cpuBurst, priority));
    }

    fin.close();
    return true;
}