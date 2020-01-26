#include "CPUloadModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Utils.hpp"

CPUloadModule::CPUloadModule(size_t size): ChartMonitorModule<float>("CPU Load:", size)
{
	for(size_t i = 0; i < size; i++)
		this->addData(0);
}

CPUloadModule::~CPUloadModule()
{
}

void CPUloadModule::stat()
{
    Info info;
    float loadp = info.getActivity();
    addData(loadp);
}

void CPUloadModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
