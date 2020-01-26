#include "AMonitorDisplay.hpp"

AMonitorDisplay::AMonitorDisplay(unsigned int width, unsigned int height)
: _width(width), _height(height), _curHeight(0) {}

AMonitorDisplay::~AMonitorDisplay()
{
	for(iterator i = _monitors.begin(); i != _monitors.end(); i++)
		delete *i;
}

void AMonitorDisplay::addMonitor(IMonitorModule *module)
{
	_monitors.push_back(module);
}

void AMonitorDisplay::addMonitorWithKey(char key, IMonitorModule* m)
{
	addMonitor(m);
	_keyBind[key] = m;
}

void AMonitorDisplay::removeMonitor(const std::string &name)
{
	for(iterator i = _monitors.begin(); i != _monitors.end(); i++)
	{
		if ((*i)->getName() ==	name)
		{
			delete *i;
			_monitors.erase(i);
		}
	}
}
