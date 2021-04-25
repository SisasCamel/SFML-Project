#include "Game.h"


// Private Functions
void Game::initVariables(){
    this -> window = nullptr;
    this -> endGame = false;
}
void Game::initWindow(){
    this -> videoMode.height = 600;
    this -> videoMode.width = 800;
    this -> settings.antialiasingLevel = 8;
    this -> window = new sf::RenderWindow(this -> videoMode, "My Window", sf::Style::Titlebar | sf::Style::Close, settings);
    this -> window -> setFramerateLimit(120);
}
void Game::initEnemies(){

}

//Constructor and destructor
Game::Game(){
    this -> initVariables();
    this -> initWindow();
    this -> initEnemies();
}

Game::~Game(){
    delete this -> window;
}

// Accessors
const bool Game::running() const
{
    return this -> window -> isOpen();
}


// Functions
void Game::pollEvents(){
    // Event Polling
    while(this -> window -> pollEvent(this->e)){
        switch(this -> e.type){
            case sf::Event::Closed:
                this -> window -> close();
                break;
            case sf::Event::KeyPressed:
                if(this -> e.key.code == sf::Keyboard::Escape){
                    this -> window -> close();
                }
                break;
        }
    }
}

void Game::updateMousePositions(){
    // Updates Mouse Position

    // relative to screen
    // std::cout << "Mouse Pos: " << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << std::endl;

    // relative to the window
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::update(){
    this -> updateMousePositions();
    this -> pollEvents();
    this -> player.update(this->window);
}

void Game::render(){
    this -> window->clear();

    // Display
    this -> player.render(this->window);
    this -> window -> display();
}