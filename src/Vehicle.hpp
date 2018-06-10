#ifndef PUBLIC_TRANSPORT_VEHICLE_H
#define PUBLIC_TRANSPORT_VEHICLE_H

#include <SFML/Graphics.hpp>
#include "BusStop.hpp"

class Vehicle {
public:
    virtual ~Vehicle() = default;

    virtual void setColor(const sf::Color &color) = 0;

    virtual void setNextStop(const BusStop &stopCoordinates) = 0;

    virtual void update(float deltaTime) = 0;

    virtual void draw(const sf::RenderTarget &renderTarget) const = 0;
};

#endif //PUBLIC_TRANSPORT_VEHICLE_H
