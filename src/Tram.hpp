#ifndef PUBLIC_TRANSPORT_TRAM_HPP
#define PUBLIC_TRANSPORT_TRAM_HPP

#include <SFML/System.hpp>
#include "Vehicle.hpp"

class Tram : public Vehicle {
public:
    explicit Tram(const sf::Vector2f &startingCoordinates, std::shared_ptr<Line> line);

    void update(float deltaTime) override;

    void draw(sf::RenderTarget &renderTarget) const override;

private:
    sf::RectangleShape shape;
};


#endif //PUBLIC_TRANSPORT_TRAM_HPP
