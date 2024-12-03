#include "Game.h"

void Game::initVariable()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->video_mode.height = 800;
	this->video_mode.width = 800;
    this->window = new sf::RenderWindow(this->video_mode, "Game 1", sf::Style::Default);
}

Game::Game()
{
	this->initVariable();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

bool Game::is_running() const
{
    return this->window->isOpen();
}

void Game::event_polling() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (this->event.key.code == sf::Keyboard::Escape) {
			this->window->close();
		}
	}
}

void Game::update()
{	
   
}

void Game::render()
{
    this->window->clear(sf::Color(255, 0, 0, 255));

    this->window->display();
}
