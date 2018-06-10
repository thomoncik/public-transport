#include "Simulation.hpp"
#include "Config.hpp"

Simulation::Simulation() : window(sf::VideoMode::getDesktopMode(), "",
                                  (WINDOW_FULL_SCREEN) ? sf::Style::Fullscreen : sf::Style::Default) {
    Config::getInstance().parseFile(CONFIG_FILE_NAME);

    this->window.setFramerateLimit(Config::getInstance().getInteger("window", "framerate_limit", 60));
    this->window.setTitle(Config::getInstance().getString("window", "title"));

    this->init();
}

void Simulation::init() {
    Line a;
//    this->lines.push_back(Line())
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
    int color = Config::getInstance().getInteger("window", "background_color");
    this->window.clear(sf::Color(static_cast<sf::Uint32>(color)));
//    this->window.draw(...);
    this->window.display();
}
