#include<SFML/Graphics.hpp>

#include<iostream>

#include"MathsObject.h"
#include"PhysicsObject.h"
#include"CompSciObject.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1001), "implicit learn");

    bool ShouldShowOpening = true;
    bool ShouldShowOptions = false;

    MathsObject Maths;
    PhysicsObject Physics;
    CompSciObject CompSci;

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
                maths.setPosition(  150 , 250);
                physics.setPosition(750 , 250);
                compsci.setPosition(1350, 250);

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (maths.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Maths clicked!" << std::endl;
                        Maths.Activate();
                        ShouldShowOptions = false;
                    }
                    if (physics.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Physics clicked!" << std::endl;
                        Physics.Activate();
                        ShouldShowOptions = false;
                    }
                    if (compsci.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Compsci clicked!" << std::endl;
                        CompSci.Activate();
                        ShouldShowOptions = false;
                    }
                }
            }
            Maths.update(event);
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
        Maths.draw(window);
        window.display();
    }
}