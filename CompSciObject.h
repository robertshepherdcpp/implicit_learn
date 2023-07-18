#pragma once

#include<SFML/Graphics.hpp>

struct CompSciObject
{
	void draw(sf::RenderWindow& window);
	void update(sf::Event& event);

	void Activate();

	bool IsActivated = false;
};