/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:14:47 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/26 08:58:31 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicsDisplay.hpp"
#include <cstdlib>
#include <unistd.h>
#include <iostream>

GraphicsDisplay::GraphicsDisplay(unsigned int width, unsigned int height): AMonitorDisplay(width, height)
{
	std::cout << "in graphic constructor" << std::endl;
}

GraphicsDisplay::~GraphicsDisplay()
{
	std::cout << "graphics destructor" << std::endl;
}

void GraphicsDisplay::run()
{
	std::cout << "ran!" << std::endl;
	// for (;;)
	// {
	// 	// if (this->_keyboard.isKeyPresed('q'))
	// 	// 	break;
	// 	for(std::map<char, IMonitorModule*>::iterator i = _keyBind.begin(); i != _keyBind.end(); i++)
	// 	{
	// 		if (this->_keyboard.isKeyPresed(i->first))
	// 			i->second->setActive(!i->second->isActive());
	// 	}
	// 	delAllWin();
	// 	for(Itor i = _monitors.begin(); i != _monitors.end(); i++)
	// 	{
	// 		if ((*i)->isActive())
	// 		{
	// 			(*i)->stat();
	// 			(*i)->beDisplayed(this);
	// 		}
	// 	}
	// 	refresh();
	// 	while (getch() != ERR)
	// 	;
	// 	usleep(100000);
	// }
}
void GraphicsDisplay::display(MultiStrMonitorModule *module)
{
	(void)module;
	std::cout << "strings!" << std::endl;
	// const std::vector<std::string> & strings = module->getStrings();
	// int wh = strings.size() + 4;
	// WINDOW *w = newwin(wh, _width, _curHeight, 0);
	// _curHeight += wh;
	// _windows.push_back(w);
	// wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
	// mvwprintw(w, 1, 1, module->getName().c_str());
	// wmove(w,2,1);
	// whline(w, ACS_HLINE, getmaxx(w) - 2);
	// for(size_t i = 0; i < strings.size(); i++)
	// 	mvwprintw(w, 3 + i, 1, strings[i].c_str()); 
	// wrefresh(w);
}

void GraphicsDisplay::display(ChartMonitorModule<float> *module)
{
	(void)module;
	std::cout << "chart!" << std::endl;
	// int wh = chartHeight + 4;
	// WINDOW *w = newwin(wh, _width, _curHeight, 0);
	// _curHeight += wh;
	// _windows.push_back(w);
	// wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
	// mvwprintw(w, 1, 1, module->getName().c_str());
	// wmove(w,2,1);
	// whline(w, ACS_HLINE, getmaxx(w) - 2);

	// int posx = 1;
	// for(ChartMonitorModule<float>::iterator i = module->begin(); i != module->end(); i++, posx++)
	// {
	// 	int h = (*i) * chartHeight / 100;
	// 	int posy = wh - 2 - h;
	// 	mvwaddch(w, posy, posx, '.');		 
	// }

	// wrefresh(w);
}
