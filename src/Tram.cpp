#include "Tram.hpp"
#include <SFML/Graphics.hpp>

Tram::Tram(const sf::Vector2f &startingCoordinates) : nextStop(startingCoordinates) {
//    this->shape.setSize()
//    this->shape.setOrigin();
    this->shape.setPosition(startingCoordinates);
}


void Tram::setColor(const sf::Color &color) {
    this->shape.setFillColor(color);
}

void Tram::setNextStop(const BusStop &stopCoordinates) {
    this->nextStop = stopCoordinates;
}

void Tram::update(float deltaTime) {
    auto offset = this->nextStop.getCoordinates() - this->shape.getPosition();
    this->shape.move(offset * deltaTime);
}

void Tram::draw(const sf::RenderTarget &renderTarget) const  {

}
