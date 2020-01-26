#include "NcursesDisplay.hpp"
#include "NameMonitorModule.hpp"
#include "DateMonitorModule.hpp"
#include "OSMonitorModule.hpp"
#include "CPUloadModule.hpp"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <errno.h>

// void runCmd(const std::vector<std::string> &cmdArg)
// {
// 	pid_t pid = fork();
// 	if (pid == -1)
// 	{
// 		std::cerr << "fork faled\n";
// 		return;
// 	}
// 	if (pid == 0)
// 	{
// 		const char *cmd = cmdArg[0].c_str();
// 		const char *args[cmdArg.size()];

// 		for (size_t i = 1; i < cmdArg.size(); i++)
// 			args[i-1] = cmdArg[i].c_str();
// 		args[cmdArg.size() - 1] = 0;

// 		if (execv(cmd, const_cast<char*const*>(args)) == -1)
// 			std::cerr << "execl faled: " << std::strerror(errno);
// 		//child procces
// 		return;
// 	}
// 	//parent procces
// }

// int main()
// {
// 	std::vector<std::string> cmd;
// 	cmd.push_back("/bin/sh");
// 	cmd.push_back("");
// 	cmd.push_back("-c");
// 	cmd.push_back("/bin/ls -laF > ttt 2>/dev/null");
// 	runCmd(cmd);
// 	return(0);
// }
 
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
		// FIXME: impement GraphicDisplay class
		disp = new NcursesDisplay(WIDTH, HEIGHT);
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
	disp->addMonitorWithKey('l', new CPUloadModule(WIDTH - 2));

	disp->run();

	delete disp;
	return 0;
}
