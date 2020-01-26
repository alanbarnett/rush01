#include "Utils.hpp"

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

template <typename T>
int getSysctl(const char *name, T &t)
{
    size_t len = sizeof(T);
    return sysctlbyname(name, &t, &len, NULL, 0);
}

float getCPULoad()
{
    struct loadavg load;
    
    getSysctl("vm.loadavg", load);
    float loadp = 1.0f * load.ldavg[0] / load.fscale;
    return (loadp);
}

int getNCores()
{
    int ncpu = 0;
    getSysctl("hw.ncpu", ncpu);
    return ncpu;
}

std::string getModel()
{
    char buf[256];
    getSysctl("machdep.cpu.brand_string", buf);
    return std::string(buf);
}

void getNProcesses()
{
}
float getFrequencyGHz()
{
    long freq = 0;
    getSysctl("hw.cpufrequency", freq);
    return freq * 1.e-9;
}
#endif
