#include "Utils.hpp"
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>

int runShellCmd(const std::string &command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        std::cerr << "FORK Error: " << std::strerror(errno);
        exit(1);
    }

    if (pid == 0)
    {
        // Child process
        const char *cmd[] = {
            "sh",
            "-c",
            command.c_str(),
            0};
        execvp(cmd[0], const_cast<char *const *>(cmd));
        std::cerr << "EXEC Error: " << std::strerror(errno);
    }

    // Parent process
    int status = 0;
    waitpid(pid, &status, 0);
    return status;
}

Info::Info()
{
    activity = getCPULoad();

#if defined(__linux__)
    struct sysinfo in;
    sysinfo(&in);
    processes = in.procs;
    cores = get_nprocs();
    model = "unknow";
    freqency = 0;

#elif defined(__APPLE__)

    processes = getNProcessesEach();
    cores = getNCoresEach();
    model = getModelStr();
    frequency = getFrequencyGHz();

#endif
}

Info::~Info() {}

float Info::getActivity() const
{
    return activity;
}
int Info::getNProcesses() const
{
    return processes;
}
int Info::getNCores() const
{
    return cores;
}
const std::string &Info::getModel() const
{
    return model;
}
float Info::getFrequency() const
{
    return frequency;
}

#if defined(__linux__)

float getCPULoad()
{
    struct sysinfo inf;
    sysinfo(&inf);
    float f = 1.f / (1 << SI_LOAD_SHIFT);
    float loadp = inf.loads[0] * f * 100 / get_nprocs();
    return (loadp);
}

#elif defined(__APPLE__)

float getCPULoad()
{
    struct loadavg load;

    getSysctl("vm.loadavg", load);
    float loadp = 1.0f * load.ldavg[0] / load.fscale;
    return (loadp);
}

int getNCoresEach()
{
    int ncpu = 0;
    getSysctl("hw.ncpu", ncpu);
    return ncpu;
}

std::string getModelStr()
{
    char buf[256];
    getSysctl("machdep.cpu.brand_string", buf);
    return std::string(buf);
}

int getNProcessesEach()
{
    int pidCount = proc_listallpids(NULL, 0);
	return pidCount - 19;
}

float getFrequencyGHz()
{
    long freq = 0;
    getSysctl("hw.cpufrequency", freq);
    return freq * 1.e-9;
}
#endif
