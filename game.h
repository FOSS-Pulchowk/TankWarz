#include "Window.h"
#include "tank.h"
#include "bullet.h"
#include "map1.h"
#include "sprites.h"

#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class Game
{
  public:
	Game();
	Game(int, int);
	~Game();

	void HandleTankMovements(); //Handle the input (includes movement of tank and mouse)
	void Update(); //1. Update the position of bullets 2. Check if the tank has been destroyed 
	void Render(); //Render all the game objects in the window
	void CheckCollision();
	bool CheckCollision(Tank, Map1);
	bool CheckCollision(Bullet &, unsigned int, Map1);
	void CheckDamage();

	sf::Packet getState(); //Gets the position of tank, direction of bullet, no of bullets shot and health of the player

	void setOtherPlayers(int, sf::Vector2f, float, unsigned int, int, sf::Vector2f); //Sets the position of other players' tank position, bullet direction and health
	float GetDistance(float, float); //not important
	float GetSlope(float, float, float, float); //not important

	void CheckWinner(); 

bool gameover=false;

	Window *GetWindow();

  private:
	Window m_window;

	int m_totalplayers;
	int m_playerid;

	unsigned int count = 0;
	unsigned int counter = 0;
	unsigned int bulletspeed = 5;
	unsigned int m_maxCollision = 5;

	sf::SoundBuffer hitsoundbuffer;
	sf::Sound hitsound;
	sf::SoundBuffer collisionsoundbuffer;
	sf::Sound collisionsound;
	sf::SoundBuffer bulletshotbuffer;
	sf::Sound bulletshotsound;

	bool m_Collision = false;
	Tank tanks[10];
	Sprite sprites[10];
	Map1 m_map;
	Bullet bullets[1000];

	int BulletCounter[10];
	unsigned int BulletCollision[1000];

	bool isWinner = false;
};