#include "Game.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.1415926535

Game::Game() : m_window("Game Window", sf::Vector2u(500, 600)) {}

Game::Game(int l_totalplayers, int playerid) : m_window("Game Window", sf::Vector2u(1280, 720))
{
    m_totalplayers = l_totalplayers;
    m_playerid = playerid - 1;
    for (int i = 0; i < l_totalplayers; i++)
    {
        tanks[i].Create(i + 1);
        sprites[i].Create(i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        BulletCounter[i] = 0;
    }
    for (int i = 0; i < 1000; i++)
    {
        BulletCollision[i] = 0;
    }
    m_map.Create();
    if (!bulletshotbuffer.loadFromFile("sounds/bulletshot.flac"))
    {
        std::cout << "Cannot load bulletshot." << std::endl;
    }
    bulletshotsound.setBuffer(bulletshotbuffer);

    if (!collisionsoundbuffer.loadFromFile("sounds/collisionsound.wav"))
    {
        std::cout << "Cannot load collisionsound." << std::endl;
    }
    bulletshotsound.setBuffer(hitsoundbuffer);

    if (!hitsoundbuffer.loadFromFile("sounds/hitsound.wav"))
    {
        std::cout << "Cannot load hit sound." << std::endl;
    }
    hitsound.setBuffer(hitsoundbuffer);
}

Game::~Game() {}

Window *Game::GetWindow() { return &m_window; }

void Game::HandleTankMovements()
{
    if (tanks[m_playerid].checkDestroyed())
    {
        return;
    }
    if (m_window.Active())
    {
        sf::Vector2f curPos = tanks[m_playerid].getPosition();
        sf::Vector2i position = sf::Mouse::getPosition(*m_window.GetRenderWindow());

        float dx = curPos.x - position.x;
        float dy = curPos.y - position.y;

        float rotation = (atan2(dy, dx)) * 180 / PI;

        tanks[m_playerid].setAngle(rotation - 90);
    }
    if (m_window.Active() && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //Move Right
    {
        tanks[m_playerid].Movement(2);
        CheckCollision();
        if (CheckCollision(tanks[m_playerid], m_map))
            ;
        if (m_Collision)
        {
            tanks[m_playerid].Movement(1);
        }
    }
    if (m_window.Active() && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //Move left
    {
        tanks[m_playerid].Movement(1);
        CheckCollision();
        if (CheckCollision(tanks[m_playerid], m_map))
            ;
        if (m_Collision)
        {
            tanks[m_playerid].Movement(2);
        }
    }
    if (m_window.Active() && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        tanks[m_playerid].Movement(3);
        CheckCollision();
        if (CheckCollision(tanks[m_playerid], m_map))
            ;
        if (m_Collision)
        {
            tanks[m_playerid].Movement(4);
        }
    }
    if (m_window.Active() && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        tanks[m_playerid].Movement(4);
        CheckCollision();
        if (CheckCollision(tanks[m_playerid], m_map))
            ;
        if (m_Collision)
        {
            tanks[m_playerid].Movement(3);
        }
    }
    if (m_window.Active() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        float slope, x, y, denominator, x_normalize, y_normalize;
        if (count % 10 == 0)
        {
            slope = GetSlope(tanks[m_playerid].getPosition().x, tanks[m_playerid].getPosition().y, sf::Mouse::getPosition(*m_window.GetRenderWindow()).x, sf::Mouse::getPosition(*m_window.GetRenderWindow()).y);
            if ((sf::Mouse::getPosition(*m_window.GetRenderWindow()).x - tanks[m_playerid].getPosition().x) > 0)
            {
                x = 1;
            }
            else
            {
                x = -1;
            }

            y = slope * x;
            denominator = sqrt(pow(x, 2) + pow(y, 2));
            x_normalize = x / denominator;
            y_normalize = y / denominator;

            if (BulletCounter[m_playerid] < 100)
            {
                bullets[m_playerid * 100 + BulletCounter[m_playerid]].Create(m_playerid + 1, {tanks[m_playerid].getPosition().x + x_normalize * 40, tanks[m_playerid].getPosition().y + y_normalize * 40}, {x_normalize, y_normalize});
                bulletshotsound.play();
                BulletCounter[m_playerid]++;
            }
            else if (BulletCounter[m_playerid] >= 100)
            {
                std::cout << "Bullet limit reached. " << std::endl;
            }

            count = 0;
        }
        count++;
    }
}

void Game::Update()
{
    m_window.Update();
    for (int j = 0; j < m_totalplayers; j++)
    {
        for (int i = 0; i <= BulletCounter[j]; i++)
        {

            unsigned int index = j * 100 + i;
            if (BulletCollision[index] >= m_maxCollision)
            {
                bullets[index].Destroy();
            }

            CheckCollision(bullets[index], index, m_map);
            bullets[index].Move();
        }
    }
    if (tanks[m_playerid].checkDestroyed())
    {
        // m_window.Destroy();

        if (!gameover)
        {
            gameover = true;
            sf::RenderWindow gameOverWindow(sf::VideoMode(1280, 720), "Game Over Window"); //window for game over
            sf::Texture lostTexture;
            lostTexture.loadFromFile("images/lostwindow.png"); //text image for explanation of game
            sf::Sprite lostSprite(lostTexture);

            while (gameOverWindow.isOpen())
            {
                sf::Event aboutWindowEvent;
                while (gameOverWindow.pollEvent(aboutWindowEvent))
                {
                    if (aboutWindowEvent.type == sf::Event::Closed)
                    {
                        gameOverWindow.close();
                    }
                }
                gameOverWindow.clear();
                gameOverWindow.draw(lostSprite);
                gameOverWindow.display();
            }
        }
    }
}

float Game::GetDistance(float a, float b)
{
    if (a - b > 0)
    {
        return (a - b);
    }
    else
    {
        return (b - a);
    }
}

bool Game::CheckCollision(Tank l_tank, Map1 l_map)
{
    for (int i = 0; i < 10; i++)
    {
        if (l_tank.getBounds().intersects(l_map.getHBounds(i)))
        {
            m_Collision = true;
            collisionsound.play();
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (l_tank.getBounds().intersects(l_map.getVBounds(i)))
        {
            m_Collision = true;
            collisionsound.play();
        }
    }
}

bool Game::CheckCollision(Bullet &l_bullet, unsigned int l_index, Map1 l_map)
{
    for (int i = 0; i < 10; i++)
    {
        if (l_bullet.getBounds().intersects(l_map.getHBounds(i)))
        {
            BulletCollision[l_index]++;
            l_bullet.setDirection(l_bullet.getdirection().x, -l_bullet.getdirection().y);
            collisionsound.play();
        }
    }
    for (int j = 0; j < 11; j++)
    {
        if (l_bullet.getBounds().intersects(l_map.getVBounds(j)))
        {
            BulletCollision[l_index]++;
            l_bullet.setDirection(-l_bullet.getdirection().x, l_bullet.getdirection().y);
            collisionsound.play();
        }
    }
}
void Game::CheckCollision()
{
    for (int i = 0; i < m_totalplayers; i++)
    {
        if (tanks[i].checkDestroyed())
        {
            continue;
        }
        if (i != m_playerid && GetDistance(tanks[m_playerid].getPosition().x, tanks[i].getPosition().x) <= 30 && GetDistance(tanks[m_playerid].getPosition().y, tanks[i].getPosition().y) <= 30)
        {
            m_Collision = true;
            collisionsound.play();
            break;
        }
        else
        {
            m_Collision = false;
        }
    }
}

void Game::setOtherPlayers(int playerid, sf::Vector2f tankposition, float rotation, unsigned int health, int bulletno, sf::Vector2f bulletdirection)
{
    tanks[playerid].setPosition(tankposition);
    tanks[playerid].setAngle(rotation);
    tanks[playerid].setHealth(health);

    if (bulletno > BulletCounter[playerid])
    {
        bullets[playerid * 100 + bulletno].Create(playerid + 1, {tanks[playerid].getPosition().x + 40 * bulletdirection.x, tanks[playerid].getPosition().y + 40 * bulletdirection.y}, bulletdirection);
        BulletCounter[playerid] = bulletno;
    }
}
void Game::CheckDamage()
{
    float x_difference, y_difference;
    for (int j = 0; j < m_totalplayers; j++)
    {
        if (tanks[j].checkDestroyed())
        {
            continue;
        }
        for (int k = 0; k < m_totalplayers; k++)
        {
            for (int i = k * 100; i <= k * 100 + BulletCounter[k]; i++)
            {
                // if (i / 100 == j)
                // {
                //     continue;
                // }
                if (!bullets[i].checkinMotion())
                {
                    continue;
                }
                if (bullets[i].getposition().x < -10 || bullets[i].getposition().y < -10 || bullets[i].getposition().x > 1300 || bullets[i].getposition().y > 1300)
                {
                    std::cout << "Bullet: " << std::setw(3) << i << "has been destroyed by out of bounds." << std::endl;
                    bullets[i].Destroy();
                }
                x_difference = GetDistance(tanks[j].getPosition().x, bullets[i].getposition().x);
                y_difference = GetDistance(tanks[j].getPosition().y, bullets[i].getposition().y);

                if (x_difference < 25 && y_difference < 25)
                {
                    bullets[i].Destroy();
                    hitsound.play();
                    tanks[j].DecreaseHealth(10);
                }
            }
        }
    }
}

float Game::GetSlope(float x1, float y1, float x2, float y2)
{
    return ((y2 - y1) / (x2 - x1));
}

void Game::Render()
{
    m_window.BeginDraw();
    tanks[m_playerid].Draw(*m_window.GetRenderWindow());

    for (int i = 0; i < m_totalplayers; i++)
    {
        if (tanks[i].checkDestroyed() == true)
        {
            continue;
        }
        tanks[i].Render(*m_window.GetRenderWindow());
        sprites[i].Render(*m_window.GetRenderWindow());
    }

    for (int j = 0; j < m_totalplayers; j++)
    {
        for (int i = 0; i <= BulletCounter[j]; i++)
        {
            if (!bullets[j * 100 + i].checkinMotion())
            {
                continue;
            }
            bullets[j * 100 + i].Render(*m_window.GetRenderWindow());
        }
    }

    m_map.map1BlockDraw(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

sf::Packet Game::getState()
{
    sf::Packet packet;
    float xtank = tanks[m_playerid].getPosition().x;
    float ytank = tanks[m_playerid].getPosition().y;
    float angle = tanks[m_playerid].getAngle();
    unsigned int health = tanks[m_playerid].getHealth();
    int bulletno = BulletCounter[m_playerid];
    int bulletindex = m_playerid * 100 + bulletno - 1;
    float xdir = bullets[bulletindex].getdirection().x;
    float ydir = bullets[bulletindex].getdirection().y;

    packet << m_playerid << xtank << ytank << angle << health << bulletno << xdir << ydir;
    return packet;
}

void Game::CheckWinner()
{
    for (int i = 0; i < m_totalplayers; i++)
    {
        if (i!=m_playerid && tanks[i].checkDestroyed() == false)
        {
            return;
        }
    }

    m_window.Destroy();

    sf::RenderWindow winnerWindow(sf::VideoMode(1280, 720), "Winner Window"); //window for game over
    sf::Texture wonTexture;
    wonTexture.loadFromFile("images/winnerwindow.png"); //text image for explanation of game
    sf::Sprite wonSprite(wonTexture);

    while (winnerWindow.isOpen())
    {
        sf::Event aboutWindowEvent;
        while (winnerWindow.pollEvent(aboutWindowEvent))
        {
            if (aboutWindowEvent.type == sf::Event::Closed)
            {
                winnerWindow.close();
            }
        }
        winnerWindow.clear();
        winnerWindow.draw(wonSprite);
        winnerWindow.display();
    }
}