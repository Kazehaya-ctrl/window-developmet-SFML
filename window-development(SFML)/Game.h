#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>


class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event event;
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	sf::Vector2i mouse;

	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	void initVariable();
	void initWindow();
	void enemyInit();

public:
	Game();
	virtual ~Game();
	bool is_running() const;
	void spawn_enemy();
	void event_polling();
	void update_enemies();
	void render_enemies();
	void update();
	void update_mouse_position();
	void render();
};