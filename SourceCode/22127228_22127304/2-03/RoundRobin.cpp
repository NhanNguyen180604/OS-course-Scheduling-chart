#include "RoundRobin.h"

bool RoundRobin::ReadFile(const std::string& path)
{
    std::ifstream fin(path);
    if (!fin)
        return false;

    int n;
    fin >> n;
    fin >> this->q;

    for (int i = 0; i < n; i++)
    {
        std::string name;
        int arrivalTime;
        int cpuBurst;
        int priority;
        fin >> name >> arrivalTime >> cpuBurst >> priority;
        this->processes.push_back(Process(name, arrivalTime, cpuBurst, priority));
    }

    std::sort(processes.begin(), processes.end(), [](Process a, Process b)
    {
        return a.arrivalTime < b.arrivalTime;
    });
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
    int p_counter = 0;
    int current_q = this->q;
    
    while (true)
    {
        if (p_counter == processes.size() && qu.empty() && currentProcess == nullptr)
            break;

        if (p_counter != processes.size())
        {
            if (time == processes[p_counter].arrivalTime)
            {
                qu.push(&processes[p_counter]);
                p_counter++;
            }
        }

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

    for (const Process& process: processes)
    {
        std::cout << process.turnaroundTime << "  " << process.waitTime << '\n';
    }
}