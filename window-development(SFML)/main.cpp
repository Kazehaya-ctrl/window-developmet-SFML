#include<iostream>
#include "Game.h"

int main() {

  srand(time(NULL));

  Game game;
  
  while (game.is_running()) {
    game.update();
    game.render();
  }

	return 0;
}