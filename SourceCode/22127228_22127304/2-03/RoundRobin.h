#pragma once
#include "Scheduler.h"
#include <iostream>
#include <queue>

class RoundRobin : public Scheduler
{
private:
    int q;
protected:
    virtual bool ReadFile(const std::string& path);
public:
    virtual void Schedule(const std::string& path);
};