
#include <iostream>
#include "Device.hpp"
#include <InetLib/include/Inet/Socket.hpp>
#include <InetLib/include/Inet/InetAddress.hpp>
#include <cerrno>
#include <cstring>
#include "InetLib/include/SocketReader/SocketReader.hpp"

Device::Device(std::string const& ipAddr, std::string const& deviceName): m_ipAddr(ipAddr),
    m_deviceName(deviceName) {
    id = 0;
}


std::string Device::getDeviceName() const {
    return m_deviceName;
}

std::string Device::getIpAddr() const {
    return m_ipAddr;
}

bool Device::isActivated() const {
    return m_isActivated;
}

void Device::turnOn() {
    InetAddress inetAddr(m_ipAddr, 55443);
    SocketPtr sock = std::make_shared<Socket>(inetAddr, SOCK_TYPE::TCP);

    std::string turnOffMessage = R"({ "id": )" + std::to_string(++id) + R"(, "method": "set_power", "params":["on", "smooth", 300]})";
    turnOffMessage += "\r\n";


    std::cerr << "Connect: " << sock->connect() << " "<< m_ipAddr <<'\n';
    std::cerr << "Send: " <<sock->send(turnOffMessage.data(), turnOffMessage.size()) << '\n';
    sock->send(" ", 1);
    SocketReader socketReader;
   // socketReader.read(sock);
    //std::cerr << "Recv: " << socketReader.getBuffer() << '\n';
}

void Device::turnOff() {
    InetAddress inetAddr(m_ipAddr, 55443);
    SocketPtr sock = std::make_shared<Socket>(inetAddr, SOCK_TYPE::TCP);

    std::string turnOffMessage = R"({ "id": )" + std::to_string(++id) + R"(, "method": "set_power", "params":["off", "smooth", 300]})";
    turnOffMessage += "\r\n";

    std::cerr << "Connect: " << sock->connect() << " "<< m_ipAddr <<'\n';
    std::cerr << "Send: " <<sock->send(turnOffMessage.data(), turnOffMessage.size()) << '\n';
    sock->send(" ", 1);

    SocketReader socketReader;
    //socketReader.read(sock);
    //std::cerr << "Recv: " << socketReader.getBuffer() << '\n';
}

void Device::toggle() {
    std::cerr << m_deviceName <<": toggle \n";
}
