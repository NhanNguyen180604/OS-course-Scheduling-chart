#include "SchedulingContext.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "RoundRobin.h"

int main()
{
    SchedulingContext context;
    context.schedule("Input.txt", new FCFS());
    context.schedule("Input.txt", new RoundRobin());
    return 0;
}