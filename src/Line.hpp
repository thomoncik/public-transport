#ifndef PUBLIC_TRANSPORT_LINE_HPP
#define PUBLIC_TRANSPORT_LINE_HPP

#include <vector>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "BusStop.hpp"
#include "SelbaWard/Spline.hpp"
#include "Vehicle.hpp"

class Vehicle;

class Line {
public:
    Line();

    void update(float deltaTime);

    void display(sf::RenderTarget &renderTarget);

    void addBusStop(std::shared_ptr<BusStop> busStop);

    void eraseBusStop(std::shared_ptr<BusStop> busStop);

    unsigned long getBusStopCount();

    std::shared_ptr<BusStop> getBusStop(int index);

    void addVehicle(const std::shared_ptr<Vehicle> &vehicle);

    void eraseVehicle(std::shared_ptr<Vehicle> vehicle);

private:
    std::vector<std::shared_ptr<BusStop>> busStops;
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    sf::Color color;
    sw::Spline shape;
};


#endif //PUBLIC_TRANSPORT_LINE_HPP
