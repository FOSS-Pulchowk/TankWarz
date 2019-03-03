#include "SFML/Graphics.hpp"
#define maxNoOfHBlock1 10
#define maxNoOfVBlock1 11

class Map1
{
  public:
    Map1();
    void Create();
    Map1(float map1Width, float map1Height);
    ~Map1();
    void map1BlockDraw(sf::RenderWindow &map1Window);
    sf::FloatRect getHBounds(int);
    sf::FloatRect getVBounds(int);

  private:
    sf::RectangleShape map1HBlock[maxNoOfHBlock1];
    sf::RectangleShape map1VBlock[maxNoOfVBlock1];
};
