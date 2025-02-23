#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    // cpu = (total - idle) / total
    float activeJiffies;
    long totalJiffies = LinuxParser::Jiffies();
    long idleJiffies = LinuxParser::IdleJiffies();
    activeJiffies = totalJiffies - idleJiffies;

    return activeJiffies / totalJiffies;
}
// DONE