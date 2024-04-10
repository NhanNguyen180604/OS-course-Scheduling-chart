#include "Process.h"

Process::Process(const std::string& name, int arrivalTime, int cpuBurst, int priority)
	: name(name), arrivalTime(arrivalTime), cpuBurst(cpuBurst), priority(priority) {}