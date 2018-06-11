#ifndef PUBLIC_TRANSPORT_SIMULATION_H
#define PUBLIC_TRANSPORT_SIMULATION_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "Line.hpp"

class Simulation {
public:
    static const bool WINDOW_FULL_SCREEN = false;
    static constexpr const char *CONFIG_FILE_NAME = "config.ini";

    Simulation();

    void run();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<std::shared_ptr<Line>> lines;

    void init();

    void processEvents();

    void update(float deltaTime);

    void render();
};

#endif //PUBLIC_TRANSPORT_SIMULATION_H
