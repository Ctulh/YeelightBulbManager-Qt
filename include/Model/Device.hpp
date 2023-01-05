
#pragma once

#include <string>
#include <memory>

class Device {
public:
    Device(std::string const& ipAddr, std::string const& deviceName);

public:
    std::string getIpAddr() const;
    std::string getDeviceName() const;
    bool isActivated() const;

    void turnOff();
    void turnOn();
    void toggle();

private:
    std::string m_ipAddr;
    std::string m_deviceName;
    bool m_isActivated;
};

using DevicePtr = std::shared_ptr<Device>;
