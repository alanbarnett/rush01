#ifndef CHARTMONITORMODULE_HPP
#define CHARTMONITORMODULE_HPP

#include "AMonitorModule.hpp"
#include <deque>
#include <string>

template<typename T>
class ChartMonitorModule : public AMonitorModule
{
    public:
        typedef std::deque<T> Container;
        typedef typename Container::iterator iterator;

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
        ChartMonitorModule(const std::string &name, size_t size): AMonitorModule(name), _size(size) {}
        ~ChartMonitorModule() {}
		size_t	getSize()
		{
			return (_size);
		}
        iterator begin()
        {
            return (_data.begin());
        }

        iterator end()
        {
            return (_data.end());
        }
};

#endif
