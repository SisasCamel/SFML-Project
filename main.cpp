#include <SFML/Graphics.hpp>

int main()
{
    //settings for antialiasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;


    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Default, settings);
    sf::RectangleShape rec(sf::Vector2f(0.0f, 0.0f));
    rec.setPosition(sf::Vector2f(250.0f, 33.0f));
    rec.setSize(sf::Vector2f(200.0f, 100.0f));
    rec.setOutlineThickness(10.0f);
    rec.setOutlineColor(sf::Color(250, 13, 44));
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

        window.clear();
        window.draw(shape);
        window.draw(rec);
        window.display();
    }

    return 0;
}