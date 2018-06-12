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
    if (this->stringValues.find(key) == this->stringValues.end()) {
        this->stringValues[key] = this->reader.Get(section, name, defaultValue);
    }

    return this->stringValues[key];
}

int Config::getInteger(const std::string &section, const std::string &name, int defaultValue) {
    std::string key = section + '.' + name;
    if (this->integerValues.find(key) == this->integerValues.end()) {
        this->integerValues[key] = static_cast<int>(this->reader.GetInteger(section, name, defaultValue));
    }
    return this->integerValues[key];
}

bool Config::getBoolean(const std::string &section, const std::string &name, bool defaultValue) {
    std::string key = section + '.' + name;
    if (this->booleanValues.find(key) == this->booleanValues.end()) {
        this->booleanValues[key] = this->reader.GetBoolean(section, name, defaultValue);
    }
    return this->booleanValues[key];
}

float Config::getReal(const std::string &section, const std::string &name, float defaultValue) {
    std::string key = section + '.' + name;
    if (this->realValues.find(key) == this->realValues.end()) {
        this->realValues[key] = static_cast<float>(this->reader.GetReal(section, name, defaultValue));
    }
    return this->realValues[key];
}

