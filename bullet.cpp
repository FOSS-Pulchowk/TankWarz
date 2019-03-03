#include "bullet.h"
#include <iostream>
Bullet::Bullet()
{
    bulletshape.setRadius(5);
    bulletshape.setOrigin({2.5, 2.5});
    bulletshape.setOutlineColor(sf::Color::Black);
    bulletshape.setOutlineThickness(3);
}

Bullet::~Bullet() {}

void Bullet::Create(int l_playerid, sf::Vector2f l_tankposition, sf::Vector2f direction)
{
    m_inmotion = true;
    if (l_playerid == 1)
    {
        bulletshape.setFillColor(sf::Color::Red);
    }
    if (l_playerid == 2)
    {
        bulletshape.setFillColor(sf::Color::Blue);
    }
    if (l_playerid == 3)
    {
        bulletshape.setFillColor(sf::Color::Green);
    }
    if (l_playerid == 4)
    {
        bulletshape.setFillColor(sf::Color::Magenta);
    }
    m_direction = direction;
    m_tankposition = l_tankposition;
    bulletshape.setPosition(m_tankposition);
}

void Bullet::setPosition(sf::Vector2f initial_position)
{
    bulletshape.setPosition(initial_position);
}

void Bullet::setDirection(float x_direction, float y_direction)
{
    m_direction.x = x_direction;
    m_direction.y = y_direction;
}


void Bullet::Destroy()
{
    m_used = true;
    m_inmotion = false;
}

void Bullet::Move()
{
    if (m_inmotion == true)
    {
        bulletshape.move(m_direction.x*bulletspeed, m_direction.y*bulletspeed);
    }
}

sf::Vector2f Bullet::getposition()
{
    return bulletshape.getPosition();
}

sf::Vector2f Bullet::getdirection()
{
    return m_direction;
}

void Bullet::Render(sf::RenderWindow &l_window)
{
    l_window.draw(bulletshape);
}

bool Bullet::checkinMotion() { return m_inmotion; }

bool Bullet::checkUsed() { return m_used; }

sf::FloatRect Bullet::getBounds()
{
    return bulletshape.getGlobalBounds();
}