#include "Config.hpp"
#include <utility>

Config &Config::getInstance() {
    static Config config;
    return config;
}

void Config::parseFile(const std::string &fileName) {
    this->reader = INIReader(fileName);
}

std::string Config::getString(const std::string &section, const std::string &name, const string &defaultValue) {
    return this->reader.Get(section, name, defaultValue);
}

int Config::getInteger(const std::string &section, const std::string &name, int defaultValue) {
    return static_cast<int>(this->reader.GetInteger(section, name, defaultValue));
}

bool Config::getBoolean(const std::string &section, const std::string &name, bool defaultValue) {
    return this->reader.GetBoolean(section, name, defaultValue);
}

float Config::getReal(const std::string &section, const std::string &name, float defaultValue) {
    return static_cast<float>(this->reader.GetReal(section, name, defaultValue));
}

