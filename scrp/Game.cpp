#include "Game.h"


// Private Functions
void Game::initVariables(){
    this -> window = nullptr;
}
void Game::initWindow(){
    this -> videoMode.height = 600;
    this -> videoMode.width = 800;
    this -> settings.antialiasingLevel = 8;
    this -> window = new sf::RenderWindow(this->videoMode, "My Window", sf::Style::Titlebar | sf::Style::Close, settings);
}


//Constructor and destructor
Game::Game(){
    this -> initVariables();
    this -> initWindow();
}

Game::~Game(){
    delete this-> window;
}

// Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}


// Functions
void Game::pollEvents(){
    // Event Polling
    while(this->window->pollEvent(this->e)){
        switch(this->e.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->e.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
                break;
        }
    }
}

void Game::update(){
    this->pollEvents();
}

void Game::render(){
    this->window->clear(sf::Color(255, 0, 0, 255));

    // Display
    this->window->display();
}