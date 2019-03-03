#include "sprites.h"

Sprite::Sprite() {}

Sprite::~Sprite() {}

void Sprite::Create(int playerid)
{
    if (playerid == 1)
    {
        m_texture.loadFromFile("images/red_tank.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(1030,50);
    }
    if (playerid == 2)
    {
        m_texture.loadFromFile("images/blue_tank.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(1030,370);
    }
    if (playerid == 3)
    {
        m_texture.loadFromFile("images/green_tank.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(1030,530);
    }
    if (playerid == 4)
    {
        m_texture.loadFromFile("images/magenta_tank.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(1030,210);
    }
}

void Sprite::setPosition(sf::Vector2f position) {m_position=position;}

sf::Vector2f Sprite::getPosition() { return m_position;}

sf::Texture Sprite::getTexture() { return m_texture;}

sf::Sprite Sprite::getSprite() { return m_sprite;}

void Sprite::Render(sf::RenderWindow& l_window)
{
    l_window.draw(m_sprite);
}