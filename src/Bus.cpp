//
// Created by thomoncik on 12.06.18.
//

#include "Bus.hpp"
#include "Config.hpp"
#include <cmath>

Bus::Bus(const sf::Vector2f &startingCoordinates, std::shared_ptr<Line> line) {
    this->line = std::move(line);

    this->shape.setPointCount(4);

    this->shape.setPoint(0, sf::Vector2f(10, 0));
    this->shape.setPoint(1, sf::Vector2f(40, 0));
    this->shape.setPoint(2, sf::Vector2f(30, 30));
    this->shape.setPoint(3, sf::Vector2f(0, 30));

    this->shape.setOrigin(sf::Vector2f(15, 15));
    this->shape.setPosition(startingCoordinates);

    sf::Uint8 r = this->line->getVehicleColor().r - sf::Uint8(80);
    sf::Uint8 g = this->line->getVehicleColor().g - sf::Uint8(80);
    sf::Uint8 b = this->line->getVehicleColor().b - sf::Uint8(80);

    this->shape.setFillColor(sf::Color(r, g, b));
}

void Bus::update(float deltaTime) {
    auto offset = this->getNextStop()->getCoordinates() - this->shape.getPosition();
    if (abs(this->getNextStop()->getCoordinates().x - this->shape.getPosition().x) < 1e-6 && abs(this->getNextStop()->getCoordinates().y - this->shape.getPosition().y) < 1e-6) {
        this->nextStop();
    }

    auto len = (float) sqrt(offset.x * offset.x + offset.y * offset.y);
    offset = offset / len;

    float speed = Config::getInstance().getReal("bus", "speed", 15);
    this->shape.move(offset * deltaTime * speed);
}

void Bus::draw(sf::RenderTarget &renderTarget) const {
    renderTarget.draw(this->shape);
}