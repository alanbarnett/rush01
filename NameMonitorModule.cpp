#include "NameMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <unistd.h>

NameMonitorModule::NameMonitorModule() : MultiStrMonitorModule("Hostname/Username")
{
    char buf[256];
    if (gethostname(buf, 256) == 0)
        _strings.push_back(std::string("Host: ") + buf);

    else
        _strings.push_back("Host: unknown");

    char *uname = getlogin();
    if (uname)
        _strings.push_back(std::string("User: ") + uname);
    else
        _strings.push_back("User: unknown");
}

NameMonitorModule::~NameMonitorModule()
{
}

void NameMonitorModule::stat()
{
}
void NameMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}