#ifndef AMONITORDISPLAY_HPP
#define AMONITORDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include <list>

class AMonitorDisplay : public IMonitorDisplay
{
public:
    typedef std::list<IMonitorModule *>::iterator Itor;

protected:
    unsigned int _width;
    unsigned int _height;
    unsigned int _curHeight;
    std::list<IMonitorModule *> _monitors;

private:
    AMonitorDisplay(const AMonitorDisplay &);
    AMonitorDisplay &operator=(const AMonitorDisplay &);

public:

    AMonitorDisplay(unsigned int width, unsigned int height);
    ~AMonitorDisplay();
    void addMonitor(IMonitorModule *);
    void removeMonitor(const std::string &name);
    void display(IMonitorModule *);
};

#endif