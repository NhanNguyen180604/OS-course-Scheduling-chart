#include "SchedulingContext.h"
#include "Scheduler.h"
#include "RoundRobin.h"

int main()
{
    SchedulingContext context;
    context.schedule("Input.txt", new RoundRobin());
    return 0;
}