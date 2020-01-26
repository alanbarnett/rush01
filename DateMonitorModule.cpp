#include "DateMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <unistd.h>
#include <ctime>
#include <cstring>
#include <errno.h>

DateMonitorModule::DateMonitorModule() : MultiStrMonitorModule("The local date and time:")
{
    stat();
}

DateMonitorModule::~DateMonitorModule()
{
}

void DateMonitorModule::stat()
{
    _strings.clear();
    time_t now = time(0);
    char *dt = ctime(&now);
    std::string tmp = dt;
    tmp.resize(24);
    if (!dt)
        _strings.push_back(std::strerror(errno));
    else
    {
        std::string tmp = dt;
        tmp.resize(24);
        _strings.push_back(tmp);
    }
}

void DateMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}