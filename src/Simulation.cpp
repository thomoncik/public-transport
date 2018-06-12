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
    auto t2 = std::make_shared<Tram>(bs4->getCoordinates(), lineA);
    lineA->addVehicle(t1);
    lineA->addVehicle(t2);


    auto lineB = std::make_shared<Line>();

    auto bsb1 = std::make_shared<BusStop>(sf::Vector2f(1000, 450));
    auto bsb2 = std::make_shared<BusStop>(sf::Vector2f(600, 200));
    auto bsb3 = std::make_shared<BusStop>(sf::Vector2f(400, 300));
    auto bsb4 = std::make_shared<BusStop>(sf::Vector2f(600, 500));

    lineB->addBusStop(bsb1);
    lineB->addBusStop(bsb2);
    lineB->addBusStop(bsb3);
    lineB->addBusStop(bsb4);
    lineB->addBusStop(bsb1);

    auto tb1 = std::make_shared<Tram>(bsb1->getCoordinates(), lineB);
    lineB->addVehicle(tb1);


    auto lineC = std::make_shared<Line>();
    this->lines.push_back(lineC);

    auto bsc1 = std::make_shared<BusStop>(sf::Vector2f(1200, 50));
    auto bsc2 = std::make_shared<BusStop>(sf::Vector2f(600, 200));
    auto bsc3 = std::make_shared<BusStop>(sf::Vector2f(900, 20));

    lineC->addBusStop(bsc1);
    lineC->addBusStop(bsc2);
    lineC->addBusStop(bsc3);
    lineC->addBusStop(bsc1);

    auto tc1 = std::make_shared<Tram>(bsc1->getCoordinates(), lineC);
    lineC->addVehicle(tc1);
    this->lines.push_back(lineB);
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
