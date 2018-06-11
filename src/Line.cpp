#include <SelbaWard/Spline.hpp>
#include "Line.hpp"
#include "Config.hpp"

Line::Line() {
    this->shape.setThickness(14);
    auto fillColor = (unsigned int) Config::getInstance().getInteger("bus_stop", "fill_color", 0x000000ff);
    this->shape.setColor(sf::Color(fillColor));
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
    this->busStops.push_back(busStop);
    this->shape.addVertex(busStop->getCoordinates());
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

void Line::addVehicle(const std::shared_ptr<Vehicle> &vehicle) {
    this->vehicles.push_back(vehicle);
}

void Line::eraseVehicle(std::shared_ptr<Vehicle> vehicle) {
    // erase
}
