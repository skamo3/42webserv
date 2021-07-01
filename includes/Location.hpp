#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "base.hpp"

class Location
{
    private:

    public:
        Location();
        Location(const Location &other);
        Location &operator=(const Location &other);
        ~Location();
};

#endif