
#pragma once

#include <string>

class Subscriber {
public:
    virtual ~Subscriber() = default;

public:
    virtual void update(std::string const& message) = 0;
};
