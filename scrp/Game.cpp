#include "Game.h"
#include "stdafx.h"


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

//Initializes player
void Game::initPlayer(){
    this->player = new Player();
}
void Game::initEnemies(){

}

//Constructor and destructor
Game::Game(){
    this -> initVariables();
    this -> initWindow();
    this -> initEnemies();
    this -> initPlayer();
}

Game::~Game(){
    delete this -> window;
    delete this -> player;
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

//Updates player, includes textures, etc
void Game::updatePlayer(){
    this->player->update();
}

void Game::update(){
    this -> updateMousePositions();
    this -> pollEvents();
    this -> updatePlayer();
}

//renders the player, we don't need to type "this->player->render(this->window);" everytime
void Game::renderPlayer(){
    this->player->render(this->window);
}

void Game::render(){
    this -> window->clear();

    //calls renderplayer
    this->renderPlayer();
    // Display
    this -> window -> display();
}
const sf::RenderWindow& Game::getWindow() const
{
    return *this->window;
}