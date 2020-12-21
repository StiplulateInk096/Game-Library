#include <iostream>
#include <vector>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#define VERSION 1
#undef main
using namespace std;
#include "global.cpp"
#include "input.cpp"
#include "framecount.cpp"
#include "init.cpp"
#include "window.cpp"
#include "objects.cpp"
#include "draw.cpp"
#include "utils.cpp"
#include "renderers.cpp"
#include "random.cpp"
#include "../main.cpp"
int main(void)
{
	init(width, height);
	srand(time(NULL));
	setFrameRate();setup();
	while (1)
	{
		frameCounter();
		SDL_GetMouseState(&mouseX, &mouseY);
		SDL_GetWindowSize(window,&width,&height);
		if (shouldQuit() == 1) break;
		background(0,0,0,255);
		loop();
		applyDraw();
	}
	close();
	return 0;
}
