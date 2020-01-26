#ifndef DATEMONITORMODULE_HPP
#define DATEMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class DateMonitorModule : public MultiStrMonitorModule
{
    private:
        DateMonitorModule(const DateMonitorModule &);
        DateMonitorModule &operator=(const DateMonitorModule &);

    public:
        DateMonitorModule();
        ~DateMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif