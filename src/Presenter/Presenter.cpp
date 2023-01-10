
#include <Presenter.hpp>
#include "Model/Model.hpp"
#include <list>
#include <iostream>

void Presenter::addDevice(const std::string &ipAddr, const std::string &deviceName) {
    Model::getInstance().addDevice(ipAddr, deviceName);
    notify("new device");
}

std::list<DevicePtr> Presenter::getDevices() const {
    return Model::getInstance().getDevices();
}


void Presenter::turnOffDevice(const std::string &deviceName) {
    auto devices = Model::getInstance().getDevices();
    for(auto device: devices) {
        if(device->getDeviceName() == deviceName)
            device->turnOff();
    }
}

void Presenter::turnOnDevice(const std::string &deviceName) {
    auto devices = Model::getInstance().getDevices();
    for(auto device: devices) {
        if(device->getDeviceName() == deviceName)
            device->turnOn();
    }
}
