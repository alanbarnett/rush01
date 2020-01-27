#include "NcursesDisplay.hpp"
#include "GraphicsDisplay.hpp"
#include "NameMonitorModule.hpp"
#include "OSMonitorModule.hpp"
#include "DateMonitorModule.hpp"
#include "CPUMonitorModule.hpp"
#include "RAMMonitorModule.hpp"
#include "CPUloadModule.hpp"
#include "RAMloadModule.hpp"
#include "NetworkMonitorModule.hpp"
#include "UnicornMonitorModule.hpp"
#include "UsageMonitorModule.hpp"
#include <iostream>
#include <string>

#define WIDTH 40
#define HEIGHT 60

void usage(std::ostream &os)
{
	os << "Usage: ft_gkrellm -tui|-gui\n";
}

int	main(int argc, char **argv)
{
	AMonitorDisplay	*disp;

	if (argc != 2)
	{
		usage(std::cerr);
		return (1);
	}

	std::string	arg(argv[1]);
	if (arg == "-tui")
	{
		disp = new NcursesDisplay(WIDTH, HEIGHT);
	}
	else if (arg == "-gui")
	{
		disp = new GraphicsDisplay(WIDTH, HEIGHT);
	}
	else
	{
		std::cerr << "Unknown argument: " << arg << std::endl;
		usage(std::cerr);
		return (1);
	}

	disp->addMonitorWithKey('n', new NameMonitorModule());
	disp->addMonitorWithKey('o', new OSMonitorModule());
	disp->addMonitorWithKey('d', new DateMonitorModule());
	disp->addMonitorWithKey('c', new CPUMonitorModule());
	disp->addMonitorWithKey('r', new RAMMonitorModule());
	disp->addMonitorWithKey('l', new CPUloadModule(WIDTH - 2));
	disp->addMonitorWithKey('L', new RAMloadModule(WIDTH - 2));
	disp->addMonitorWithKey('k', new NetworkMonitorModule());
	disp->addMonitorWithKey('z', new UnicornMonitorModule());
	disp->addMonitorWithKey('u', new UsageMonitorModule());

	disp->run();

	delete disp;
	return 0;
}
