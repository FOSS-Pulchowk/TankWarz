#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include <map>
#include <string>

#include "computerId.h"

using namespace std;


class Server
{
private:
  int m_players;
  int m_playerno;

  ComputerId m_computer;

  unsigned short port=2000;
  sf::IpAddress serverIp;
  sf::UdpSocket s_socket;

  char m_buffer[200];
  std::size_t s_received;
  std::string text = "Connected to: ";

  std::vector<ComputerId> players;

  sf::Thread m_listenThread;

  sf::Vector2f m_position;

public:
  Server();

  void setPlayers(int);
  void ReceiveConnection(); //Receive connection from the client
  void ConfirmConnection(sf::IpAddress, unsigned short); //Send connection to the client from which the connection has been received
  void SendPlaySignal(); //Send the signal that all players have joined and it is ready to start the game

  void SendtoOthers(sf::IpAddress, unsigned short, sf::Packet); //Send packet to all players except by whom the packet has been sent
  void Listen(); //Listen to packet from all clients and forward them respectively by invoking send to others

  void Thread(); //Starts the thread

};
