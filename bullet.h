#include <SFML/Graphics.hpp>

class Bullet
{
  public:
    Bullet(); //constructor
    ~Bullet(); //destructor
    void Create(int, sf::Vector2f, sf::Vector2f); //Create with playerid, direction and initial position
    void Destroy(); //Destroy the bullet
    sf::Vector2f getposition(); //Returns the current position of bullet
    sf::Vector2f getdirection(); // Returns the direction of the bullet
    void setPosition(sf::Vector2f); //Sets the position of the bullet
    void setDirection(float, float); //Sets the direction of the bullet
    void Render(sf::RenderWindow &l_window);

    sf::FloatRect getBounds(); //Get the rectangle bounding box to check the collision

    void Move(); //Move the bullet in the direction
    bool checkUsed(); //Check if the bullet has been used
    bool checkinMotion(); //check if the bullet is in motion

  private:
    sf::CircleShape bulletshape;

    bool m_used = false;
    bool m_inmotion = false;

    int bulletspeed = 5;

    sf::Vector2f m_tankposition;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
};