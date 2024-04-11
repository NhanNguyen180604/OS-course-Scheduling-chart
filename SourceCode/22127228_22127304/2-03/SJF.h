#pragma once
#include "Scheduler.h"
#include <vector>
#include <queue>
#include <functional>

class SJF : public Scheduler
{
public:
    virtual void Schedule(const std::string& path);
};
