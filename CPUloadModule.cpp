#include "CPUloadModule.hpp"
#include "IMonitorDisplay.hpp"

CPUloadModule::CPUloadModule(size_t size): ChartMonitorModule<float>("CPU Load:", size)
{
    for(size_t i = 0; i < size; i++)
        this->addData(i);
}

CPUloadModule::~CPUloadModule()
{}

void CPUloadModule::stat()
{}
void CPUloadModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}