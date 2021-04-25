#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Player{
private:

    //Player GameObject
    sf::RectangleShape shape;

    //Private variables, make sure to initialize
    float movementSpeed;

    //Private Functions
    void initVariables();
    void initShape();
public:
    // Constructors and Destructors
    Player(float x = 0.f, float y = 0.f);
    ~Player();


    //Functions
    void updateInput();
    void update(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};