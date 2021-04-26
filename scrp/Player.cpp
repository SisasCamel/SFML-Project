#include "Player.h"
#include "stdafx.h"


// Initializes variables
void Player::initVariables(){
    this->movementSpeed = 2.5f;
    this->playerPos = playerObj.getPosition();
}

//Initializes and loads texture
void Player::initTexture(){

    if(!this->playerIdleTexture.loadFromFile("res/playerIdles.png")){
        std::cout << "Error, couldn't load \"Idle Animation\" texture\n";
    }
    if(!this->playerRunningTexture.loadFromFile("res/running.png")){
        std::cout << "Error, couldn't load \"Running Animation\" texture\n";
    }
}

// Initializes sprite and Settings
void Player::initSprite(){
    this->playerObj.scale(2.5f, 2.5f);
    this->currentFrame = sf::IntRect(0, 0, 32, 32);
    this->playerObj.setTextureRect(this->currentFrame);
    this->playerObj.setOrigin(playerPos.x + 16, playerPos.y + 16);
    this->playerObj.setPosition(400, 300);
}

void Player::initAnimations(){
    this->animationTimerIdle.restart();
    this->animationState = IDLE;
}

//Constructor and Destructor
Player::Player(){

    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initAnimations();
}

Player::~Player(){

}

void Player::updateInput(){    
    // Keyboard Input
    animationState = IDLE;
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->playerObj.move(-this->movementSpeed, 0.f);
        this->animationState = MOVING_LEFT;
    }
    //Right
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->playerObj.move(this->movementSpeed, 0.f);
        this->animationState = MOVING_RIGHT;
    }

}

void Player::updateAnimations(){
    if(this->animationState == IDLE){
        playerObj.setTexture(this->playerIdleTexture);
        currentFrame.left = 0;
        if(this->animationTimerIdle.getElapsedTime().asSeconds() >= 1.5f)
        {
            this->currentFrame.left += 32.f;
            if(this->currentFrame.left >= 128.f){
                this->currentFrame.left = 0;
            }
        }
        this->animationTimerIdle.restart();
        this->playerObj.setTextureRect(this->currentFrame);
    }
    else if(this->animationState == MOVING_RIGHT){
        playerObj.setTexture(this->playerRunningTexture);
        currentFrame.left = 0;
        if(this->animationTimerIdle.getElapsedTime().asSeconds() >= 0.5f)
        {
            this->currentFrame.left += 32.f;
            if(this->currentFrame.left >= 128.f){
                this->currentFrame.left = 0;
            }
        }
        this->animationTimerIdle.restart();
        this->playerObj.setTextureRect(this->currentFrame);
    }
}

//Updates player
void Player::update(){
    // Window bounds Collision
    
    this->updateAnimations();
    this->updateInput();
}

//Renders Player
void Player::render(sf::RenderTarget* target){
    target->draw(this->playerObj);
}