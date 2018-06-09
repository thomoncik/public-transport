//
// Created by thomoncik on 09.06.18.
//

#include "Simulation.h"

Simulation::Simulation() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE,
                                  (WINDOW_FULL_SCREEN) ? sf::Style::Fullscreen : sf::Style::Default) {
    this->window.setFramerateLimit(Simulation::FRAME_RATE_LIMIT);
}

void Simulation::run() {
    while (this->window.isOpen()) {
        sf::Time deltaTime = this->clock.restart();

        this->processEvents();
        this->update(deltaTime.asSeconds());
        this->render();
    }
}

void Simulation::processEvents() {
    sf::Event event{};

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->window.close();
        }
    }
}

void Simulation::update(float deltaTime) {

}

void Simulation::render() {
    this->window.clear();
//    this->window.draw(...);
    this->window.display();
}
