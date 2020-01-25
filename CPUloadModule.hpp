#ifndef CPULOADMODULE_HPP
#define CPULOADMODULE_HPP

#include "ChartMonitorModule.hpp"

class CPUloadModule : public ChartMonitorModule<float>
{
    private:
        CPUloadModule(const CPUloadModule &);
        CPUloadModule &operator=(const CPUloadModule &);

    public:
        CPUloadModule(size_t size);
        ~CPUloadModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};

#endif