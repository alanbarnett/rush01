#ifndef UTILS_HPP
#define UTILS_HPP
#ifdef __linux__
#include <sys/sysinfo.h>
#elif defined (__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
#include <string>
#include <sstream>
#include <iomanip>

float getCPULoad();

#if defined (__APPLE__)
float getFrequencyGHz();
void getNProcesses();
std::string getModel();
int getNCores();

#endif


struct Info
{   float activity;
    int processes;
    int cores;
    std::string model;
    float freqency;
    Info()
    {
        activity = getCPULoad();

        #if defined (__linux__)
        struct sysinfo in;
        sysinfo(&in);
        processes = in.procs;
        cores = get_nprocs();
        model = "unknow";

        // need add model ans friq
        #elif defined (__APPLE__)

        processes = getNprocesses();
        cores = getNCores();
        model = getModel();
        frequency = getFrequencyGHz();
        #endif

    }
};

template <typename T> std::string toStr(const T &val)
{
    std::stringstream ss;
    ss << std::setprecision(4) << val;
    return (ss.str());
}

#endif