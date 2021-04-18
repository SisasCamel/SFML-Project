#include <SFML/Graphics.hpp>

int main()
{
    //settings for antialiasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //window
    sf::RenderWindow window(sf::VideoMode(250, 250), "SFML works!", sf::Style::Default, settings);

    //creates circle
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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
    }

    return 0;
}