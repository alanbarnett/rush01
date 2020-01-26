#include "NcursesDisplay.hpp"
#include "NameMonitorModule.hpp"
#include "DateMonitorModule.hpp"
#include "CPUMonitorModule.hpp"
#include "RAMMonitorModule.hpp"
#include "OSMonitorModule.hpp"
#include "CPUloadModule.hpp"
#include "NetworkMonitorModule.hpp"
#include "UsageMonitorModule.hpp"
#include "UnicornMonitorModule.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>

NcursesDisplay::NcursesDisplay(unsigned int width, unsigned int height): AMonitorDisplay(width, height)
{

    initscr();

    cbreak();
    /* tell curses not to echo the input back to the screen*/
    noecho();
    clear();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    refresh();

}

NcursesDisplay::~NcursesDisplay()
{
    delAllWin();
    endwin();
}

void NcursesDisplay::delAllWin()
{
    for(size_t i = 0; i < _windows.size(); i++)
    {
        werase(_windows[i]);
        wrefresh(_windows[i]);
        delwin(_windows[i]);
    }
    _windows.clear();
    _curHeight = 0;
}

void NcursesDisplay::run()
{
    for (int dt = 0;; dt++)
    {
        bool keyPressed = false;
        if (this->_keyboard.isKeyPresed('q'))
            break;
        int winRefresh = 10;   
        for(std::map<char, IMonitorModule*>::iterator i = _keyBind.begin(); i != _keyBind.end(); i++)
        {
            if (this->_keyboard.isKeyPresed(i->first))
            {
                i->second->setActive(!i->second->isActive());
                keyPressed = true;
            }
        }

        for(iterator i = _monitors.begin(); i != _monitors.end(); i++)
        {
            if ((*i)->isActive() && (!(dt % winRefresh) || keyPressed))
            {
                    (*i)->stat();
            }
        }
        if (!(dt % winRefresh) || keyPressed)
            delAllWin();
        for(Itor i = _monitors.begin(); i != _monitors.end(); i++)
        {
            if ((*i)->isActive() && (!(dt % winRefresh) || keyPressed))
            {
                    (*i)->beDisplayed(this);
            }
        }
        refresh();
        while (getch() != ERR)
        ;
        usleep(100000);
    }
}
void NcursesDisplay::display(MultiStrMonitorModule *module)
{
    const std::vector<std::string> & strings = module->getStrings();
    int wh = strings.size() + 4;
    WINDOW *w = newwin(wh, _width, _curHeight, 0);
    _curHeight += wh;
    _windows.push_back(w);
    wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
    mvwprintw(w, 1, 1, module->getName().c_str());
    wmove(w,2,1);
    whline(w, ACS_HLINE, getmaxx(w) - 2);
    for(size_t i = 0; i < strings.size(); i++)
    {
        std::string tmp = strings[i].substr(0, _width - 2);
        mvwprintw(w, 3 + i, 1, tmp.c_str());
    }
    wrefresh(w);
}

void NcursesDisplay::display(ChartMonitorModule<float> *module)
{
    int wh = chartHeight + 4;
    WINDOW *w = newwin(wh, _width, _curHeight, 0);
    _curHeight += wh;
    _windows.push_back(w);
    wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
    mvwprintw(w, 1, 1, module->getName().c_str());
    wmove(w,2,1);
    whline(w, ACS_HLINE, getmaxx(w) - 2);

    int posx = 1;
    for(ChartMonitorModule<float>::iterator i = module->begin(); i != module->end(); i++, posx++)
    {
        int h = (*i) * chartHeight / 100;
        int posy = wh - 2 - h;
        mvwaddch(w, posy, posx, '.');        
    }

    wrefresh(w);
}
