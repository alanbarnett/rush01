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

#if defined(__APPLE__)
size_t RAMMonitorModule::getRamSize()
{
    size_t ram = 0;
    getSysctl("hw.memsize", ram);
    return ram / (1024 * 1024);
}

size_t RAMMonitorModule::getFreeMem()
{
    size_t pages = 0;
    size_t page_sz = 0;
    getSysctl("vm.page_free_count", pages);
    getSysctl("vm.pagesize", page_sz);
    return pages * page_sz / (1024 * 1024);
}
#endif