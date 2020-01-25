#ifndef AMONITORMODULE_HPP
#define AMONITORMODULE_HPP

#include "IMonitorModule.hpp"

class AMonitorModule : public IMonitorModule
{
    private:
        bool _active;
        AMonitorModule(const AMonitorModule &);
        AMonitorModule &operator=(const AMonitorModule &);

    public:
        AMonitorModule();
        ~AMonitorModule();
        bool isActive();
        void setActive(bool a);
};

#endif