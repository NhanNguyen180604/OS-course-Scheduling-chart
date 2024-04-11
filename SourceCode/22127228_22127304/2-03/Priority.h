#pragma once
#include <queue>
#include <vector>
#include <functional>
#include "Scheduler.h"

class Priority : public Scheduler
{
public:
    virtual void Schedule(const std::string& path);
};
