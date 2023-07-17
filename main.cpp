#include<SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1001), "implicit learn");

    bool ShouldShowOpening = true;

    sf::Texture opening_background_texture;
    opening_background_texture.loadFromFile("implicit_learn.png");

    sf::Sprite opening_background_sprite;
    opening_background_sprite.setTexture(opening_background_texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (ShouldShowOpening && event.type == sf::Event::KeyPressed)
            {
                ShouldShowOpening = false;
            }
        }
    }

    window.clear();
    if (ShouldShowOpening) window.draw(opening_background_sprite);
    window.display();
}