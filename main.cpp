#include "scrp/Game.cpp"
#include <iostream>

int main()
{
    // Init game engine
    Game game;
    while (game.running()){
        // Update
        game.update();
        //Render
        game.render(); 
        
        }
    return 0;
}
