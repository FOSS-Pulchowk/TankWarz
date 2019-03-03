#include "menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("fonts/gameFont.ttf"))
    {
        //error handle
    }
    menutext.setFont(font);
    menutext.setColor(sf::Color::Red);
    menutext.setString("TANK WARZ");
    menutext.setPosition(sf::Vector2f(width / 18 - 20, height / (maxNoOfItems+2) *1 - 20));
    menutext.setCharacterSize(60);

    menuText[0].setFont(font);
    menuText[0].setColor(sf::Color::White);
    menuText[0].setString("PLAY");
    menuText[0].setPosition(sf::Vector2f(width / 18, height / (maxNoOfItems+2) *2));
    menuText[0].setCharacterSize(40);

    menuText[1].setFont(font);
    menuText[1].setColor(sf::Color(180,180,180));
    menuText[1].setString("INSTRUCTIONS");
    menuText[1].setPosition(sf::Vector2f(width / 18, height / (maxNoOfItems+2) *3));
    menuText[1].setCharacterSize(40);

    menuText[2].setFont(font);
    menuText[2].setColor(sf::Color(180,180,180));
    menuText[2].setString("HOST A GAME");
    menuText[2].setPosition(sf::Vector2f(width / 18, height / (maxNoOfItems+2) *4));
    menuText[2].setCharacterSize(40);

    menuText[3].setFont(font);
    menuText[3].setColor(sf::Color(180,180,180));
    menuText[3].setString("JOIN A GAME");
    menuText[3].setPosition(sf::Vector2f(width / 18, height / (maxNoOfItems+2) *5));
    menuText[3].setCharacterSize(40);

    menuText[4].setFont(font);
    menuText[4].setColor(sf::Color(180,180,180));
    menuText[4].setString("ABOUT US");
    menuText[4].setPosition(sf::Vector2f(width / 18, height / (maxNoOfItems+2) *6));
    menuText[4].setCharacterSize(40);

    menuText[5].setFont(font);
    menuText[5].setColor(sf::Color(180,180,180));
    menuText[5].setString("EXIT");
    menuText[5].setPosition(sf::Vector2f(width / 18, height / (maxNoOfItems+2) *7));
    menuText[5].setCharacterSize(40);

    selectedItemOfIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i=0; i < maxNoOfItems; i++)
    {
        window.draw(menuText[i]);
    }
    window.draw(menutext);
}

void Menu::moveUp()
{
    if (selectedItemOfIndex-1 >= 0)
    {
        menuText[selectedItemOfIndex].setColor(sf::Color(180,180,180));
        selectedItemOfIndex--;
        menuText[selectedItemOfIndex].setColor(sf::Color::White);
    }
}

void Menu::moveDown()
{
    if (selectedItemOfIndex+1 < maxNoOfItems)
    {
        menuText[selectedItemOfIndex].setColor(sf::Color(180,180,180));
        selectedItemOfIndex++;
        menuText[selectedItemOfIndex].setColor(sf::Color::White);
    }
}
