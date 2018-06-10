#ifndef PUBLIC_TRANSPORT_PASSENGER_HPP
#define PUBLIC_TRANSPORT_PASSENGER_HPP


#include "BusStop.hpp"

class BusStop;

class Passenger {
private:
    std::shared_ptr<BusStop> desiredBusStop;
};


#endif //PUBLIC_TRANSPORT_PASSENGER_HPP
