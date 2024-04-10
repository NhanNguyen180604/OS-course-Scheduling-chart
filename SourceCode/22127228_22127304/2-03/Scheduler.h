#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Process.h"

class Scheduler
{
protected:
    std::vector<Process> processes;
    virtual bool ReadFile(const std::string& path);
public:
    virtual void Schedule(const std::string& path) = 0;
};