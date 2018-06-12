#ifndef PUBLIC_TRANSPORT_VEHICLE_H
#define PUBLIC_TRANSPORT_VEHICLE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "BusStop.hpp"
#include "Counted.hpp"
#include "Line.hpp"

class Line;

class Vehicle {
public:
    virtual ~Vehicle() = default;

    virtual void update(float deltaTime) = 0;

    virtual void draw(sf::RenderTarget &renderTarget) const = 0;

protected:
    std::shared_ptr<Line> line;
    int busStopIndex = 0;

    std::shared_ptr<BusStop> getNextStop();
    void nextStop();
};

#endif //PUBLIC_TRANSPORT_VEHICLE_H
