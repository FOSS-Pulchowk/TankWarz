#include "map1.h"

Map1::Map1() {}

void Map1::Create()

{
    map1HBlock[0].setSize(sf::Vector2f( 1258, 0));
    map1HBlock[0].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[0].setPosition(sf::Vector2f(11, 9));
    map1HBlock[0].setOutlineThickness(6);

    map1HBlock[1].setSize(sf::Vector2f( 1258, 0));
    map1HBlock[1].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[1].setPosition(sf::Vector2f(11, 710));
    map1HBlock[1].setOutlineThickness(6);

    map1HBlock[2].setSize(sf::Vector2f( 280, 0));
    map1HBlock[2].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[2].setPosition(sf::Vector2f(185, 205));
    map1HBlock[2].setOutlineThickness(4);

    map1HBlock[3].setSize(sf::Vector2f( 176, 0));
    map1HBlock[3].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[3].setPosition(sf::Vector2f(11, 205));
    map1HBlock[3].setOutlineThickness(4);

    map1HBlock[4].setSize(sf::Vector2f( 130, 0));
    map1HBlock[4].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[4].setPosition(sf::Vector2f(270, 630));
    map1HBlock[4].setOutlineThickness(4);

    map1HBlock[5].setSize(sf::Vector2f( 290, 0));
    map1HBlock[5].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[5].setPosition(sf::Vector2f(400, 400));
    map1HBlock[5].setOutlineThickness(4);

    map1HBlock[6].setSize(sf::Vector2f( 130, 0));
    map1HBlock[6].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[6].setPosition(sf::Vector2f(400, 300));
    map1HBlock[6].setOutlineThickness(4);

    map1HBlock[7].setSize(sf::Vector2f( 200, 0));
    map1HBlock[7].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[7].setPosition(sf::Vector2f(800, 300));
    map1HBlock[7].setOutlineThickness(4);

    map1HBlock[8].setSize(sf::Vector2f( 200, 0));
    map1HBlock[8].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[8].setPosition(sf::Vector2f(100, 300));
    map1HBlock[8].setOutlineThickness(4);

    map1HBlock[9].setSize(sf::Vector2f( 300, 0));
    map1HBlock[9].setOutlineColor(sf::Color(255,255,255));
    map1HBlock[9].setPosition(sf::Vector2f(450, 110));
    map1HBlock[9].setOutlineThickness(4);

    map1VBlock[0].setSize(sf::Vector2f( 0, 700));
    map1VBlock[0].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[0].setPosition(sf::Vector2f(17, 9));
    map1VBlock[0].setOutlineThickness(6);

    map1VBlock[1].setSize(sf::Vector2f( 0, 700));
    map1VBlock[1].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[1].setPosition(sf::Vector2f(1263, 9));
    map1VBlock[1].setOutlineThickness(6);

    map1VBlock[2].setSize(sf::Vector2f( 0, 100));
    map1VBlock[2].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[2].setPosition(sf::Vector2f(130, 404));
    map1VBlock[2].setOutlineThickness(4);

    map1VBlock[3].setSize(sf::Vector2f( 0, 200));
    map1VBlock[3].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[3].setPosition(sf::Vector2f(550, 515));
    map1VBlock[3].setOutlineThickness(4);

    map1VBlock[4].setSize(sf::Vector2f( 0, 200));
    map1VBlock[4].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[4].setPosition(sf::Vector2f(800, 515));
    map1VBlock[4].setOutlineThickness(4);

    map1VBlock[5].setSize(sf::Vector2f( 0, 250));
    map1VBlock[5].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[5].setPosition(sf::Vector2f(693, 250));
    map1VBlock[5].setOutlineThickness(4);

    map1VBlock[6].setSize(sf::Vector2f( 0, 106));
    map1VBlock[6].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[6].setPosition(sf::Vector2f(533, 296));
    map1VBlock[6].setOutlineThickness(4);

    map1VBlock[7].setSize(sf::Vector2f( 0, 106));
    map1VBlock[7].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[7].setPosition(sf::Vector2f(900, 190));
    map1VBlock[7].setOutlineThickness(4);

    map1VBlock[8].setSize(sf::Vector2f( 0, 689));
    map1VBlock[8].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[8].setPosition(sf::Vector2f(1004, 15));     //
    map1VBlock[8].setOutlineThickness(6);

    map1VBlock[9].setSize(sf::Vector2f( 0, 250));
    map1VBlock[9].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[9].setPosition(sf::Vector2f(300, 296));
    map1VBlock[9].setOutlineThickness(4);

    map1VBlock[10].setSize(sf::Vector2f( 0, 100));
    map1VBlock[10].setOutlineColor(sf::Color(255,255,255));
    map1VBlock[10].setPosition(sf::Vector2f(600, 9));
    map1VBlock[10].setOutlineThickness(4);

}

Map1::~Map1() { }

sf::FloatRect Map1::getHBounds(int index) {
    return map1HBlock[index].getGlobalBounds();
}

sf::FloatRect Map1::getVBounds(int index) {
    return map1VBlock[index].getGlobalBounds();
}

void Map1::map1BlockDraw(sf::RenderWindow &map1Window)
{
    for (int i=0; i < maxNoOfHBlock1; i++)
    {
        map1Window.draw(map1HBlock[i]);
    }

    for (int j=0; j < maxNoOfVBlock1; j++)
    {
        map1Window.draw(map1VBlock[j]);
    }

}
