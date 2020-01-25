#ifndef AMONITORMODULE_HPP
#define AMONITORMODULE_HPP

#include "IMonitorModule.hpp"

class AMonitorModule : public IMonitorModule
{
    private:
        std::string _name;
        bool _active;
        AMonitorModule(const AMonitorModule &);
        AMonitorModule &operator=(const AMonitorModule &);

    public:
        AMonitorModule(const std::string &name);
        ~AMonitorModule();
        const std::string &getName() const;
        bool isActive();
        void setActive(bool a);
};

#endif