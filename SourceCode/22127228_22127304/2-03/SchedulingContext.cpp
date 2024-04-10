#include "SchedulingContext.h"

void SchedulingContext::schedule(const std::string& path, Scheduler *scheduler)
{
    if (scheduler == nullptr)
    {
        std::cout << "Invalid scheduler!\n";
        return;
    }

    scheduler->Schedule(path);
    delete scheduler;
}