#include "OSMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

#include <sys/utsname.h>


OSMonitorModule::OSMonitorModule(): MultiStrMonitorModule("OS info:")
{
    struct utsname info;
    uname(&info);

    _strings.push_back(std::string("System name: ") + info.sysname);
    _strings.push_back(std::string("Release: ") + info.release);
    _strings.push_back(std::string("Version: ") + info.version);
    _strings.push_back(std::string("Machine: ") + info.machine);

}
OSMonitorModule::~OSMonitorModule()
{}

void OSMonitorModule::stat()
{}
void OSMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
