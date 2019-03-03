#include "computerId.h"


ComputerId::ComputerId() {}
ComputerId::ComputerId(sf::IpAddress address, unsigned short portno)
{
    ip = address;
    port = portno;
}
void ComputerId::setIp(sf::IpAddress address) {ip = address;}
void ComputerId::setPort(unsigned short portno) {port = portno;}
sf::IpAddress ComputerId::getIp() {return ip;}
unsigned short ComputerId::getPort() {return port;}