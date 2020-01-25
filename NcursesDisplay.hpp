#ifndef NCURSESDISPLAY_HPP
#define NCURSESDISPLAY_HPP

#include "AMonitorDisplay.hpp"
#include "Keyboard.hpp"
#include <vector>
#include <ncurses.h>
#include <map>

class NcursesDisplay: public AMonitorDisplay
{
    private:
        std::map<char , IMonitorModule*> _keyBind;
        static const size_t chartHeight = 10; 
        std::vector<WINDOW*> _windows;
        Keyboard _keyboard;
        void delAllWin();
        void addMonitor(char key, IMonitorModule* m);
        NcursesDisplay(const NcursesDisplay &);
        NcursesDisplay &operator=(const NcursesDisplay &);

    public:
        NcursesDisplay(unsigned int width, unsigned int height);
        ~NcursesDisplay();

        void run();
        void display(MultiStrMonitorModule *);
        void display(ChartMonitorModule<float>*);
};

#endif