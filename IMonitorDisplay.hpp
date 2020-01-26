#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP
#include "IMonitorModule.hpp"
#include "MultiStrMonitorModule.hpp"
#include "ChartMonitorModule.hpp"
#include <string>

class IMonitorDisplay
{
public:
    virtual void addMonitor(IMonitorModule *) = 0;
    virtual void removeMonitor(const std::string &name) = 0;
    virtual void run() = 0;
    virtual void display(MultiStrMonitorModule *) = 0;
    virtual void display(ChartMonitorModule<float>*) = 0;
    virtual ~IMonitorDisplay() {};
};

#endif