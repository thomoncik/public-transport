#include "Tram.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <utility>

Tram::Tram(const sf::Vector2f &startingCoordinates, std::shared_ptr<Line> line) {
    this->line = std::move(line);

    this->shape.setSize(sf::Vector2f(30, 30));
    this->shape.setOrigin(sf::Vector2f(15, 15));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(startingCoordinates);
}

void Tram::update(float deltaTime) {
    auto offset = this->line->getBusStop(1)->getCoordinates() - this->shape.getPosition();
    auto len = (float) sqrt(offset.x * offset.x + offset.y * offset.y);
    offset = offset / len;

    this->shape.move(offset * deltaTime * 10.0f);
}

void Tram::draw(sf::RenderTarget &renderTarget) const {
    renderTarget.draw(this->shape);
}
