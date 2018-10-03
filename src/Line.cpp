#include "SelbaWard/Spline.hpp"
#include <iostream>
#include <sstream>
#include "Line.hpp"
#include "Config.hpp"
#include "Counted.hpp"

Line::Line() {
    this->shape.setThickness(14);

//    std::cout << "Create line #" << Counted<Line>::getInstancesCount() << std::endl;

    std::stringstream ss;
    ss << Counted<Line>::getInstancesCount();
    std::string s;
    ss >> s;
    std::cout << s << std::endl;
    this->color = sf::Color((sf::Uint32) Config::getInstance().getInteger("line", "color" + s));
    this->shape.setColor(this->color);
}

void Line::update(float deltaTime) {
    for (const auto &vehicle : this->vehicles) {
        vehicle->update(deltaTime);
    }
}

void Line::display(sf::RenderTarget &renderTarget) {
    renderTarget.draw(this->shape);
    for (const auto &busStop : this->busStops) {
        busStop->display(renderTarget);
    }

    for (const auto &vehicle : this->vehicles) {
        vehicle->draw(renderTarget);
    }
}

void Line::addBusStop(std::shared_ptr<BusStop> busStop) {
    busStop->setColor(this->color);
    this->busStops.push_back(busStop);
    this->shape.addVertex(busStop->getCoordinates());
    this->shape.smoothHandles();
    this->shape.update();
}

void Line::eraseBusStop(std::shared_ptr<BusStop> busStop) {
    // erase
    this->shape.update();
}

unsigned long Line::getBusStopCount() {
    return this->busStops.size();
}

std::shared_ptr<BusStop> Line::getBusStop(int index) {
    return this->busStops[index];
}

void Line::addVehicle(std::shared_ptr<Vehicle> vehicle) {
    this->vehicles.push_back(vehicle);
}

void Line::eraseVehicle(std::shared_ptr<Vehicle> vehicle) {
    // erase
}

sf::Color Line::getVehicleColor() {
    return this->color;
}
