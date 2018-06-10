#ifndef PUBLIC_TRANSPORT_CONFIGSTORE_HPP
#define PUBLIC_TRANSPORT_CONFIGSTORE_HPP

#include "INIReader.h"

class Config {
public:
    static Config &getInstance();

    void parseFile(const std::string &fileName);

    std::string getString(const std::string &section, const std::string &name, const std::string &defaultValue = "");

    int getInteger(const std::string &section, const std::string &name, int defaultValue = 0);

    bool getBoolean(const std::string &section, const std::string &name, bool defaultValue = false);

    float getReal(const std::string &section, const std::string &name, float defaultValue = 0.0f);

private:
    INIReader reader;

    Config() = default;

    Config(const Config &) = default;

    Config(Config &&) = default;

    Config &operator=(const Config &) = default;

    Config &operator=(Config &&) = default;
};


#endif //PUBLIC_TRANSPORT_CONFIGSTORE_HPP
