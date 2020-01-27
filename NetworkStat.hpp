#ifndef NETWORKSTAT_HPP
#define NETWORKSTAT_HPP
#include <cstdlib>
#include <ctime>

class NetworkStat
{
private:
    time_t _prev_time;
    size_t _received;
    size_t _sent;
    size_t _rdelta;
    size_t _sdelta;
    float _rthrpt;
    float _sthrpt;
    NetworkStat(const NetworkStat&);
    NetworkStat &operator=(const NetworkStat&);

public:
    NetworkStat();
    ~NetworkStat();

    void update();
    size_t getReceiveDelta() const;

    size_t getSentDelta() const;

    float getReceiveThrptKB() const;

    float getSentThrptKB() const;
};
#endif