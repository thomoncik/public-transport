//
// Created by thomoncik on 09.06.18.
//

#ifndef PUBLIC_TRANSPORT_SIMULATION_H
#define PUBLIC_TRANSPORT_SIMULATION_H


#include <SFML/Graphics.hpp>

class Simulation {
public:
    unsigned int FRAME_RATE_LIMIT = 60;

    const unsigned int WINDOW_WIDTH = 800;
    const unsigned int WINDOW_HEIGHT = 600;

    const bool WINDOW_FULL_SCREEN = false;
    const char* WINDOW_TITLE = "Public transport simulation";

    Simulation();
    void run();
private:
    sf::RenderWindow window;
    sf::Clock clock;

    void processEvents();
    void update(float deltaTime);
    void render();
};


#endif //PUBLIC_TRANSPORT_SIMULATION_H
