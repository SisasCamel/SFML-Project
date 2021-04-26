#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


enum PLAYER_ANIMATION_STATES{IDLE = 0, MOVING_LEFT = 1, MOVING_RIGHT = 2, JUMPING = 3, FALLING = 4};

class Player{
private:

    //Player GameObject
    sf::Texture playerIdleTexture;
    sf::Texture playerRunningTexture;
    sf::Sprite playerObj;

    //Animation, initialize on initAnimations()
    sf::IntRect currentFrame;
    sf::Clock animationTimerIdle;
    short animationState;

    //Private variables, make sure to initialize on initVariables()
    float movementSpeed;
    sf::Vector2f playerPos;

    //Private Functions make sure to call them on Player()
    void initVariables();
    void initSprite();
    void initTexture();
    void initAnimations();
public:
    // Constructors and Destructors
    Player();
    ~Player();


    //Functions, if updates something, call them on update()
    void updateInput();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget* target);
};