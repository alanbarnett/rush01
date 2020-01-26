#include "NetworkMonitorModule.hpp"
#include "IMonitorDisplay.hpp"


NetworkMonitorModule::NetworkMonitorModule() : MultiStrMonitorModule("Network throughput:")
{

}

NetworkMonitorModule::~NetworkMonitorModule()
{
}

void NetworkMonitorModule::stat()
{
}

void NetworkMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
