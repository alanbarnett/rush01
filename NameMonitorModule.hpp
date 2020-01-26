#ifndef NAMEMONITORMODULE_HPP
#define NAMEMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class NameMonitorModule : public MultiStrMonitorModule
{
    private:
        NameMonitorModule(const NameMonitorModule &);
        NameMonitorModule &operator=(const NameMonitorModule &);

    public:
        NameMonitorModule();
        ~NameMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif