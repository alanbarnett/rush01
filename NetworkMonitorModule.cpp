#include "NetworkMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Utils.hpp"


NetworkMonitorModule::NetworkMonitorModule() : MultiStrMonitorModule("Network throughput:")
{

}

NetworkMonitorModule::~NetworkMonitorModule()
{
}

void NetworkMonitorModule::stat()
{
    _strings.clear();
    ns.update();
    _strings.push_back(std::string("Receive: ") + toStr(ns.getReceiveThrptKB()) + "KB");
    _strings.push_back(std::string("Send: ") + toStr(ns.getSentThrptKB()) + "KB");
}

void NetworkMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}
