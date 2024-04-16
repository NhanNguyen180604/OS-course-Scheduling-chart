#include "FCFS.h"

void FCFS::Schedule(const std::string& path)
{
    if (!ReadFile(path))
    {
        std::cout << "An error occurred when reading the file!\n";
        return;
    }    

    int time = 0;
    int p_counter = 0;  //processes pointer

    std::string schedulingChart = "Scheduling chart: 0 ";

    while (p_counter != processes.size())
    {
        Process* process = &processes[p_counter++];
        if (time < process->arrivalTime)
            time = process->arrivalTime;
        time += process->cpuBurst;
        schedulingChart += "~" + process->name + "~ " + std::to_string(time) + " ";
        process->turnaroundTime = time - process->arrivalTime;
        process->waitTime = process->turnaroundTime - process->cpuBurst;
    }

    if (!OutputFile(schedulingChart, "FCFS.txt"))
        std::cout << "An error occurred trying to output \"FCFS.txt\"\n";
    else std::cout << "Outputted \"FCFS.txt\"\n";
}