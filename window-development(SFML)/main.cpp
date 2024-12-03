#include<iostream>
#include "Game.h"

int main() {
    //creating a window
    Game game;
    //window loop
    while (game.is_running()) {
        game.event_polling();
        game.render();
    }

	return 0;
}