#include "OSMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

OSMonitorModule::OSMonitorModule(): MultiStrMonitorModule("OS info:")
{
    this->_strings.push_back("test");
    this->_strings.push_back("test2");
    this->_strings.push_back("test3");
}
OSMonitorModule::~OSMonitorModule()
{}

void OSMonitorModule::stat()
{}
void OSMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}