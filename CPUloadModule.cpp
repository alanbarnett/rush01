#include "CPUloadModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Utils.hpp"


CPUloadModule::CPUloadModule(size_t size): ChartMonitorModule<float>("CPU Load:", size)
{
}

CPUloadModule::~CPUloadModule()
{}

void CPUloadModule::stat()
{
    float loadp = getCPULoad();
    addData(loadp);
}

void CPUloadModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}