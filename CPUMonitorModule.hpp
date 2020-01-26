#ifndef CPUMONITORMODULE_HPP
#define CPUMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class CPUMonitorModule : public MultiStrMonitorModule
{
    private:
        CPUMonitorModule(const CPUMonitorModule &);
        CPUMonitorModule &operator=(const CPUMonitorModule &);

    public:
        CPUMonitorModule();
        ~CPUMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif