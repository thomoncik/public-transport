#include "Simulation.hpp"
#include "Config.hpp"
#include "Tram.hpp"

Simulation::Simulation() : window(sf::VideoMode::getDesktopMode(), "",
                                  (WINDOW_FULL_SCREEN) ? sf::Style::Fullscreen : sf::Style::Default) {
    Config::getInstance().parseFile(CONFIG_FILE_NAME);

    this->window.setFramerateLimit(Config::getInstance().getInteger("window", "framerate_limit", 60));
    this->window.setTitle(Config::getInstance().getString("window", "title"));

    this->init();
}

void Simulation::init() {
    auto lineA = std::make_shared<Line>();
    this->lines.push_back(lineA);

    auto bs1 = std::make_shared<BusStop>(sf::Vector2f(10, 10));
    auto bs2 = std::make_shared<BusStop>(sf::Vector2f(250, 100));
    auto bs3 = std::make_shared<BusStop>(sf::Vector2f(800, 600));
    auto bs4 = std::make_shared<BusStop>(sf::Vector2f(400, 500));
    lineA->addBusStop(bs1);
    lineA->addBusStop(bs2);
    lineA->addBusStop(bs3);
    lineA->addBusStop(bs4);
    lineA->addBusStop(bs1);

    auto t1 = std::make_shared<Tram>(bs1->getCoordinates(), lineA);
    lineA->addVehicle(t1);
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
    for (const auto &line : lines) {
        line->update(deltaTime);
    }
}

void Simulation::render() {
    int color = Config::getInstance().getInteger("window", "background_color");
    this->window.clear(sf::Color(static_cast<sf::Uint32>(color)));

    for (auto &line : lines) {
        line->display(this->window);
    }

    this->window.display();
}
