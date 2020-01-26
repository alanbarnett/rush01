#ifndef NETWORKMONITORMODULE_HPP
#define NETWORKMONITORMODULE_HPP
#include "MultiStrMonitorModule.hpp"

class NetworkMonitorModule : public MultiStrMonitorModule
{
    private:
        NetworkMonitorModule(const NetworkMonitorModule &);
        NetworkMonitorModule &operator=(const NetworkMonitorModule &);

    public:
        NetworkMonitorModule();
        ~NetworkMonitorModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};
#endif