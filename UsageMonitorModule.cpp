#include "UsageMonitorModule.hpp"
#include "IMonitorDisplay.hpp"


UsageMonitorModule::UsageMonitorModule() : MultiStrMonitorModule("Usage:")
{
    _strings.push_back("key 'n' to activate/deactivate NameMonitorModule");
    _strings.push_back("key 'o' to activate/deactivate OSMonitorModule");
    _strings.push_back("key 'd' to activate/deactivate DateMonitorModule");
    _strings.push_back("key 'c' to activate/deactivate CPUMonitorModule");
    _strings.push_back("key 'r' to activate/deactivate RAMMonitorModule");
    _strings.push_back("key 'l' to activate/deactivate CPUloadModule");
    _strings.push_back("key 'k' to activate/deactivate NetworkMonitorModule");
    _strings.push_back("key 'z' to activate/deactivate ZazAnimalMonitorModule");
    _strings.push_back("key 'u' to activate/deactivate UsageMonitorModule");

}

UsageMonitorModule::~UsageMonitorModule()
{
}

void UsageMonitorModule::stat()
{
}

void UsageMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
