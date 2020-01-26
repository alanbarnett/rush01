#include <SFML/Graphics.hpp>
#include "NcursesDisplay.hpp"
#include <iostream>

void usage(std::ostream &os)
{
	os << "Usage: ft_gkrellm -tui|-gui\n";
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		usage(std::cerr);
		return (1);
	}

	std::string arg = argv[1];
	if (arg == "-tui")
	{
		NcursesDisplay d(40,60);
		d.run();
	}
	else if (arg == "-gui")
	{
		// FIXME: impement GraphicDisplay class
//		GraphicsDisplay d(40,60); 
//		d.run();
	}
	else
	{
		std::cerr << "Unknown argument: " << arg << std::endl;
		usage(std::cerr);
	}
		
    return 0;
}