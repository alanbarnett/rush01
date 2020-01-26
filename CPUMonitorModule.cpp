#include "CPUMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Utils.hpp"
#include <sstream>

CPUMonitorModule::CPUMonitorModule(): MultiStrMonitorModule("CPU info:")
{
    Info info;

    _strings.push_back(std::string("Activity: ") + toStr(info.activity));
    _strings.push_back(std::string("Processes: ") + toStr(info.processes));
    _strings.push_back(std::string("Cores: ") + toStr(info.cores));
    _strings.push_back(std::string("Model: ") + info.model);
    _strings.push_back(std::string("Cpu GHz : ") + toStr(info.freqency));
}
CPUMonitorModule::~CPUMonitorModule()
{}

void CPUMonitorModule::stat()
{}
void CPUMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}