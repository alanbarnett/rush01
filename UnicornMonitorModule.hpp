#ifndef UNICORNMONITORMODULE_HPP
#define UNICORNMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class UnicornMonitorModule : public MultiStrMonitorModule
{
    private:
        int _cnt;
        UnicornMonitorModule(const UnicornMonitorModule &);
        UnicornMonitorModule &operator=(const UnicornMonitorModule &);

    public:
        UnicornMonitorModule();
        ~UnicornMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif