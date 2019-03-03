#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sprite
{
    public:
    Sprite();
    ~Sprite();
    void Create(int);
    void Render(sf::RenderWindow&);
    void setPosition(sf::Vector2f);
    sf::Texture getTexture();
    sf::Vector2f getPosition();
    sf::Sprite getSprite();

    private:
    sf::Vector2f m_position;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};