#include "Vehicle.hpp"

std::shared_ptr<BusStop> Vehicle::getNextStop() {
    int foo = this->busStopIndex + 1;
    if (foo >= this->line->getBusStopCount()) {
        foo = 0;
    }
    return this->line->getBusStop(foo);
}
