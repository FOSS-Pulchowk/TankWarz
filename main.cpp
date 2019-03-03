#include "client.h"
#include "server.h"
#include "game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iomanip>
#include "menu.h"

using namespace std;

int main()
{
MAINMENU:
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tanks War"); //main menu window
    window.setFramerateLimit(60);

    Menu menuText(window.getSize().x, window.getSize().y);

    sf::Texture texture;
    texture.loadFromFile("images/mainmenu1.png"); //background image for main menu
    sf::Sprite sprite(texture);

    static sf::Music backgroundMusic; //plays background music
    if (!backgroundMusic.openFromFile("sounds/gamemusic.wav"))
    {
        return -1;
    }
    backgroundMusic.play();
    backgroundMusic.setVolume(100);
    backgroundMusic.setLoop(true);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                    menuText.moveUp();

                if (event.key.code == sf::Keyboard::W)
                    menuText.moveUp();

                if (event.key.code == sf::Keyboard::Down)
                    menuText.moveDown();

                if (event.key.code == sf::Keyboard::S)
                    menuText.moveDown();

                if (event.key.code == sf::Keyboard::Return)
                {
                    if (menuText.getPressedItem() == 0)
                    {
                        cout << "Play button has been pressed." << endl;
                        window.close();
                    PLAYMENU:
                        Game game(4, 1);

                        while (!game.GetWindow()->IsDone())
                        {
                            game.HandleTankMovements();
                            game.CheckDamage();
                            game.Update();

                            game.Render();
                            game.CheckWinner();
                        }
                        if(game.GetWindow()->IsDone())
                        {
                            goto MAINMENU;
                        }
                    }
                    

                    if (menuText.getPressedItem() == 1)
                    {
                        cout << "Instructions button has been pressed." << endl;
                        window.close();

                        sf::RenderWindow instructionWindow(sf::VideoMode(1280, 720), "About Game"); //window for providing description of games

                        sf::Texture instructionTexture;
                        instructionTexture.loadFromFile("images/instructions.png"); //text image for explanation of game
                        sf::Sprite instructionSprite(instructionTexture);

                        while (instructionWindow.isOpen())
                        {
                            sf::Event aboutWindowEvent;
                            while (instructionWindow.pollEvent(aboutWindowEvent))
                            {
                                if (aboutWindowEvent.type == sf::Event::Closed)
                                    goto MAINMENU;
                            }

                            instructionWindow.clear();
                            instructionWindow.draw(instructionSprite);
                            instructionWindow.display();
                        }
                    }

                    if (menuText.getPressedItem() == 2)
                    {
                        cout << "Host a Game button has been pressed." << endl;
                        window.close();
                    HOSTEMENU:

                        Server s;
                        std::cout << "Local Ip Address: " << sf::IpAddress::getLocalAddress() << endl;
                        std::cout << "Global Ip Address: " << sf::IpAddress::getPublicAddress() << endl;
                        int players;
                        std::cout << "Enter the no of players: ";
                        std::cin >> players;
                        s.setPlayers(players);

                        Client c(sf::IpAddress::getLocalAddress());
                        s.ReceiveConnection();
                        c.ReceiveConfirmation();

                        for (int i = 0; i < players - 1; i++)
                        {
                            s.ReceiveConnection();
                        }

                        s.SendPlaySignal();

                        while (!c.ReadyToPlay())
                        {
                            c.PlaySignal();
                        }

                        std::cout << "---------------------------------------------------------" << endl;
                        std::cout << "|                   GAME STARTS NOW                     |" << endl;
                        std::cout << "---------------------------------------------------------" << endl;

                        s.Thread();

                        int totalplayers = c.getTotalPlayer();
                        int playerid = c.getPlayerId();

                        Game game(totalplayers, playerid + 1);

                        c.Thread();

                        while (!game.GetWindow()->IsDone())
                        {
                            for (int i = 0; i < totalplayers; i++)
                            {
                                if (i == playerid)
                                {
                                    continue;
                                }
                                game.setOtherPlayers(i, c.getTankPosition(i), c.getTankDirection(i), c.getTankHealth(i), c.SendBulletNotoState(i), c.getBulletDirection(i));
                            }

                            game.HandleTankMovements();
                            game.CheckDamage();
                            game.Update();

                            c.Send(game.getState());
                            game.CheckWinner();

                            game.Render();
                        }
                    }
                    //Make for other players
                    if (menuText.getPressedItem() == 3)
                    {
                        cout << "Join a Game button has been pressed." << endl;
                        window.close();
                    CLIENTMENU:
                        Client c;
                        c.SendConnection();
                        c.ReceiveConfirmation();

                        while (!c.ReadyToPlay())
                        {
                            c.PlaySignal();
                        }

                        int totalplayers = c.getTotalPlayer();
                        int playerid = c.getPlayerId();

                        Game game(totalplayers, playerid + 1);

                        c.Thread();

                        while (!game.GetWindow()->IsDone())
                        {
                            for (int i = 0; i < totalplayers; i++)
                            {
                                if (i == playerid)
                                {
                                    continue;
                                }
                                game.setOtherPlayers(i, c.getTankPosition(i), c.getTankDirection(i), c.getTankHealth(i), c.SendBulletNotoState(i), c.getBulletDirection(i));
                            }

                            game.HandleTankMovements();
                            game.CheckDamage();
                            game.Update();

                            game.CheckWinner();
                            c.Send(game.getState());

                            game.Render();
                        }
                    }

                    if (menuText.getPressedItem() == 4)
                    {
                        cout << "About button has been pressed." << endl;
                        window.close();

                        sf::RenderWindow aboutWindow(sf::VideoMode(1280, 720), "About Game"); //window for providing description of games

                        sf::Texture aboutTexture;
                        aboutTexture.loadFromFile("images/about.png"); //text image for explanation of game
                        sf::Sprite aboutSprite(aboutTexture);

                        while (aboutWindow.isOpen())
                        {
                            sf::Event aboutWindowEvent;
                            while (aboutWindow.pollEvent(aboutWindowEvent))
                            {
                                if (aboutWindowEvent.type == sf::Event::Closed)
                                    goto MAINMENU;
                            }

                            aboutWindow.clear();
                            aboutWindow.draw(aboutSprite);
                            aboutWindow.display();
                        }
                    }

                    if (menuText.getPressedItem() == 5)
                        window.close();
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(sprite);

        menuText.draw(window);

        window.display();
    }
    return 0;
}