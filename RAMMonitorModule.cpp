#include "RAMMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Utils.hpp"
#include <sstream>
#ifdef __linux__
#include <sys/sysinfo.h>
#elif defined (__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#endif


RAMMonitorModule::RAMMonitorModule() : MultiStrMonitorModule("RAM info:")
{

}
RAMMonitorModule::~RAMMonitorModule()
{
}

void RAMMonitorModule::stat()
{
        _strings.clear();
    #ifdef __linux__
    struct sysinfo info;
    sysinfo(&info);

    _strings.push_back(std::string("Total RAM: ") + toStr(info.totalram / (1024 * 1024)) + "M");
    _strings.push_back(std::string("Free RAM: ") + toStr(info.freeram / (1024 * 1024)) + "M");

    #elif defined(__APPLE__)
    _strings.push_back(std::string("Total RAM: ") + toStr(getRamSize()) + "M");
    _strings.push_back(std::string("Free RAM: ") + toStr(getFreeMem()) + "M");
     #endif
}

void RAMMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
