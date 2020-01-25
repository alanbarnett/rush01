#include "MultiStrMonitorModule.hpp"

MultiStrMonitorModule::MultiStrMonitorModule() {}

MultiStrMonitorModule::~MultiStrMonitorModule() {}

const std::vector<std::string> &MultiStrMonitorModule::getStrings() const
{  
    return (_strings);
}
