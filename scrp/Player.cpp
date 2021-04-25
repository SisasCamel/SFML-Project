#include "Player.h"


// Initializes variables
void Player::initVariables(){
    this->movementSpeed = 2.5f;
}


// Initializes shape Settings
void Player::initShape(){
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(100.0f, 100.0f));
}

//Constructor and Destructor
Player::Player(float x, float y){

    this->shape.setPosition(x, y);


    this->initVariables();
    this->initShape();
}

Player::~Player(){

}

void Player::updateInput(){    
    // Keyboard Input
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->shape.move(-this->movementSpeed, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->shape.move(this->movementSpeed, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->shape.move(0.f, -this->movementSpeed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->shape.move(0.f, this->movementSpeed);
    }
}

//Updates player
void Player::update(sf::RenderTarget* target){
    // Window bounds Collision
    
    
    
    this->updateInput();
}

//Renders Player
void Player::render(sf::RenderTarget * target){
    target->draw(this->shape);
}