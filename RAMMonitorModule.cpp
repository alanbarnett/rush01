#include "RAMMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <sstream>
#ifdef __linux__
#include <sys/sysinfo.h>
#elif defined (__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#endif


template <typename T>

std::string toStr(const T &val)
{
    std::stringstream ss;
    ss << val;
    return (ss.str());
}

RAMMonitorModule::RAMMonitorModule() : MultiStrMonitorModule("RAM info:")
{
    #ifdef __linux__
        struct sysinfo info;
        sysinfo(&info);

        _strings.push_back(std::string("Total RAM: ") + toStr(info.totalram / (1024 * 1024 *1024)) + "G");
        _strings.push_back(std::string("Free RAM: ") + toStr(info.freeram / (1024 * 1024 *1024)) + "G");

    #elif defined(__APPLE__)
        _strings.push_back(std::string("Total RAM: ") + toStr(getRamSize());
        _strings.push_back(std::string("Free RAM: ") + toStr(getFreeMem());

    #endif
}
RAMMonitorModule::~RAMMonitorModule()
{
}

void RAMMonitorModule::stat()
{
}
void RAMMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}

#if defined(__APPLE__)
size_t getRamSize()
{
    size_t ram = 0;
    getSysctl("hw.memsize", ram);
    return ram;
}

size_t getFreeMem()
{
    size_t pages = 0;
    size_t page_sz = 0;
    getSysctl("vm.page_free_count", pages);
    getSysctl("vm.pagesize", page_sz);
    return pages * page_sz;
}
#endif