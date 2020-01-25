#include "MultiStrMonitorModule.hpp"

MultiStrMonitorModule::MultiStrMonitorModule(const std::string &name): AMonitorModule(name) {}

MultiStrMonitorModule::~MultiStrMonitorModule() {}

const std::vector<std::string> &MultiStrMonitorModule::getStrings() const
{  
    return (_strings);
}
