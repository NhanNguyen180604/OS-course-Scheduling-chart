#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include "Process.h"

class Scheduler
{
protected:
    std::vector<Process> processes;
    virtual bool ReadFile(const std::string& path);
    bool OutputFile(const std::string& schedulingChart, const std::string& fileName);
    
public:
    virtual void Schedule(const std::string& path) = 0;
};