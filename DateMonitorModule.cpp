#include "DateMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <unistd.h>
#include <ctime>

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
    _strings.push_back(dt);
}
void DateMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}