#include <SFML/Network.hpp>

class ComputerId
{
private:
  sf::IpAddress ip;
  unsigned short port;

public:
  ComputerId();
  ComputerId(sf::IpAddress, unsigned short);
  void setPort(unsigned short);
  void setIp(sf::IpAddress);
  unsigned short getPort();
  sf::IpAddress getIp();
};
