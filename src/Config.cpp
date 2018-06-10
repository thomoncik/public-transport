#include "Config.hpp"
#include <utility>

Config &Config::getInstance() {
    static Config config;
    return config;
}

void Config::parseFile(const std::string &fileName) {
    this->stringValues.clear();
    this->integerValues.clear();
    this->booleanValues.clear();
    this->realValues.clear();
    this->reader = INIReader(fileName);
}

std::string Config::getString(const std::string &section, const std::string &name, const string &defaultValue) {
    std::string key = section + '.' + name;
    if (this->stringValues.find(key) != this->stringValues.end()) {
        return this->stringValues[key];
    }
    return this->reader.Get(section, name, defaultValue);
}

int Config::getInteger(const std::string &section, const std::string &name, int defaultValue) {
    std::string key = section + '.' + name;
    if (this->integerValues.find(key) != this->integerValues.end()) {
        return this->integerValues[key];
    }
    return static_cast<int>(this->reader.GetInteger(section, name, defaultValue));
}

bool Config::getBoolean(const std::string &section, const std::string &name, bool defaultValue) {
    std::string key = section + '.' + name;
    if (this->booleanValues.find(key) != this->booleanValues.end()) {
        return this->booleanValues[key];
    }
    return this->reader.GetBoolean(section, name, defaultValue);
}

float Config::getReal(const std::string &section, const std::string &name, float defaultValue) {
    std::string key = section + '.' + name;
    if (this->realValues.find(key) != this->realValues.end()) {
        return this->realValues[key];
    }
    return static_cast<float>(this->reader.GetReal(section, name, defaultValue));
}

