// FirstSFMLApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    int width = 640;
    int height = 480;
    float radius = 30.0f;

    sf::RenderWindow window(sf::VideoMode(width, height), "Hello SFML!");
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition((float)width / 2 - radius, (float)height / 2 - radius);

    window.setFramerateLimit(60);

    float speedX=1.0f, speedY=1.0f;

    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }



        circle.setPosition(circle.getPosition().x + speedX, circle.getPosition().y + speedY);

        if (circle.getPosition().x < 0 || circle.getPosition().x + 2 * radius > width) speedX *= -1;
        if (circle.getPosition().y <0 || circle.getPosition().y + 2 * radius > height) speedY *= -1;

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}


