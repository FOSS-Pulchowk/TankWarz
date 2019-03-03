#include "tank.h"

Tank::Tank()
{
    tankshape.setSize({30, 30});
    tankshape.setOrigin(tankshape.getSize().x / 2, tankshape.getSize().y / 2);
    tankshape.setOutlineColor(sf::Color::White);
    tankshape.setOutlineThickness(3);

    gunshape.setSize({6, 27});
    gunshape.setOrigin(3, 26);
    gunshape.setFillColor(sf::Color::Black);
    gunshape.setOutlineThickness(1);
    gunshape.setOutlineColor(sf::Color::White);

    circleshape.setRadius(5);
    circleshape.setOutlineColor(sf::Color::White);
    circleshape.setOutlineThickness(2);

    healthbar.setSize({static_cast<float>(m_health) * 2, 15});
    healthbar.setFillColor(sf::Color::Cyan);
    healthbar.setOutlineColor(sf::Color::White);
    healthbar.setOutlineThickness(2);

    bgtexture.loadFromFile("images/mainbg.jpg");
    bgsprite.setTexture(bgtexture);
}

void Tank::Create(int a)
{
    m_playerid = a;
    if (a == 1)
    {
        tankshape.setPosition({50, 50});
        tankshape.setFillColor(sf::Color::Red);

        gunshape.setPosition({50, 50});
        circleshape.setPosition({45, 45});
        circleshape.setFillColor(sf::Color::Red);

        healthbar.setPosition(1030, 50 + 75);
    }
    if (a == 2)
    {
        tankshape.setPosition({700, 50});
        tankshape.setFillColor(sf::Color::Blue);

        gunshape.setPosition({700, 50});
        circleshape.setPosition({695, 45});
        circleshape.setFillColor(sf::Color::Blue);

        healthbar.setPosition(1030, 370 + 75);
    }
    if (a == 3)
    {
        tankshape.setPosition({50, 650});
        tankshape.setFillColor(sf::Color::Green);

        gunshape.setPosition({50, 650});
        circleshape.setPosition({45, 645});
        circleshape.setFillColor(sf::Color::Green);

        healthbar.setPosition({1030, 530 + 75});
    }
    if (a == 4)
    {
        tankshape.setPosition({470, 470});
        tankshape.setFillColor(sf::Color::Magenta);

        gunshape.setPosition({470, 470});
        circleshape.setPosition({465, 465});
        circleshape.setFillColor(sf::Color::Magenta);

        healthbar.setPosition({1030, 210 + 75});
    }
}

void Tank::Destroy() { m_destroyed = true; }

void Tank::Movement(int a)
{
    if (a == 1) //Move Left
    {
        tankshape.move(-1 * tankspeed, 0);
        circleshape.move(-1 * tankspeed, 0);
        gunshape.move(-1 * tankspeed, 0);
    }
    else if (a == 2) //Move Right
    {
        tankshape.move(1 * tankspeed, 0);
        circleshape.move(1 * tankspeed, 0);
        gunshape.move(1 * tankspeed, 0);
    }
    else if (a == 3) //Move Up
    {
        tankshape.move(0, -1 * tankspeed);
        gunshape.move(0, -1 * tankspeed);
        circleshape.move(0, -1 * tankspeed);
    }
    else if (a == 4) //Move down
    {
        tankshape.move(0, 1 * tankspeed);
        gunshape.move(0, 1 * tankspeed);
        circleshape.move(0, 1 * tankspeed);
    }
}

void Tank::setAngle(float angle)
{
    m_angle = angle;
    gunshape.setRotation(angle);
}
void Tank::DecreaseHealth(int amount)
{
    if (m_health <= 10)
    {
        std::cout << "Tank " << m_playerid << "has been destroyed." << std::endl;
        Destroy();
    }
    m_health = m_health - amount;
    healthbar.setSize({static_cast<float>(m_health) * 2, 15});
}

sf::FloatRect Tank::getBounds()
{
    return tankshape.getGlobalBounds();
}

unsigned int Tank::getHealth() { return m_health; }

bool Tank::checkDestroyed() { return m_destroyed; }

sf::Vector2f Tank::getPosition() { return tankshape.getPosition(); }

void Tank::setPosition(sf::Vector2f position)
{
    tankshape.setPosition(position);
    circleshape.setPosition({position.x-5, position.y-5});
    gunshape.setPosition(position);
}

void Tank::setHealth(unsigned int l_health) { m_health = l_health; }

float Tank::getAngle() { return m_angle; }

void Tank::Draw(sf::RenderWindow &l_window)
{
    l_window.draw(bgsprite);
}

void Tank::Render(sf::RenderWindow &l_window)
{
    l_window.draw(tankshape);
    l_window.draw(gunshape);
    l_window.draw(circleshape);
    l_window.draw(healthbar);
}