
#include <Presenter.hpp>
#include "Model/Model.hpp"
#include <list>

void Presenter::addDevice(const std::string &ipAddr, const std::string &deviceName) {
    Model::getInstance().addDevice(ipAddr, deviceName);
    notify("new device");
}

std::list<DevicePtr> Presenter::getDevices() const {
    return Model::getInstance().getDevices();
}


void Presenter::turnOffDevice(const std::string &ipAddr) {
    auto devices = Model::getInstance().getDevices();
    for(auto device: devices) {
        if(device->getIpAddr() == ipAddr)
            device->turnOff();
    }
}

void Presenter::turnOnDevice(const std::string &ipAddr) {
    auto devices = Model::getInstance().getDevices();
    for(auto device: devices) {
        if(device->getIpAddr() == ipAddr)
            device->turnOn();
    }
}
