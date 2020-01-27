#include "OSMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#ifdef __linux__
#include <sys/utsname.h>
#endif

OSMonitorModule::OSMonitorModule(): MultiStrMonitorModule("OS info:")
{
    #ifdef __linux__
    struct utsname info;
    uname(&info);

    _strings.push_back(std::string("System name: ") + info.sysname);
    _strings.push_back(std::string("Release: ") + info.release);
    _strings.push_back(std::string("Version: ") + info.version);
    _strings.push_back(std::string("Machine: ") + info.machine);
    #elif defined(__APPLE__)
    #endif

}
OSMonitorModule::~OSMonitorModule()
{}

void OSMonitorModule::stat()
{}
void OSMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
