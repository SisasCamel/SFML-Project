#include "scrp/Game.cpp"

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
