#include "Tram.hpp"
#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <utility>

Tram::Tram(const sf::Vector2f &startingCoordinates, std::shared_ptr<Line> line) {
    this->line = std::move(line);

    this->shape.setSize(sf::Vector2f(30, 30));
    this->shape.setOrigin(sf::Vector2f(15, 15));
    this->shape.setPosition(startingCoordinates);

    sf::Uint8 r = this->line->getVehicleColor().r - sf::Uint8(50);
    sf::Uint8 g = this->line->getVehicleColor().g - sf::Uint8(50);
    sf::Uint8 b = this->line->getVehicleColor().b - sf::Uint8(50);

    this->shape.setFillColor(sf::Color(r, g, b));
}

void Tram::update(float deltaTime) {
    auto offset = this->getNextStop()->getCoordinates() - this->shape.getPosition();
//    std::cout << this->getNextStop()->getCoordinates().x << " " << this->getNextStop()->getCoordinates().y << " " << this->shape.getPosition().x << " " << this->shape.getPosition().y << std::endl;
    if (abs(this->getNextStop()->getCoordinates().x - this->shape.getPosition().x) < 1e-6 && abs(this->getNextStop()->getCoordinates().y - this->shape.getPosition().y) < 1e-6) {
        this->nextStop();
    }

    auto len = (float) sqrt(offset.x * offset.x + offset.y * offset.y);
    offset = offset / len;

    float speed = Config::getInstance().getReal("tram", "speed", 25);
    this->shape.move(offset * deltaTime * speed);
}

void Tram::draw(sf::RenderTarget &renderTarget) const {
    renderTarget.draw(this->shape);
}
