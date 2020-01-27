#include "RAMloadModule.hpp"
#include "IMonitorDisplay.hpp"
#include <cstdlib>

RAMloadModule::RAMloadModule(size_t size): ChartMonitorModule<float>("RAM Load:", size)
{
	for(size_t i = 0; i < size; i++)
		this->addData(0);
}

RAMloadModule::~RAMloadModule()
{
}

void RAMloadModule::stat()
{
	addData(rand() % 100);
}

void RAMloadModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
