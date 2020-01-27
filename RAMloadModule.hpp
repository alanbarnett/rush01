#ifndef RAMLOADMODULE_HPP
#define RAMLOADMODULE_HPP

#include "ChartMonitorModule.hpp"

class RAMloadModule : public ChartMonitorModule<float>
{
    private:
        RAMloadModule(const RAMloadModule &);
        RAMloadModule &operator=(const RAMloadModule &);

    public:
        RAMloadModule(size_t size);
        ~RAMloadModule();
        void beDisplayed(IMonitorDisplay *);
        void stat();
};

#endif
