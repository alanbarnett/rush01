#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP
#include <string>

class IMonitorDisplay;

class IMonitorModule
{
    public:
        virtual const std::string &getName() const = 0;
        virtual bool isActive() = 0;
        virtual void setActive(bool a) = 0;
        virtual void stat() = 0;
        virtual void beDisplayed(IMonitorDisplay *) = 0;
        virtual ~IMonitorModule() {};
};

#endif