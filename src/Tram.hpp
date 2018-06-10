#ifndef PUBLIC_TRANSPORT_TRAM_HPP
#define PUBLIC_TRANSPORT_TRAM_HPP

#include <SFML/System.hpp>
#include "Vehicle.hpp"

class Tram : public Vehicle {
public:
    explicit Tram(const sf::Vector2f &startingCoordinates);

    void setColor(const sf::Color &color) override;

    void setNextStop(const BusStop &stopCoordinates) override;

    void update(float deltaTime) override;

    void draw(const sf::RenderTarget &renderTarget) const override;

private:
    sf::RectangleShape shape;
    BusStop nextStop;
};


#endif //PUBLIC_TRANSPORT_TRAM_HPP
