#include <iostream>
#include <vector>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <thread>
#define VERSION 1
#undef main
using namespace std;
#include "perlin.c"
#include "global.cpp"
#include "framecount.cpp"
#include "init.cpp"
#include "window.cpp"
#include "objects.cpp"
#include "draw.cpp"
#include "utils.cpp"
#include "renderers.cpp"
#include "random.cpp"
void presetup(void) __attribute__((weak));
void setup(void) __attribute__((weak));
void loop(void) __attribute__((weak));
#include "../main.cpp"
int main(void)
{
	init();
	if (presetup) presetup();
	initWindow(width, height);
	srand(time(NULL));
	setFrameRate();
	setup();
	while (1)
	{
		frameCounter();
		SDL_GetMouseState(&mouseX, &mouseY);
		SDL_GetGlobalMouseState(&gMouseX, &gMouseY);
		SDL_GetWindowSize(window,&width,&height);
		if (shouldQuit() == 1) break;
		background(0,0,0,255);
		fill(255, 255, 255, 255);
		loop();
		applyDraw();
	}
	close();
	return 0;
}
