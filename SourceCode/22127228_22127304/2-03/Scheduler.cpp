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

bool Scheduler::OutputFile(const std::string& schedulingChart, const std::string& fileName)
{
    std::ofstream fout(fileName, std::ios::out);
    if (!fout)
        return false;

    // write the first line
    fout << schedulingChart << '\n';

    int totalTT = 0;
    int totalWT = 0;
    for (const Process& process: processes)
    {
        fout << process.name << ":     TT = " << process.turnaroundTime << "     WT = " << process.waitTime << '\n';
        totalTT += process.turnaroundTime;
        totalWT += process.waitTime;
    }

    float avgTT = (float)totalTT / processes.size(), avgWT = (float)totalWT / processes.size();
    fout << "Average:" 
         << "     TT = " << std::fixed << std::setprecision(2) << avgTT
         << "     WT = " << std::fixed << std::setprecision(2) << avgWT;

    fout.close();
    return true;
}