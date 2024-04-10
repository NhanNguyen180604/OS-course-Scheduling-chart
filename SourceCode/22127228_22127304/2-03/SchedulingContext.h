#pragma once
#include <string>
#include <iostream>
#include "Scheduler.h"

class SchedulingContext
{
public:
    void schedule(const std::string& path, Scheduler *scheduler);
};