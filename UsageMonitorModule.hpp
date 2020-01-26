#ifndef USAGEMONITORMODULE_HPP
#define USAGEMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class UsageMonitorModule : public MultiStrMonitorModule
{
    private:
        UsageMonitorModule(const UsageMonitorModule &);
        UsageMonitorModule &operator=(const UsageMonitorModule &);

    public:
        UsageMonitorModule();
        ~UsageMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif