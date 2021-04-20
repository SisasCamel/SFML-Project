#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include<windows.h>


int main()  
{
    int colora, colorb, colorc;
    int randSeed = (rand() % 100) * (int) time(0);

    srand(randSeed);
    colora = (rand() % 255);
    colorb = (rand() % 255) - 52;
    colora = (rand() % 255) - 32;
    int i = 0;
    int radius = 100;

    //settings for antialiasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    float outlineThick = 10.0f;

    //window
    sf::RenderWindow window(sf::VideoMode(250, 250), "SFML works!", sf::Style::Default, settings);

    //creates circle
    sf::CircleShape shape(125.f);
    shape.setOutlineThickness(outlineThick);
    shape.setOutlineColor(sf::Color(colora, colorb, colorc));
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(radius);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //draws and window init
        window.clear();
        window.draw(shape);
        window.display();
        i++;
        if(i%10 == 0){
            shape.setPosition(0.0f, 0.0f);
            if(i%3 == 0 && radius < 300){
                std::cout << radius << " ";
                shape.setRadius(radius++);
            }
            if(outlineThick != 35){
                shape.setOutlineThickness(outlineThick++);
            }
            shape.setOutlineColor(sf::Color(colora--, colorb, colorc));
        }
    }

    return 0;
}