#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule
{
    public:
        virtual bool isActive() = 0;
        virtual void setActive() = 0;
        virtual void stat() = 0;
        virtual ~IMonitorModule() = 0;
};

#endif