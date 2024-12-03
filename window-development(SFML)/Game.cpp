#include "Game.h"

void Game::initVariable()
{
	this->window = nullptr;

	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
}

void Game::initWindow()
{
	this->video_mode.height = 800;
	this->video_mode.width = 800;
  this->window = new sf::RenderWindow(this->video_mode, "Game 1", sf::Style::Default);

	this->window->setFramerateLimit(60);
}

void Game::enemyInit () {
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setOutlineThickness(1.f);
	this->enemy.setOutlineColor(sf::Color::Black);
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setPosition(10.f, 10.f);
}	

Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->enemyInit();
}

Game::~Game()
{
	delete this->window;
}

bool Game::is_running() const
{
  return this->window->isOpen();
}

void Game::spawn_enemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>((this->window->getSize().x - this->enemy.getSize().x))),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Red);

	this->enemies.push_back(enemy);
}

void Game::event_polling () {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::update_enemies()
{
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			this->spawn_enemy();
			this->enemySpawnTimer = 0.f;
		}
		else {
			this->enemySpawnTimer += 1.f;
		}
	}	

	for (auto& a : this->enemies) {
		a.move(0.f, 1.f);
	}
}

void Game::render_enemies()
{
	for (auto& a : this->enemies) {
		this->window->draw(a);
	}
}

void Game::update()
{	
	this->event_polling();
	this->update_mouse_position();
	this->update_enemies();
}

void Game::update_mouse_position ()
{
	this->mouse = sf::Mouse::getPosition(*this->window);
}

void Game::render()
{
  this->window->clear();
	this->render_enemies();
  this->window->display();
}
