#pragma once
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

	void initVariable();
	void initWindow();
public:
	Game();
	virtual ~Game();
	bool is_running() const;
	void event_polling();
	void update();
	void render();
};