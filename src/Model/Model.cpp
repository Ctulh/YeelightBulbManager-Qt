
#include "Model.hpp"
#include <algorithm>
#include "Device.hpp"



void Model::addDevice(std::string const& ipAddr, std::string const& deviceName) {
    m_devices.push_back(std::make_shared<Device>(ipAddr, deviceName));
}

DevicePtr Model::getDeviceByAddr(std::string const& ipAddr) {
    auto it = std::find_if(m_devices.begin(), m_devices.end(), [&ipAddr](auto device){ return device->getIpAddr() == ipAddr;});
    if(it == m_devices.end()) {
        return nullptr;
    }
    return *it;
}

std::list<DevicePtr> Model::getDevices() const {
    return m_devices;
}
