#ifndef MULTISTRMONITORMODULE_HPP
#define MULTISTRMONITORMODULE_HPP

#include "AMonitorModule.hpp"
#include <vector>
#include <string>

class MultiStrMonitorModule : public AMonitorModule
{
    protected:
        std::vector<std::string> _strings;

    private:
        MultiStrMonitorModule(const MultiStrMonitorModule &);
        MultiStrMonitorModule &operator=(const MultiStrMonitorModule &);

    public:
        MultiStrMonitorModule(const std::string &name);
        ~MultiStrMonitorModule();
        const std::vector<std::string> &getStrings() const;     
};

#endif