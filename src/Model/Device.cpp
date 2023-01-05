
#include <iostream>
#include "Device.hpp"

Device::Device(std::string const& ipAddr, std::string const& deviceName): m_ipAddr(ipAddr),
    m_deviceName(deviceName) {}


std::string Device::getDeviceName() const {
    return m_deviceName;
}

std::string Device::getIpAddr() const {
    return m_ipAddr;
}

bool Device::isActivated() const {
    return m_isActivated;
}

void Device::turnOff() {
    std::cerr << m_deviceName <<": turnOff \n";
}

void Device::turnOn() {
    std::cerr << m_deviceName <<": turnOn \n";
}

void Device::toggle() {
    std::cerr << m_deviceName <<": toggle \n";
}
