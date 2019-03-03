#include "SFML/Graphics.hpp"
#define maxNoOfItems 6

class Menu
{
 public:
     Menu(float width, float height);
     ~Menu();

     void draw(sf::RenderWindow &window);
     void moveUp();
     void moveDown();
     int getPressedItem() { return selectedItemOfIndex ;}

 private:
    int selectedItemOfIndex;
    sf::Font font;
    sf::Text menuText[maxNoOfItems];
    sf::Text menutext;

};

