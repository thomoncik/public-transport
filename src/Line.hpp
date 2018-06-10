#ifndef PUBLIC_TRANSPORT_LINE_HPP
#define PUBLIC_TRANSPORT_LINE_HPP


// line is determined by it's starting and ending point as well as
// by it's middle points (bus stops)

// line is connected with vehicles using Schedule class

// need to provide some sort of asking function
// when vehicle ask it will respond with it's next step

#include <list>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "BusStop.hpp"

class Line {
public:
    Line();

    void draw(const sf::RenderTarget &renderTarget);

    void addBusStop(const BusStop &busStop);

    void eraseBusStop(const BusStop &busStop);

private:
    std::list<BusStop> busStops;
    sf::Color color;

};


#endif //PUBLIC_TRANSPORT_LINE_HPP
