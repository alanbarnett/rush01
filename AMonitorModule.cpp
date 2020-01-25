#include "AMonitorModule.hpp"

AMonitorModule::AMonitorModule() {}

AMonitorModule::~AMonitorModule() {}

bool AMonitorModule::isActive()
{
    return(_active);
}

void AMonitorModule::setActive(bool a)
{
    _active = a;
}
