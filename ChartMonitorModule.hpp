#ifndef MULTISTRMONITORMODULE_HPP
#define MULTISTRMONITORMODULE_HPP

#include "AMonitorModule.hpp"
#include <deque>
#include <string>

template<typename T>
class ChartMonitorModule : public AMonitorModule
{
    public:
        typedef std::deque<T> Container;
        typedef Container::const_iterator const_iterator;

    protected:
        Container _data;
        void addData(const T& elm)
        {
            _data.push_back(elm);
            if (_data.size() > _size)
                _data.pop_front();
        }

    private:
        const size_t _size;
        ChartMonitorModule(const ChartMonitorModule &);
        ChartMonitorModule &operator=(const ChartMonitorModule &);

    public:
        ChartMonitorModule(size_t size): _size(size) {}
        ~ChartMonitorModule() {}
        const_iterator cbegin() const
        {
            return (_data.cbegin());
        }

        const_iterator cend() const
        {
            return (_data.cend());
        }
};

#endif