#ifndef UTILS_HPP
#define UTILS_HPP
#ifdef __linux__
#include <sys/sysinfo.h>
#elif defined(__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#include <libproc.h>
#endif
#include <string>
#include <sstream>
#include <iomanip>

float getCPULoad();

#if defined(__APPLE__)
float getFrequencyGHz();
int getNProcessesEach();
std::string getModelStr();
int getNCoresEach();
int getLogCPUNCoresEach();
int getPhisCPUNCoresEach();

#endif

struct Info
{
    private:
        float activity;
        int processes;
        int cores;
        std::string model;
        float frequency;
        Info(const Info &);
        Info &operator=(const Info &);

    public:
        Info();
        ~Info();
        float getActivity() const;
        int getNProcesses() const;
        int getNCores() const;
        const std::string &getModel() const;
        float getFrequency() const;

};

int runShellCmd(const std::string &command);

template <typename T>
int getSysctl(const char *name, T &t)
{
    size_t len = sizeof(T);
    return sysctlbyname(name, &t, &len, NULL, 0);
}

template <typename T>
std::string toStr(const T &val)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << val;
    return (ss.str());
}

#endif