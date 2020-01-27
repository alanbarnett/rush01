#ifndef RAMMONITORMODULE_HPP
#define RAMMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class RAMMonitorModule : public MultiStrMonitorModule
{
    private:
        RAMMonitorModule(const RAMMonitorModule &);
        RAMMonitorModule &operator=(const RAMMonitorModule &);

    public:
        RAMMonitorModule();
        ~RAMMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif
