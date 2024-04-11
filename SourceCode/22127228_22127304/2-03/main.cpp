#include "SchedulingContext.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "Priority.h"
#include "RoundRobin.h"
#include "SJF.h"

int main()
{
    SchedulingContext context;
    context.schedule("Input.txt", new FCFS());
    context.schedule("Input.txt", new RoundRobin());
    context.schedule("Input.txt", new Priority());
    context.schedule("Input.txt", new SJF());
    return 0;
}