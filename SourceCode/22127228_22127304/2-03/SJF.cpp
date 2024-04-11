#include "SJF.h"

bool CompareBurstTime(Process* p1, Process* p2) {
    return p1->cpuBurst > p2->cpuBurst;
}

void SJF::Schedule(const std::string& path)
{
    if (!ReadFile(path))
    {
        std::cout << "An error occurred when reading the file!\n";
        return;
    }

    std::priority_queue<Process*, std::vector<Process*>, std::function<bool(Process*, Process*)>> qu(CompareBurstTime);
    std::unordered_map<std::string, int> name_cpuBurst_map;
    for (const Process& process : this->processes)
    {
        name_cpuBurst_map[process.name] = process.cpuBurst;
    }
    Process* currentProcess = nullptr;
    int time = 0;
    int p_counter = 0;  //processes pointer

    std::string schedulingChart = "Scheduling chart: 0 ";

    while (!(p_counter == processes.size() && qu.empty() && currentProcess == nullptr))
    {
        while (p_counter != processes.size() && time == processes[p_counter].arrivalTime)
        {
            qu.push(&processes[p_counter]);
            p_counter++;
        }

        //get the new shortest process
        auto newProcess = qu.top();
        if (newProcess != currentProcess) {
            // write scheduling chart
            if (currentProcess != nullptr)
                schedulingChart += "~" + currentProcess->name + "~ " + std::to_string(time) + " ";
            currentProcess = newProcess;
        }

        if (currentProcess != nullptr) {
            currentProcess->cpuBurst--;
            if (currentProcess->cpuBurst == 0)
            {
                schedulingChart += "~" + currentProcess->name + "~ " + std::to_string(time + 1) + " ";
                currentProcess->turnaroundTime = time + 1 - currentProcess->arrivalTime;
                currentProcess->waitTime = currentProcess->turnaroundTime - name_cpuBurst_map[currentProcess->name];
                qu.pop();
                currentProcess = nullptr;
                if (!qu.empty()) {
                    currentProcess = qu.top();
                }
            }
        }

        time++;
    }

    if (!OutputFile(schedulingChart, "SJF.txt"))
        std::cout << "An error occurred trying to output \"SJF.txt\"\n";
    else std::cout << "Outputted \"SJF.txt\"\n";
}