#pragma once
#include <iostream>
#include "../../SDL2-2.0.16/include/SDL_video.h"
#include <SDL.h>

class Game
{
public:
	Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};