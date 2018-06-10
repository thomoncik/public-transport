#include "BusStop.hpp"

BusStop::BusStop(const sf::Vector2f &coordinates) : coordinates(coordinates) {
}

void BusStop::addPassenger(const Passenger &passenger) {
    this->passengersWaiting.push_back(passenger);
}

sf::Vector2f BusStop::getCoordinates() {
    return this->coordinates;
}
