#pragma once
#include <string>
struct Process
{
	std::string name;
	int arrivalTime;
	int cpuBurst;
	int priority;
	int waitTime;
	int turnaroundTime;
	Process(const std::string& name, int arrivalTime, int cpuBurst, int priority);
};