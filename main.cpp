#include<SFML/Graphics.hpp>

#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1001), "implicit learn");

    bool ShouldShowOpening = true;
    bool ShouldShowOptions = false;

    sf::Texture opening_background_texture;
    opening_background_texture.loadFromFile("implicit_learn.png");

    sf::Sprite opening_background_sprite;
    opening_background_sprite.setTexture(opening_background_texture);

    sf::Texture maths_texture;
    maths_texture.loadFromFile("maths.png");
    sf::Sprite maths(maths_texture);

    sf::Texture physics_texture;
    physics_texture.loadFromFile("physics.png");
    sf::Sprite physics(physics_texture);

    sf::Texture compsci_texture;
    compsci_texture.loadFromFile("compsci.png");
    sf::Sprite compsci(compsci_texture);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (ShouldShowOpening)
            {
                if (event.type == sf::Event::KeyReleased)
                {
                    ShouldShowOpening = false;
                    ShouldShowOptions = true;
                }
            }
            else if (ShouldShowOptions)
            {
                maths.setPosition(  450,  250);
                physics.setPosition(850,  250);
                compsci.setPosition(1250, 250);

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (maths.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Maths clicked!" << std::endl;
                    }
                    if (physics.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Physics clicked!" << std::endl;
                    }
                    if (compsci.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Compsci clicked!" << std::endl;
                    }
                }
            }
        }

        window.clear();
        if (ShouldShowOpening)
        {
            window.draw(opening_background_sprite);
        }
        if (ShouldShowOptions)
        {
            window.draw(maths);
            window.draw(physics);
            window.draw(compsci);
        }
        window.display();
    }
}