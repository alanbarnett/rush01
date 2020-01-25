#include "NcursesDisplay.hpp"

#include "OSMonitorModule.hpp"
#include "CPUloadModule.hpp"
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
    addMonitor('c', new CPUloadModule(width - 2));
    addMonitor('o', new OSMonitorModule());

}

void NcursesDisplay::addMonitor(char key, IMonitorModule* m)
{
    AMonitorDisplay::addMonitor(m);
    _keyBind[key] = m;
}

NcursesDisplay::~NcursesDisplay()
{
    delAllWin();
    endwin();
}

void NcursesDisplay::delAllWin()
{
    for(int i = 0; i < _windows.size(); i++)
    {
        wclear(_windows[i]);
        delwin(_windows[i]);
    }
    _windows.clear();
    _curHeight = 0;
}

void NcursesDisplay::run()
{
    for (;;)
    {
        if (this->_keyboard.isKeyPresed('q'))
            break;
        for(std::map<char, IMonitorModule*>::iterator i = _keyBind.begin(); i != _keyBind.end(); i++)
        {
            if (this->_keyboard.isKeyPresed(i->first))
                i->second->setActive(!i->second->isActive());
        }
        //clear();
        delAllWin();
        refresh();
        for(Itor i = _monitors.begin(); i != _monitors.end(); i++)
        {
            if ((*i)->isActive())
            {
                (*i)->stat();
                (*i)->beDisplayed(this);
            }
        }
        refresh();
        while (getch() != ERR)
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
    for(int i = 0; i < strings.size(); i++)
        mvwprintw(w, 3 + i, 1, strings[i].c_str()); 
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
