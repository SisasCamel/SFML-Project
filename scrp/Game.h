#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

// Acts as the game engine

class Game
{
private:
    //Variables

    // Window 
    sf::ContextSettings settings;
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event e;
    //Private Functions
    void initVariables();
    void initWindow();


public:
    // Constructor / Destructor
    Game();
    ~Game();

    //Accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();

};


