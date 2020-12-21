int init(int w, int h) {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
		"unnamed game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w,
		h,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
	);
	renderer = SDL_CreateRenderer(
		window,
		0,
		0
	);
    return 0;
}
