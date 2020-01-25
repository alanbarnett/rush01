#include "AMonitorModule.hpp"
#include <string>

AMonitorModule::AMonitorModule(const std::string &name) : _name(name), _active(true) {}

AMonitorModule::~AMonitorModule() {}

const std::string &AMonitorModule::getName() const
{
    return (_name);
}

bool AMonitorModule::isActive()
{
    return(_active);
}

void AMonitorModule::setActive(bool a)
{
    _active = a;
}
