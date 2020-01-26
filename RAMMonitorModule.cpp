#include "RAMMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <sstream>
#ifdef __linux__
#include <sys/sysinfo.h>
#endif

template <typename T> std::string toStr(const T &val)
{
    std::stringstream ss;
    ss << val;
    return (ss.str());
}

RAMMonitorModule::RAMMonitorModule(): MultiStrMonitorModule("RAM info:")
{
    #ifdef __linux__
    struct sysinfo info;
    sysinfo(&info);

    _strings.push_back(std::string("Total RAM: ") + toStr(info.totalram /(1024 *1024)) + "M");
    _strings.push_back(std::string("Free RAM: ") + toStr(info.freeram /(1024 *1024)) + "M");

    #elif defined(__APPLE__)
    #endif
}
RAMMonitorModule::~RAMMonitorModule()
{}

void RAMMonitorModule::stat()
{}
void RAMMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}