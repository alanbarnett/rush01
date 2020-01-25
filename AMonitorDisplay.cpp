#include "AMonitorDisplay.hpp"

AMonitorDisplay::AMonitorDisplay(unsigned int width, unsigned int height)
: _height(height), _width(width), _curHeight(0) {}

AMonitorDisplay::~AMonitorDisplay()
{
    for(Itor i = _monitors.begin(); i != _monitors.end(); i++)
        delete *i;
}

void AMonitorDisplay::addMonitor(IMonitorModule *module)
{
    _monitors.push_back(module);
}

void AMonitorDisplay::removeMonitor(const std::string &name)
{
    for(Itor i = _monitors.begin(); i != _monitors.end(); i++)
    {
        if ((*i)->getName() ==  name)
        {
            delete *i;
            _monitors.erase(i);
        }
    }
}

void AMonitorDisplay::display(IMonitorModule *module)
{
    module->beDisplayed(this);
}