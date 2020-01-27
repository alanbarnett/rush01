#include "CPUMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Utils.hpp"
#include <sstream>

CPUMonitorModule::CPUMonitorModule(): MultiStrMonitorModule("CPU info:")
{
    // Info info;

    // _strings.push_back(std::string("Activity: ") + toStr(info.getActivity()));
    // _strings.push_back(std::string("Processes: ") + toStr(info.getNProcesses()));
    // _strings.push_back(std::string("Cores: ") + toStr(info.getNCores()));
    // _strings.push_back(std::string("Model: ") + info.getModel());
    // _strings.push_back(std::string("Cpu GHz : ") + toStr(info.getFrequency()));
}
CPUMonitorModule::~CPUMonitorModule()
{}

void CPUMonitorModule::stat()
{
    Info info;
    _strings.clear();
    _strings.push_back(std::string("Activity: ") + toStr(info.getActivity()));
    _strings.push_back(std::string("Processes: ") + toStr(info.getNProcesses()));
    _strings.push_back(std::string("Cores: ") + toStr(info.getNCores()));
    _strings.push_back(std::string("Model: ") + info.getModel());
    _strings.push_back(std::string("Cpu GHz : ") + toStr(info.getFrequency()));
}

void CPUMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}