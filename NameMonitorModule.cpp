#include "NameMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <unistd.h>
#include <pwd.h>

static std::string getUserName()
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (pw)
    {
        return std::string(pw->pw_name);
    }
    return ("User: unknown");
}

NameMonitorModule::NameMonitorModule() : MultiStrMonitorModule("Hostname/Username")
{

    char buf[256];
    if (gethostname(buf, 256) == 0)
        _strings.push_back(std::string("Host: ") + buf);

    else
        _strings.push_back("Host: unknown");

    _strings.push_back(std::string("User: ") + getUserName());
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