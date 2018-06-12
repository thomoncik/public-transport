//
// Created by thomoncik on 12.06.18.
//

#ifndef PUBLIC_TRANSPORT_BUS_HPP
#define PUBLIC_TRANSPORT_BUS_HPP


#include "Vehicle.hpp"

class Bus : public Vehicle {
public:
    explicit Bus(const sf::Vector2f &startingCoordinates, std::shared_ptr<Line> line);

    void update(float deltaTime) override;

    void draw(sf::RenderTarget &renderTarget) const override;

private:
    sf::ConvexShape shape;
};


#endif //PUBLIC_TRANSPORT_BUS_HPP
