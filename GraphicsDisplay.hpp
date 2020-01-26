/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:14:48 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/26 10:53:08 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICSDISPLAY_HPP
# define GRAPHICSDISPLAY_HPP

# include "AMonitorDisplay.hpp"
# include "Keyboard.hpp"
# include <vector>
# include <map>

# include <SFML/Graphics.hpp>

class GraphicsDisplay: public AMonitorDisplay
{
	private:
		static const size_t chartHeight = 10; 
		sf::RenderWindow	_window;
		sf::Font			_font;
		float				_position;
		//std::vector<WINDOW*> _windows;
		GraphicsDisplay(const GraphicsDisplay &);
		GraphicsDisplay &operator=(const GraphicsDisplay &);

	public:
		GraphicsDisplay(unsigned int width, unsigned int height);
		~GraphicsDisplay();

		void run();
		void display(MultiStrMonitorModule *);
		void display(ChartMonitorModule<float>*);
};

#endif
