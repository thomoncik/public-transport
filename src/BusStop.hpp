#ifndef PUBLIC_TRANSPORT_BUSSTOP_HPP
#define PUBLIC_TRANSPORT_BUSSTOP_HPP


#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Passenger.hpp"

class Passenger;

class BusStop {
public:
    explicit BusStop(const sf::Vector2f &coordinates);

    void addPassenger(const Passenger &passenger);

    void display(sf::RenderTarget &renderTarget);

    void setColor(const sf::Color &color);

    sf::Vector2f getCoordinates();

private:
    std::vector<Passenger> passengersWaiting;
    sf::Vector2f coordinates;
    sf::Color color;
};


#endif //PUBLIC_TRANSPORT_BUSSTOP_HPP
