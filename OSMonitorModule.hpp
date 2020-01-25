#ifndef OSMONITORMODULE_HPP
#define OSMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class OSMonitorModule : public MultiStrMonitorModule
{
    private:
        OSMonitorModule(const OSMonitorModule &);
        OSMonitorModule &operator=(const OSMonitorModule &);

    public:
        OSMonitorModule();
        ~OSMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif