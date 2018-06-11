#include <SFML/Graphics/CircleShape.hpp>
#include "BusStop.hpp"
#include "Config.hpp"

BusStop::BusStop(const sf::Vector2f &coordinates) : coordinates(coordinates) {
}

void BusStop::addPassenger(const Passenger &passenger) {
    this->passengersWaiting.push_back(passenger);
}

void BusStop::display(sf::RenderTarget &renderTarget) {
    sf::CircleShape shape(14);
    shape.setOrigin(14, 14);
    shape.setOutlineThickness(3.5);
    auto fillColor = (unsigned int) Config::getInstance().getInteger("bus_stop", "fill_color", 0x000000ff);
    auto outlineColor = (unsigned int) Config::getInstance().getInteger("bus_stop", "outline_color", 0x000000ff);
    shape.setFillColor(sf::Color(fillColor));
    shape.setOutlineColor(sf::Color(outlineColor));
    shape.setPosition(this->coordinates);
    renderTarget.draw(shape);
}

sf::Vector2f BusStop::getCoordinates() {
    return this->coordinates;
}
