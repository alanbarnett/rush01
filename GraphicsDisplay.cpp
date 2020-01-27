/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:14:47 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/26 19:48:00 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicsDisplay.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <string>
#include <algorithm>

GraphicsDisplay::GraphicsDisplay(unsigned int width, unsigned int height): AMonitorDisplay(width, height)
{
	_windowWidth = width * 30;
	_windowHeight = height * 40;
	_vertOffset = 20.0f;
	_horizOffset = 20.0f;
	_titleGap = 20;
	_windowGap = 40;
	_titleSize = 36;
	_textSize = 32;
	_titleColor = sf::Color(100, 120, 140);
	_textColor = sf::Color(200, 220, 240);
}

GraphicsDisplay::~GraphicsDisplay()
{
}

int		GraphicsDisplay::handleKey(char c)
{
	// Either quit the program, or hide the window of the pressed character
	if (c == 'q')
		return (1);
	for (std::map<char, IMonitorModule *>::iterator i = _keyBind.begin();
			i != _keyBind.end(); ++i)
	{
		if (c == i->first)
			i->second->setActive(!i->second->isActive());
	}
	return (0);
}

void	GraphicsDisplay::run()
{
	_window.create(sf::VideoMode(_windowWidth, _windowHeight), "My Window");
	if (!_font.loadFromFile("TerminusTTF-4.46.0.ttf"))
		return ;

	while (_window.isOpen())
	{
		// Set the starting position at the top
		_curHeight = _vertOffset;

		// Event handling
		sf::Event	event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
			// grab entered text
			if (event.type == sf::Event::TextEntered && (event.text.unicode < 128))
				if (handleKey(static_cast<char>(event.text.unicode)) == 1)
					_window.close();
		}

		// Start of main loop (clear, draw, display)
		_window.clear();
		for (iterator i = _monitors.begin(); i != _monitors.end(); ++i)
		{
			if ((*i)->isActive())
			{
				(*i)->stat();
				(*i)->beDisplayed(this);
			}
		}
		_window.display();
		usleep(100000);
	}
}

void	GraphicsDisplay::drawName(IMonitorModule *module)
{
	sf::Text	text;

	text.setFont(_font);
	text.setCharacterSize(_titleSize);
	text.setFillColor(_titleColor);
	text.setPosition(_horizOffset, _curHeight);
	text.setString(module->getName());
	_window.draw(text);
	_curHeight += text.getLocalBounds().height + _titleGap;
}

void GraphicsDisplay::display(MultiStrMonitorModule *module)
{
	sf::Text	text;
	std::string	singlestring;

	// Draw the module title (updates current height)
	drawName(module);

	// Create text object for module
	text.setFont(_font);
	text.setCharacterSize(_textSize);
	text.setFillColor(_textColor);

	// Draw each string
	const std::vector<std::string> & strings = module->getStrings();
	for (size_t i = 0; i < strings.size(); ++i)
	{
		// Get a string, and remove its newlines
		singlestring = strings[i];
		// remove pushes all \n's to after the .end()
		// it returns the new .end(), before all the things it pushed back
		// erase takes the new end and the total end, and deletes that chunk
		singlestring.erase(
				std::remove(singlestring.begin(), singlestring.end(), '\n'),
				singlestring.end());

		text.setPosition(_horizOffset, _curHeight);
		text.setString(singlestring);
		_window.draw(text);
		// Update current height
		_curHeight += text.getLocalBounds().height;
	}

	// Add gap before the next window
	_curHeight += _windowGap;
}

void GraphicsDisplay::display(ChartMonitorModule<float> *module)
{
	size_t	points = module->getSize();
	float	graphHeight = 100;
	float	graphWidth = 400;
	// Initialize x position, and distance between x positions
	float	xPos = _horizOffset;
	float	xDelta = graphWidth / points;
	ChartMonitorModule<float>::iterator	it = module->begin();
	ChartMonitorModule<float>::iterator	it_end = module->end();

	// Make a triangle strip with double points (for bottom and top)
	sf::VertexArray	graph(sf::TriangleStrip, points * 2);

	// Draw title (updates current height)
	drawName(module);

	unsigned int	i;
	for (i = 0, it = module->begin(); it != it_end; i += 2, ++it)
	{
		// Dot for the top of the chart, should be the value
		graph[i].position = sf::Vector2f(xPos, _curHeight + graphHeight - *it);
		// This dot is always the bottom of the graph
		graph[i + 1].position = sf::Vector2f(xPos, _curHeight + graphHeight);

		// Set colors based on value
		graph[i].color = sf::Color(*it, 100 - *it, (xPos / 4));
		graph[i + 1].color = sf::Color(80 + (*it / 2), 140 - (*it / 2), 20 + (xPos / 4));

		// Move to the next x location
		xPos += xDelta;
	}

	// Increase the height based on the graph and the window gap
	_curHeight += graphHeight + _windowGap;

	// Draw the graph
	_window.draw(graph);
}
