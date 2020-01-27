#include "NetworkStat.hpp"
#include "Utils.hpp"
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <string>


NetworkStat::NetworkStat()
{
    update();
    update();
}
NetworkStat::~NetworkStat() {}

void NetworkStat::update()
{
    runShellCmd("nettop -Jbytes_in,bytes_out -P -l 1 -x > /tmp/netstat.tmp 2>/dev/null");
    std::ifstream in("/tmp/netstat.tmp");
    if (!in)
        return;
    std::string headers;
    getline(in, headers);
    size_t total_received = 0;
    size_t total_sent = 0;
    while (in)
    {
        std::string time;
        std::string process;
        size_t bytes_received = 0;
        size_t bytes_sent = 0;
        in >> time >> process >> bytes_received >> bytes_sent;
        total_received += bytes_received;
        total_sent += bytes_sent;
    }

    time_t cur_time = time(0);
    if (cur_time <= _prev_time)
        return;

    time_t tdelta = cur_time - _prev_time;
    _prev_time = cur_time;
    _rdelta = total_received - _received;
    _sdelta = total_sent - _sent;
    _received = total_received;
    _sent = total_sent;
    _rthrpt = 1.0f * _rdelta / tdelta;
    _sthrpt = 1.0f * _sdelta / tdelta;
}

size_t NetworkStat::getReceiveDelta() const
{
    return _rdelta;
}

size_t NetworkStat::getSentDelta() const
{
    return _sdelta;
}

float NetworkStat::getReceiveThrptKB() const
{
    return _rthrpt / 1024;
}

float NetworkStat::getSentThrptKB() const
{
    return _sthrpt / 1024;
}