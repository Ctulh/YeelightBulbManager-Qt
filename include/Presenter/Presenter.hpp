
#pragma once

#include <string>
#include <map>
#include <vector>

#include "Publisher.hpp"
#include <list>
#include "Model/Device.hpp"
#include "Model/Singleton.hpp"

class Presenter: public Publisher, public Singleton<Presenter> {
public:
    void addDevice(std::string const& ipAddr, std::string const& deviceName);
    void turnOffDevice(std::string const& deviceName);
    void turnOnDevice(std::string const& deviceName);
    std::list<DevicePtr> getDevices() const;
};
