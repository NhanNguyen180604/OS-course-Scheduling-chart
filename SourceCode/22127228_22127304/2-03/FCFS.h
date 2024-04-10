#pragma once
#include "Scheduler.h"

class FCFS : public Scheduler
{
public:
    virtual void Schedule(const std::string& path);
};