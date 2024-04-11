#include "RoundRobin.h"

bool RoundRobin::ReadFile(const std::string& path)
{
    std::ifstream fin(path);
    if (!fin || !Scheduler::ReadFile(path))
        return false;

    fin >> this->q >> this->q;
    fin.close();
    return true;
}

void RoundRobin::Schedule(const std::string& path)
{
    if (!ReadFile(path))
    {
        std::cout << "An error occurred when reading the file!\n";
        return;
    }    

    std::queue<Process*> qu;
    std::unordered_map<std::string, int> name_cpuBurst_map;
    for (const Process& process: this->processes)
    {
        name_cpuBurst_map[process.name] = process.cpuBurst;
    }
    Process *currentProcess = nullptr;
    int time = 0;
    int p_counter = 0;  //processes pointer
    int current_q = this->q;  //current quantum left

    std::string schedulingChart = "Scheduling chart: 0 ";
    
    while (!(p_counter == processes.size() && qu.empty() && currentProcess == nullptr))
    {
        while (p_counter != processes.size() && time == processes[p_counter].arrivalTime)
        {
            qu.push(&processes[p_counter]);
            p_counter++;
        }

        // switch to next process in queue
        if (currentProcess == nullptr)
        {
            if (!qu.empty())
            {
                currentProcess = qu.front();
                qu.pop();
            }
        }

        if (currentProcess)
        {
            currentProcess->cpuBurst--;
            current_q--;

            if (current_q == 0 || currentProcess->cpuBurst == 0)
            {
                // write scheduling chart
                schedulingChart += "~" + currentProcess->name + "~ " + std::to_string(time + 1) + " ";

                current_q = this->q;
                if (currentProcess->cpuBurst == 0)
                {
                    currentProcess->turnaroundTime = time + 1 - currentProcess->arrivalTime;
                    currentProcess->waitTime = currentProcess->turnaroundTime - name_cpuBurst_map[currentProcess->name];
                }
                else {
                    qu.push(currentProcess);
                }
                currentProcess = nullptr;
            }
        }

        time++;
    }

    if (!OutputFile(schedulingChart, "RR.txt"))
        std::cout << "An error occurred trying to output \"RR.txt\"\n";
    else std::cout << "Outputted \"RR.txt\"\n";
}