#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Tank
{
  public:
    Tank();

    void Create(int); //Create the tank according to the player no //Sets position, size and color of the tank
    void Destroy(); //Destroys the tank

    sf::Vector2f getPosition(); //Returns the current position of the tank
    void setPosition(sf::Vector2f); //Sets the tank to the current position

    sf::FloatRect getBounds(); //Returns the bounding box to check collision

    void DecreaseHealth(int); //Decrease the health of the player by given amount
    unsigned int getHealth(); //Returns the current health
    void setHealth(unsigned int); //Set the health to this value

    bool checkDestroyed(); //check if the tank has been destroyed 

    void Movement(int); //move the tank to specific direction
    void setAngle(float); //Move the shooter direction to the give angle
    float getAngle();

    void Draw(sf::RenderWindow& l_window);

    void Render(sf::RenderWindow& l_window);
  private:
    sf::RectangleShape tankshape;
    sf::CircleShape circleshape;
    sf::RectangleShape gunshape;

    sf::RectangleShape healthbar;

    sf::Texture bgtexture;
    sf::Sprite bgsprite;
    
    float tankspeed = 3;
    float m_angle;

    sf::Vector2f m_position;

    int m_playerid;
    unsigned int m_health = 100;
    bool m_destroyed = false;

    unsigned int bullet_no;
};