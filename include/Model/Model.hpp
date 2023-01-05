

#pragma once

#include "Device.hpp"
#include "Singleton.hpp"

#include <memory>
#include <list>

class Model: public Singleton<Model> {
public:
    void addDevice(std::string const& ipAddr, std::string const& deviceName);
    DevicePtr getDeviceByAddr(std::string const& ipAddr);
    std::list<DevicePtr> getDevices() const;
private:
    std::list<DevicePtr> m_devices;
};
