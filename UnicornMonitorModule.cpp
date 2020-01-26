#include "UnicornMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <unistd.h>
#include <ctime>
#include <cstring>
#include <errno.h>

UnicornMonitorModule::UnicornMonitorModule() : MultiStrMonitorModule("Zaz's favorite animal:")
{
    _cnt = 0;
}

UnicornMonitorModule::~UnicornMonitorModule()
{
}

void UnicornMonitorModule::stat()
{
    _strings.clear();
    _strings.push_back("    \\");
    _strings.push_back("   _\\,,");
    _strings.push_back("  \"-=\\~     _");
    _strings.push_back("     \\\\~___( ~");
    _strings.push_back("    _|/---\\\\_");
    if ((_cnt++) % 2)
        _strings.push_back("    \\        \\");
    else
        _strings.push_back("    /        /");
}

void UnicornMonitorModule::beDisplayed(IMonitorDisplay *d)
{
    d->display(this);
}